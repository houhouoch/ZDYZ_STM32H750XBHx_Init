/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
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
#include "usart.h"

/* USER CODE BEGIN 0 */
#include "./BSP/LED/led.h"
/******************************************************************************************/
/* ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Â´ï¿½ï¿½ï¿½, Ö§ï¿½ï¿½printfï¿½ï¿½ï¿½ï¿½, ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ÒªÑ¡ï¿½ï¿½use MicroLIB */

#if 1
#if (__ARMCC_VERSION >= 6010050)            /* Ê¹ï¿½ï¿½AC6ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê± */
__asm(".global __use_no_semihosting\n\t");  /* ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¹ï¿½Ã°ï¿½ï¿½ï¿½ï¿½ï¿½Ä£Ê½ */
__asm(".global __ARM_use_no_argv \n\t");    /* AC6ï¿½ï¿½ï¿½ï¿½Òªï¿½ï¿½ï¿½ï¿½mainï¿½ï¿½ï¿½ï¿½Îªï¿½Ş²ï¿½ï¿½ï¿½ï¿½ï¿½Ê½ï¿½ï¿½ï¿½ï¿½ï¿½ò²¿·ï¿½ï¿½ï¿½ï¿½Ì¿ï¿½ï¿½Ü³ï¿½ï¿½Ö°ï¿½ï¿½ï¿½ï¿½ï¿½Ä£Ê½ */

#else
/* Ê¹ï¿½ï¿½AC5ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±, Òªï¿½ï¿½ï¿½ï¿½ï¿½ï¶¨ï¿½ï¿½__FILE ï¿½ï¿½ ï¿½ï¿½Ê¹ï¿½Ã°ï¿½ï¿½ï¿½ï¿½ï¿½Ä£Ê½ */
#pragma import(__use_no_semihosting)
    void _sys_exit(int x) { x = x; }
    void _ttywrch(int ch) { ch = ch; }
struct __FILE
{
    int handle;
};
FILE __stdout;
FILE __stdin;
FILE __stderr;

#endif

/* ï¿½Ø¶ï¿½ï¿½ï¿½fputcï¿½ï¿½ï¿½ï¿½, printfï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Õ»ï¿½Í¨ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½fputcï¿½ï¿½ï¿½ï¿½Ö·ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ */
int fputc(int ch, FILE *f)
{
    while ((USART1->ISR & 0X40) == 0);    /* ï¿½È´ï¿½ï¿½ï¿½Ò»ï¿½ï¿½ï¿½Ö·ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ */

    USART1->TDR = (uint8_t)ch;            /* ï¿½ï¿½Òªï¿½ï¿½ï¿½Íµï¿½ï¿½Ö·ï¿½ ch Ğ´ï¿½ëµ½DRï¿½Ä´ï¿½ï¿½ï¿½ */
    return ch;
}
#endif


#if 1     
   

uint8_t g_usart_rx_buf[USART_REC_LEN];
uint16_t g_usart_rx_sta = 0;
uint8_t g_rx_buffer[RXBUFFERSIZE];    
/* USER CODE END 0 */

UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_rx;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */
    #if USART_EN_RX  
    HAL_UARTEx_ReceiveToIdle_DMA(&huart1, g_usart_rx_buf, USART_REC_LEN);
    #endif
  /* USER CODE END USART1_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART1;
    PeriphClkInitStruct.Usart16ClockSelection = RCC_USART16CLKSOURCE_D2PCLK2;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA10     ------> USART1_RX
    PA9     ------> USART1_TX
    */
    GPIO_InitStruct.Pin = USART1_R_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(USART1_R_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = USART1_U_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(USART1_U_GPIO_Port, &GPIO_InitStruct);

    /* USART1 DMA Init */
    /* USART1_RX Init */
    hdma_usart1_rx.Instance = DMA1_Stream0;
    hdma_usart1_rx.Init.Request = DMA_REQUEST_USART1_RX;
    hdma_usart1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart1_rx.Init.Mode = DMA_NORMAL;
    hdma_usart1_rx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_usart1_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_usart1_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart1_rx);

    /* USART1 interrupt Init */
    HAL_NVIC_SetPriority(USART1_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA10     ------> USART1_RX
    PA9     ------> USART1_TX
    */
    HAL_GPIO_DeInit(GPIOA, USART1_R_Pin|USART1_U_Pin);

    /* USART1 DMA DeInit */
    HAL_DMA_DeInit(uartHandle->hdmarx);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
#include <string.h>
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if (huart->Instance == USART1)
    {
        /* 1. ¡¾ºËĞÄĞŞÕı¡¿ÔÚ¶ÁÈ¡Êı¾İÇ°£¬±ØĞë×÷·Ï¸Ã¶ÎÄÚ´æµÄ Cache */
        /* ÕâÑùÈ·±£ CPU ½ÓÏÂÀ´¶Áµ½µÄ g_usart_rx_buf ÊÇ´Ó RAM ÀïÄÃµ½µÄ×îĞÂ DMA Êı¾İ */
        SCB_InvalidateDCache_by_Addr((uint32_t*)g_usart_rx_buf, USART_REC_LEN);

        /* 2. °²È«´¦Àí£ºÊÖ¶¯Ìí¼Ó×Ö·û´®½áÊø·û */
        if(Size < USART_REC_LEN) {
            g_usart_rx_buf[Size] = '\0'; 
        } else {
            g_usart_rx_buf[USART_REC_LEN - 1] = '\0';
        }
        
        SCPI_Input(&scpi_context, (char*)g_usart_rx_buf, Size);
        
        /* 5. ÖØĞÂ¿ªÆô½ÓÊÕ */
        /* ÒòÎªÄãÊ¹ÓÃµÄÊÇ DMA_NORMAL Ä£Ê½£¬±ØĞëÊÖ¶¯ÖØÆô */
        HAL_UARTEx_ReceiveToIdle_DMA(&huart1, g_usart_rx_buf, USART_REC_LEN);
    }
}
#endif
/* USER CODE END 1 */
