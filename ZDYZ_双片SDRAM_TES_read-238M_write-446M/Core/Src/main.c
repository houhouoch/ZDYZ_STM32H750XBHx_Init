/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "fdcan.h"
#include "quadspi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MPU_Config(void);
/* USER CODE BEGIN PFP */
typedef struct {
    uint32_t size;
    uint32_t sum;
    char fileName[128];
} FirmwareInfo_Def;

const FirmwareInfo_Def *firmwareInfo = 0;
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define SDRAM_BANK_ADDR      (0xC0000000UL)
#define SDRAM_CAPACITY_BYTES (64 * 1024 * 1024) 
#define SDRAM_TOTAL_WORDS (64 * 1024 * 1024 / 4) //  64MB容量 / 每个uint32_t占用4字节 = 16M个测试单元

/**
 * @brief  SDRAM 完整性与容量校验
 * @note   每间隔 16KB 写入一个增量值并回读，确保地址线无短路、无回环
 */
void SDRAM_Capacity_Test(void)
{
    uint32_t i;
    uint32_t temp = 0;
    uint32_t sval = 0;      
    
    printf("--- SDRAM 64MB Integrity Test Start ---\r\n");

    /* 阶段 1: 写入测试数据 */
    for (i = 0; i < SDRAM_CAPACITY_BYTES; i += (16 * 1024))
    {
        *(volatile uint32_t *)(SDRAM_BANK_ADDR + i) = temp++;
    }
    
    /* 阶段 2: 回读并校验 */
    temp = 0;
    for (i = 0; i < SDRAM_CAPACITY_BYTES; i += (16 * 1024))
    {
        temp = *(volatile uint32_t *)(SDRAM_BANK_ADDR + i);
        
        // 校验逻辑：读取的值必须是递增的且符合写入顺序
        if ((i > 0) && (temp <= sval))
        {
            printf("❌ Error at Address: 0x%08X! Expected higher than %u, got %u\r\n", 
                   (unsigned int)(SDRAM_BANK_ADDR + i), (unsigned int)sval, (unsigned int)temp);
            return;
        }
        sval = temp;
        
        if (i % (1024 * 1024) == 0) // 每兆字节打印进度
        {
             printf("Checked: %d MB...\r", (int)(i / (1024 * 1024)));
        }
    }
    printf("\r\n✅ SDRAM 64MB Capacity Verified Successfully!\r\n");
}
/**
 * @brief  利用 TIM2 获取系统时间（微秒级）
 */
uint32_t Get_System_Time(uint8_t State)
{
    uint32_t GetTick = 0;
    
    if (State == 1)
    {
        __HAL_TIM_SET_COUNTER(&htim2, 0);
        HAL_TIM_Base_Start(&htim2);
    }
    else if (State == 2)
    {
        HAL_TIM_Base_Stop(&htim2);
        GetTick = __HAL_TIM_GET_COUNTER(&htim2);
        return GetTick;
    }
    return 0;
}


/**
 * @brief  极致性能写入测试
 * @note   使用 TIM2 进行微秒级计时，需配合开启 D-Cache 以获得最高速度
 */
void SDRAM_WriteSpeed_Optimized(void)
{
    uint32_t i, elapsed;
    volatile uint32_t *pBuf = (uint32_t *)SDRAM_BANK_ADDR;

    printf("--- SDRAM 64MB Write Speed Test (32-bit Optimized) ---\r\n");
    
    Get_System_Time(1); // 启动计时器 (如 TIM2)
    
    /* 8路循环展开：减少指令跳转频率，充分利用 H7 AXI 总线带宽 */
    for (i = 0; i < SDRAM_TOTAL_WORDS; i += 8)
    {
        pBuf[i+0] = 0xABCDEF12; pBuf[i+1] = 0xBBBBBBBB;
        pBuf[i+2] = 0xCCCCCCCC; pBuf[i+3] = 0xDDDDDDDD;
        pBuf[i+4] = 0xEEEEEEEE; pBuf[i+5] = 0xFFFFFFFF;
        pBuf[i+6] = 0x11111111; pBuf[i+7] = 0x22222222;
    }
    
    elapsed = Get_System_Time(2); // 获取耗时 (us)
    
    if (elapsed > 0)
    {
        float speed = (64.0f * 1000000.0f) / (float)elapsed;
        printf("Result -> Write Speed: %.2f MB/s | Time: %.3f s\r\n", 
               speed, (float)elapsed/1000000.0f);
    }
}
/**
 * @brief  极致性能读取测试
 * @note   利用 volatile 确保读取操作不被编译器优化掉
 */
void SDRAM_ReadSpeed_Optimized(void)
{
    uint32_t i, elapsed;
    volatile uint32_t *pBuf = (uint32_t *)SDRAM_BANK_ADDR;
    volatile uint32_t temp; // 必须使用 volatile

    printf("--- SDRAM 64MB Read Speed Test (32-bit Optimized) ---\r\n");
    
    Get_System_Time(1);
    
    /* 8路循环展开读取 */
    for (i = 0; i < SDRAM_TOTAL_WORDS; i += 8)
    {
        temp = pBuf[i+0]; temp = pBuf[i+1];
        temp = pBuf[i+2]; temp = pBuf[i+3];
        temp = pBuf[i+4]; temp = pBuf[i+5];
        temp = pBuf[i+6]; temp = pBuf[i+7];
    }
    (void)temp; // 处理未使用的变量，防止警告
    
    elapsed = Get_System_Time(2);
    
    if (elapsed > 0)
    {
        float speed = (64.0f * 1000000.0f) / (float)elapsed;
        printf("Result -> Read Speed: %.2f MB/s | Time: %.3f s\r\n", 
               speed, (float)elapsed/1000000.0f);
    }
}

