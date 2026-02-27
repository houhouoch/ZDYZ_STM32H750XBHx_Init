/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    fdcan.c
  * @brief   This file provides code for the configuration
  *          of the FDCAN instances.
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
#include "fdcan.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

FDCAN_HandleTypeDef hfdcan1;

/* FDCAN1 init function */
void MX_FDCAN1_Init(void)
{

  /* USER CODE BEGIN FDCAN1_Init 0 */

  /* USER CODE END FDCAN1_Init 0 */

  /* USER CODE BEGIN FDCAN1_Init 1 */

  /* USER CODE END FDCAN1_Init 1 */
  hfdcan1.Instance = FDCAN1;
  hfdcan1.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
  hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
  hfdcan1.Init.AutoRetransmission = ENABLE;
  hfdcan1.Init.TransmitPause = DISABLE;
  hfdcan1.Init.ProtocolException = DISABLE;
  hfdcan1.Init.NominalPrescaler = 5;
  hfdcan1.Init.NominalSyncJumpWidth = 4;
  hfdcan1.Init.NominalTimeSeg1 = 15;
  hfdcan1.Init.NominalTimeSeg2 = 4;
  hfdcan1.Init.DataPrescaler = 5;
  hfdcan1.Init.DataSyncJumpWidth = 4;
  hfdcan1.Init.DataTimeSeg1 = 15;
  hfdcan1.Init.DataTimeSeg2 = 4;
  hfdcan1.Init.MessageRAMOffset = 0;
  hfdcan1.Init.StdFiltersNbr = 62;
  hfdcan1.Init.ExtFiltersNbr = 16;
  hfdcan1.Init.RxFifo0ElmtsNbr = 32;
  hfdcan1.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.RxFifo1ElmtsNbr = 32;
  hfdcan1.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.RxBuffersNbr = 8;
  hfdcan1.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
  hfdcan1.Init.TxEventsNbr = 0;
  hfdcan1.Init.TxBuffersNbr = 0;
  hfdcan1.Init.TxFifoQueueElmtsNbr = 32;
  hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  hfdcan1.Init.TxElmtSize = FDCAN_DATA_BYTES_8;
  if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FDCAN1_Init 2 */
      FDCAN_FilterTypeDef sFilterConfig;
    /* 2. 配置过滤器（接收标准ID 0x123的报文） */
  sFilterConfig.IdType = FDCAN_STANDARD_ID;
  sFilterConfig.FilterIndex = 0;
  sFilterConfig.FilterType = FDCAN_FILTER_MASK;
  sFilterConfig.FilterConfig =FDCAN_FILTER_TO_RXFIFO0;
  sFilterConfig.FilterID1 = 0x123;         // 过滤ID
  sFilterConfig.FilterID2 = 0x7FF;         // 掩码（全匹配）
  if (HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig) != HAL_OK)
  {
    Error_Handler();
  }   
      FDCAN_FilterTypeDef sExtFilterConfig;
    /* 配置扩展 ID 过滤器 */
    sExtFilterConfig.IdType = FDCAN_EXTENDED_ID;      // 注意：这里变了！
    sExtFilterConfig.FilterIndex = 0;                 // 扩展过滤器的第 0 号
    sExtFilterConfig.FilterType = FDCAN_FILTER_MASK;
    sExtFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    sExtFilterConfig.FilterID1 = 0x0000;           // 设置一个大的扩展 ID
    sExtFilterConfig.FilterID2 = 0x1FFFFFFF;          // 掩码，全匹配
    if (HAL_FDCAN_ConfigFilter(&hfdcan1, &sExtFilterConfig) != HAL_OK)
    {
        Error_Handler();
    }
  /* 3. 配置全局过滤器（未匹配的报文丢弃） */
  HAL_FDCAN_ConfigGlobalFilter(&hfdcan1, FDCAN_REJECT, FDCAN_REJECT, FDCAN_REJECT, FDCAN_REJECT);
  // 将未匹配的报文也放入 RX FIFO0，不丢弃
 // HAL_FDCAN_ConfigGlobalFilter(&hfdcan1, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_REJECT, FDCAN_REJECT);
  /* 4. 启动FDCAN */
  if (HAL_FDCAN_Start(&hfdcan1) != HAL_OK)
  {
    Error_Handler();
  }
 
  /* 5. 启用Rx FIFO0中断（可选） */
  HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);

  /* USER CODE END FDCAN1_Init 2 */

}

