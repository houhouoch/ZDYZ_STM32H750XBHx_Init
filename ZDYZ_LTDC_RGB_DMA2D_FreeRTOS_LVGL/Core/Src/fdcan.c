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
  hfdcan1.Init.NominalPrescaler = 1;
  hfdcan1.Init.NominalSyncJumpWidth = 1;
  hfdcan1.Init.NominalTimeSeg1 = 31;
  hfdcan1.Init.NominalTimeSeg2 = 18;
  hfdcan1.Init.DataPrescaler = 1;
  hfdcan1.Init.DataSyncJumpWidth = 16;
  hfdcan1.Init.DataTimeSeg1 = 31;
  hfdcan1.Init.DataTimeSeg2 = 3;
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
    /* Start the FDCAN module */
    if(HAL_FDCAN_Start(&hfdcan1) != HAL_OK) {
    Error_Handler();
    }
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

/**
 * @brief 替代 CAN_Send_Msg 的底层发送函数
 * @param id 扩展帧 ID
 * @param data 数据指针 (8字节)
 * @param len 数据长度 (通常为 8)
 */
uint8_t DevBoard_Send_FDCAN_Msg(uint32_t id, uint8_t *data, uint32_t len)
{
    FDCAN_TxHeaderTypeDef TxHeader;

    // 1. 配置报文头
    TxHeader.Identifier = id;                         // 设置 ID
    TxHeader.IdType = FDCAN_EXTENDED_ID;               // 必须是扩展帧
    TxHeader.TxFrameType = FDCAN_DATA_FRAME;           // 数据帧
    TxHeader.DataLength = FDCAN_DLC_BYTES_8;           // 长度 8 字节
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader.BitRateSwitch = FDCAN_BRS_OFF;            // 关闭速率切换
    TxHeader.FDFormat = FDCAN_CLASSIC_CAN;             // 使用经典 CAN 格式 (配合主机)
    TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader.MessageMarker = 0;

    // 2. 发送报文到 FIFO
    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, data) != HAL_OK)
    {
        return 1; // 发送失败
    }
    return 0; // 发送成功
}

/* 在你的 fdcan.c 或接收处理文件中编写 */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
    FDCAN_RxHeaderTypeDef RxHeader;
    uint8_t RxData[8];

    if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != 0)
    {
        HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData);


    }
}

void CAN_Test_Send(void)
{
    FDCAN_TxHeaderTypeDef TxHeader;
    uint8_t TxData[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

    /* ���÷��Ϳ��Ʋ��� */
    TxHeader.Identifier = 0x123;                  /* ��׼ ID��11λ����Χ 0~0x7FF */
    TxHeader.IdType = FDCAN_STANDARD_ID;          /* ��ȷ����Ӳ�������Ǳ�׼֡ */
    TxHeader.TxFrameType = FDCAN_DATA_FRAME;      /* ֡���ͣ�����֡������Զ��֡�� */
    TxHeader.DataLength = FDCAN_DLC_BYTES_8;      /* ���ݳ��ȣ�8 �ֽ� */
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader.BitRateSwitch = FDCAN_BRS_OFF;       /* ���л����ʣ����� CAN ģʽ�� */
    TxHeader.FDFormat = FDCAN_CLASSIC_CAN;        /* ��ʽ������ CAN */
    TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader.MessageMarker = 0;

    /* ����Ϣѹ�뷢�� FIFO ���� */
    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData) != HAL_OK)
    {
        printf("CAN failure \r\n");/* ����ʧ�ܣ�ͨ�����������߷�æ��Ӳ���������� */
    }
}
/* USER CODE END 1 */