//FIFO干扰实验
void SDRAM_FIFO_Comparison_Test(void)
{
    uint32_t elapsed_no_fifo, elapsed_with_fifo;
    
    printf("\r\n--- SDRAM FIFO Benefits Test (with 100KHz Interrupt) ---\r\n");

    // 1. 开启高频中断干扰
    HAL_TIM_Base_Start_IT(&htim3);

    // --- 阶段 A: 关闭 FIFO 测试 ---
    FMC_Bank1_R->BTCR[0] |= FMC_BCR1_WFDIS; // 禁止 FIFO
    Get_System_Time(1);
    SDRAM_WriteSpeed_Optimized(); // 调用你之前的 64MB 写入函数
    elapsed_no_fifo = Get_System_Time(2);
    printf("Result WITHOUT FIFO: %d MB/s\r\n", 64 * 1000000 / elapsed_no_fifo);

    HAL_Delay(500); // 歇一会儿

    // --- 阶段 B: 开启 FIFO 测试 ---
    FMC_Bank1_R->BTCR[0] &= ~FMC_BCR1_WFDIS; // 开启 FIFO
    Get_System_Time(1);
    SDRAM_WriteSpeed_Optimized();
    elapsed_with_fifo = Get_System_Time(2);
    printf("Result WITH FIFO:    %d MB/s\r\n", 64 * 1000000 / elapsed_with_fifo);

    // 关闭干扰
    HAL_TIM_Base_Stop_IT(&htim3);

    // 计算提升比例
    float improvement = (float)(elapsed_no_fifo - elapsed_with_fifo) / elapsed_no_fifo * 100.0f;
    printf("Performance Buffer Improvement: %.2f%%\r\n", improvement);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
   __disable_irq();
   SCB->VTOR = 0x90002000;
    SCB_DisableDCache();
    SCB_DisableICache();
    SCB_InvalidateICache();
    SCB_InvalidateDCache();
    __enable_irq();
    firmwareInfo = (FirmwareInfo_Def *)(0x90000000 + 0x400000ul);
    mpu_memory_protection();
  /* USER CODE END 1 */

  /* MPU Configuration--------------------------------------------------------*/
//  MPU_Config();

  /* Enable the CPU Cache */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
  //MX_QUADSPI_Init();
  MX_FDCAN1_Init();
  MX_FMC_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
   led_init();
    LED0(0);   
   printf("test start \r\n");
   printf("test start  -->CAN\r\n");
   //printf SCPI-message
   SCPI_Config_Init();

    FDCAN_FilterTypeDef sFilterConfig;
    sFilterConfig.IdType = FDCAN_STANDARD_ID;      /* ������׼֡ */
    sFilterConfig.FilterIndex = 0;                 /* ʹ�� 0 �Ź����� */
    sFilterConfig.FilterType = FDCAN_FILTER_MASK;  /* ����ģʽ����õ�ģʽ */
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0; /* �յ������ FIFO 0 */
    sFilterConfig.FilterID1 = 0x000;               /* ���� ID1 */
    sFilterConfig.FilterID2 = 0x000;               /* ���룺��Ϊ 0 ����������б�׼֡ */

    HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig);
    HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);
   

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
      uint8_t key = key_scan(0);
        if (key == KEY0_PRES)
        {
            /* 测试SDRAM容量 */
            SDRAM_Capacity_Test();
        }
        if (key == KEY1_PRES)
        {
            /* 测试SDRAM容量 */
            SDRAM_WriteSpeed_Optimized();
        }
        if (key == KEY2_PRES)
        {
            /* 测试SDRAM容量 */
            SDRAM_ReadSpeed_Optimized();
        }
        if (key == WKUP_PRES)
        {
            /* 测试SDRAM容量 */
            SDRAM_FIFO_Comparison_Test();
        }
        
        
        LED0(1);
        HAL_Delay(100);
        LED0(0);
        HAL_Delay(100);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

 /* MPU Configuration */

void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct = {0};

  /* Disables the MPU */
  HAL_MPU_Disable();

  /** Initializes and configures the Region and the memory to be protected
  */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.BaseAddress = 0x0;
  MPU_InitStruct.Size = MPU_REGION_SIZE_4GB;
  MPU_InitStruct.SubRegionDisable = 0x87;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.AccessPermission = MPU_REGION_NO_ACCESS;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /* Enables the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);

}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6)
  {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */
    if (htim->Instance == TIM3)
    {
        // 模拟一些计算开销，干扰 CPU
        static volatile uint32_t dummy_cnt;
        for(int i=0; i<50; i++) dummy_cnt++; 
    }
  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