void HAL_FDCAN_MspInit(FDCAN_HandleTypeDef* fdcanHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(fdcanHandle->Instance==FDCAN1)
  {
  /* USER CODE BEGIN FDCAN1_MspInit 0 */

  /* USER CODE END FDCAN1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
    PeriphClkInitStruct.FdcanClockSelection = RCC_FDCANCLKSOURCE_HSE;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* FDCAN1 clock enable */
    __HAL_RCC_FDCAN_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**FDCAN1 GPIO Configuration
    PA12     ------> FDCAN1_TX
    PA11     ------> FDCAN1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* FDCAN1 interrupt Init */
    HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
    HAL_NVIC_SetPriority(FDCAN1_IT1_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(FDCAN1_IT1_IRQn);
    HAL_NVIC_SetPriority(FDCAN_CAL_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(FDCAN_CAL_IRQn);
  /* USER CODE BEGIN FDCAN1_MspInit 1 */

  /* USER CODE END FDCAN1_MspInit 1 */
  }
}

void HAL_FDCAN_MspDeInit(FDCAN_HandleTypeDef* fdcanHandle)
{

  if(fdcanHandle->Instance==FDCAN1)
  {
  /* USER CODE BEGIN FDCAN1_MspDeInit 0 */

  /* USER CODE END FDCAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_FDCAN_CLK_DISABLE();

    /**FDCAN1 GPIO Configuration
    PA12     ------> FDCAN1_TX
    PA11     ------> FDCAN1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_12|GPIO_PIN_11);

    /* FDCAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(FDCAN1_IT0_IRQn);
    HAL_NVIC_DisableIRQ(FDCAN1_IT1_IRQn);
    HAL_NVIC_DisableIRQ(FDCAN_CAL_IRQn);
  /* USER CODE BEGIN FDCAN1_MspDeInit 1 */

  /* USER CODE END FDCAN1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

#include "fdcan.h" // 确保包含了 FDCAN 的头文件

/* 发送标准ID 0x123的8字节数据 */
void FDCAN1_Send_Msg(uint8_t *data, uint8_t len)
{
  FDCAN_TxHeaderTypeDef TxHeader;
  
  /* 配置发送头 */
  TxHeader.IdType = FDCAN_STANDARD_ID;
  TxHeader.Identifier = 0x233;
  TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  TxHeader.DataLength = FDCAN_DLC_BYTES_8; // 8字节数据长度
  TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  TxHeader.BitRateSwitch = FDCAN_BRS_OFF;  // 经典CAN无波特率切换
  TxHeader.FDFormat = FDCAN_CLASSIC_CAN;   // 经典CAN格式
  TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
  TxHeader.MessageMarker = 0x00;
  
  /* 添加报文到Tx FIFO并发送 */
  if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, data) != HAL_OK)
  {
    Error_Handler();
  }
}




/**
 * @brief  通用FDCAN发送函数（支持自定义标准ID、数据、长度）
 * @param  std_id: 标准ID（0~0x7FF）
 * @param  data: 发送数据缓冲区
 * @param  len: 数据长度（1~8）
 * @retval HAL_StatusTypeDef: 发送状态
 */
HAL_StatusTypeDef FDCAN1_Send_Any_Msg(uint16_t std_id, uint8_t *data, uint8_t len)
{
  // 1. 参数校验：ID范围+数据+长度
  if (std_id > 0x7FF || data == NULL || len == 0 || len > 8)
  {
    return HAL_ERROR;
  }
  
  // 2. 临时缓冲区清零，避免垃圾值
  uint8_t tx_buf[8] = {0};
  memcpy(tx_buf, data, len);
  
  FDCAN_TxHeaderTypeDef TxHeader;
  // 配置自定义标准ID
  TxHeader.IdType = FDCAN_STANDARD_ID;
  TxHeader.Identifier = std_id;  // 动态ID
  TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  
  // 动态设置数据长度
  switch(len)
  {
    case 1: TxHeader.DataLength = FDCAN_DLC_BYTES_1; break;
    case 2: TxHeader.DataLength = FDCAN_DLC_BYTES_2; break;
    case 3: TxHeader.DataLength = FDCAN_DLC_BYTES_3; break;
    case 4: TxHeader.DataLength = FDCAN_DLC_BYTES_4; break;
    case 5: TxHeader.DataLength = FDCAN_DLC_BYTES_5; break;
    case 6: TxHeader.DataLength = FDCAN_DLC_BYTES_6; break;
    case 7: TxHeader.DataLength = FDCAN_DLC_BYTES_7; break;
    case 8: TxHeader.DataLength = FDCAN_DLC_BYTES_8; break;
    default: return HAL_ERROR;
  }
  
  TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
  TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
  TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
  TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
  TxHeader.MessageMarker = 0x00;
  
  // 发送
  return HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, tx_buf);
}











// 1. 定义接收缓存和接收头（全局/静态，避免栈溢出）
static uint8_t fdcan_rx_data[16] = {0};
static FDCAN_RxHeaderTypeDef fdcan_rx_header;
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
    // 判断是不是“收到新消息”触发的中断
    if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET)
    {
        // 从硬件 FIFO 搬运数据到内存变量中
        if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &fdcan_rx_header, fdcan_rx_data) == HAL_OK)
        {
            // 1. 直接取长度（因为你的 Raw 值显示它就是 8）
            uint8_t actual_len = (uint8_t)fdcan_rx_header.DataLength;

            // 2. 打印个报头信息
            printf("\r\n--- 发现新报文 ---");
            printf("\r\nID: 0x%X", (unsigned int)fdcan_rx_header.Identifier);
            printf("\r\n长度: %d 字节", actual_len);

            // 3. 打印具体数据：利用 for 循环，让这一行代码重复跑 actual_len 次
            printf("\r\n内容: ");
            for(uint8_t i = 0; i < actual_len; i++)
            {
                // 每次循环，i 会增加，从而打印出 fdcan_rx_data[0], [1], [2]...
                printf("%02X ", fdcan_rx_data[i]);
            }
            printf("\r\n----------------\r\n");
        }
    }
}



