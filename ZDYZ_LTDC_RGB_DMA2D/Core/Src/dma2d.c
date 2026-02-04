/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    dma2d.c
  * @brief   This file provides code for the configuration
  *          of the DMA2D instances.
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
#include "dma2d.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

DMA2D_HandleTypeDef hdma2d;

/* DMA2D init function */
void MX_DMA2D_Init(void)
{

  /* USER CODE BEGIN DMA2D_Init 0 */

  /* USER CODE END DMA2D_Init 0 */

  /* USER CODE BEGIN DMA2D_Init 1 */

  /* USER CODE END DMA2D_Init 1 */
  hdma2d.Instance = DMA2D;
  hdma2d.Init.Mode = DMA2D_M2M;
  hdma2d.Init.ColorMode = DMA2D_OUTPUT_RGB565;
  hdma2d.Init.OutputOffset = 0;
  hdma2d.LayerCfg[1].InputOffset = 0;
  hdma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_RGB565;
  hdma2d.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  hdma2d.LayerCfg[1].InputAlpha = 0;
  hdma2d.LayerCfg[1].AlphaInverted = DMA2D_REGULAR_ALPHA;
  hdma2d.LayerCfg[1].RedBlueSwap = DMA2D_RB_REGULAR;
  hdma2d.LayerCfg[1].ChromaSubSampling = DMA2D_NO_CSS;
  if (HAL_DMA2D_Init(&hdma2d) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_DMA2D_ConfigLayer(&hdma2d, 1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DMA2D_Init 2 */

  /* USER CODE END DMA2D_Init 2 */

}

void HAL_DMA2D_MspInit(DMA2D_HandleTypeDef* dma2dHandle)
{

  if(dma2dHandle->Instance==DMA2D)
  {
  /* USER CODE BEGIN DMA2D_MspInit 0 */

  /* USER CODE END DMA2D_MspInit 0 */
    /* DMA2D clock enable */
    __HAL_RCC_DMA2D_CLK_ENABLE();

    /* DMA2D interrupt Init */
    HAL_NVIC_SetPriority(DMA2D_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(DMA2D_IRQn);
  /* USER CODE BEGIN DMA2D_MspInit 1 */

  /* USER CODE END DMA2D_MspInit 1 */
  }
}

void HAL_DMA2D_MspDeInit(DMA2D_HandleTypeDef* dma2dHandle)
{

  if(dma2dHandle->Instance==DMA2D)
  {
  /* USER CODE BEGIN DMA2D_MspDeInit 0 */

  /* USER CODE END DMA2D_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_DMA2D_CLK_DISABLE();

    /* DMA2D interrupt Deinit */
    HAL_NVIC_DisableIRQ(DMA2D_IRQn);
  /* USER CODE BEGIN DMA2D_MspDeInit 1 */

  /* USER CODE END DMA2D_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */


volatile uint8_t g_dma2d_done = 0;

/**
 * @brief  DMA2D 纯色填充函数 (R2M 模式)
 * @param  sx, sy: 起始坐标
 * @param  ex, ey: 结束坐标
 * @param  color:  填充的颜色 (RGB565格式)
 */
void ltdc_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint32_t color)
{
    uint32_t width  = ex - sx + 1;
    uint32_t height = ey - sy + 1;
    uint16_t offline = 800 - width; // 屏幕宽度减去填充宽度
    uint32_t addr = 0xC0000000 + 2 * (800 * sy + sx); // 目标显存地址

    /* 1. 安全检查：确保 DMA2D 当前空闲 */
    while (DMA2D->CR & DMA2D_CR_START);

    /* 2. 配置 DMA2D 为 R2M 模式 */
    DMA2D->CR = DMA2D_R2M; 

    /* 3. 设置输出颜色 */
    // 注意：在 R2M 模式下，颜色直接写到 OCOLR 寄存器
    DMA2D->OCOLR = color; 

    /* 4. 设置目标地址与偏移 */
    DMA2D->OMAR = addr;
    DMA2D->OOR  = offline;

    /* 5. 设置颜色格式 */
    DMA2D->OPFCCR = LTDC_PIXEL_FORMAT_RGB565;

    /* 6. 设置填充区域大小 */
    DMA2D->NLR = (height) | (width << 16);

    /* 7. 重置标志位并使能中断 */
    g_dma2d_done = 0; // 裸机全局标志位
    DMA2D->IFCR |= DMA2D_IFCR_CTCIF; 
    DMA2D->CR   |= DMA2D_CR_TCIE;

    /* 8. 启动填充 */
    DMA2D->CR |= DMA2D_CR_START;

    /* 9. 裸机同步等待中断唤醒 */
    while (g_dma2d_done == 0);
}




/**
 * @brief  使用 DMA2D 将颜色缓冲区数据搬运至显存指定区域
 * @param  sx, sy: 起始坐标
 * @param  ex, ey: 结束坐标
 * @param  color: 指向源颜色缓冲区（如 LVGL 的 color_p）的指针
 */
void ltdc_color_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color)
{
    uint32_t width  = ex - sx + 1;
    uint32_t height = ey - sy + 1;
    uint32_t addr   = 0xC0000000 + 2 * (800 * sy + sx); 

    /* 1. Cache 管理：确保 DMA2D 读到的是最新的内存数据 */
    SCB_CleanDCache_by_Addr((uint32_t*)color, width * height * 2);

    /* 2. 等待 DMA2D 空闲 (保险起见) */
    while (DMA2D->CR & DMA2D_CR_START);

    /* 3. 配置模式与地址 */
    DMA2D->CR      = DMA2D_M2M;                      // 存储器到存储器模式
    DMA2D->FGMAR   = (uint32_t)color;                 // 源：LVGL 缓冲区
    DMA2D->OMAR    = addr;                            // 目：SDRAM 显存
    DMA2D->FGOR    = 0;                               // 源偏移
    DMA2D->OOR     = 800 - width;                     // 目标偏移 (屏幕宽度 - 填充宽度)
    DMA2D->FGPFCCR = LTDC_PIXEL_FORMAT_RGB565;        // 输入格式
    DMA2D->OPFCCR  = LTDC_PIXEL_FORMAT_RGB565;        // 输出格式
    DMA2D->NLR     = (height) | (width << 16);        // 设置宽高

    /* 4. 开启中断并启动 */
    DMA2D->IFCR |= DMA2D_IFCR_CTCIF;                  // 先清一次标志位
    DMA2D->CR   |= DMA2D_CR_TCIE;                     // 使能传输完成中断
    DMA2D->CR   |= DMA2D_CR_START;                    // 开启搬运


    /* 5. 同步等待 */
    while (g_dma2d_done == 0);

}
/* USER CODE END 1 */