/************************李工代码*****************************/
void CANFD_Send_Standard(uint32_t id, uint8_t pdata[8])
{
    uint8_t can1_txbuf[8] = {0};
    memcpy(can1_txbuf, pdata, 8);
    FDCAN_TxHeaderTypeDef TxHeader1;
    TxHeader1.Identifier = id;                      // CAN ID
    TxHeader1.IdType = FDCAN_STANDARD_ID;           // 标准ID
    TxHeader1.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader1.DataLength = FDCAN_DLC_BYTES_8;       // 发送长度：8byte
    TxHeader1.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader1.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader1.FDFormat = FDCAN_CLASSIC_CAN;         // CANFD
    TxHeader1.TxEventFifoControl = FDCAN_STORE_TX_EVENTS;
    TxHeader1.MessageMarker = 0;
   // CAN_Tx_Queue_Send(&TxHeader1, can1_txbuf);
    // 真正的投递动作：调用 HAL 库原生的发送函数
    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader1, can1_txbuf) != HAL_OK)
    {
        // 如果发送失败，你可以在这里打个断点
    }
}


/*
 * @brief       void CANFD_Send_Extended(uint32_t id ,uint8_t* pdata)
 * @details     CAN发送Ext数据包(最大8字节)
                ID范围:0x000~0x1FFFFFFF(536870911)
 */
void CANFD_Send_Extended(uint32_t id, uint8_t pdata[8])
{
    uint8_t can1_txbuf[8] = {0};
    memcpy(can1_txbuf, pdata, 8);
    FDCAN_TxHeaderTypeDef TxHeader1;
    TxHeader1.Identifier = id;                      // CAN ID
    TxHeader1.IdType = FDCAN_EXTENDED_ID;           // 拓展ID
    TxHeader1.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader1.DataLength = FDCAN_DLC_BYTES_8;       // 发送长度：8byte
    TxHeader1.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader1.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader1.FDFormat = FDCAN_CLASSIC_CAN;         // CANFD
    TxHeader1.TxEventFifoControl = FDCAN_STORE_TX_EVENTS;
    TxHeader1.MessageMarker = 0;
    // 真正的投递动作：调用 HAL 库原生的发送函数
    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader1, can1_txbuf) != HAL_OK)
    {
        // 如果发送失败，你可以在这里打个断点
    }
}

void CANFD_Send_ExtRemote(uint32_t id)
{
    uint8_t can1_txbuf[8] = {0};
    FDCAN_TxHeaderTypeDef TxHeader1;
    TxHeader1.Identifier = id;                      // CAN ID
    TxHeader1.IdType = FDCAN_EXTENDED_ID;           // 拓展ID
    TxHeader1.TxFrameType = FDCAN_REMOTE_FRAME;
    TxHeader1.DataLength = FDCAN_DLC_BYTES_8;       // 发送长度：8byte
    TxHeader1.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader1.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader1.FDFormat = FDCAN_CLASSIC_CAN;         // CANFD
    TxHeader1.TxEventFifoControl = FDCAN_STORE_TX_EVENTS;
    TxHeader1.MessageMarker = 0;
    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader1, can1_txbuf) != HAL_OK)
    {
        // 如果发送失败，你可以在这里打个断点
    }
}


/* USER CODE END 1 */
