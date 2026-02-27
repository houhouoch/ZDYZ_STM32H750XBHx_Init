/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    fdcan.h
  * @brief   This file contains all the function prototypes for
  *          the fdcan.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FDCAN_H__
#define __FDCAN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
void CAN_Test_Send(void);
/* USER CODE END Includes */

extern FDCAN_HandleTypeDef hfdcan1;

/* USER CODE BEGIN Private defines */
uint8_t DevBoard_Send_FDCAN_Msg(uint32_t id, uint8_t *data, uint32_t len);
/* USER CODE END Private defines */

void MX_FDCAN1_Init(void);

/* USER CODE BEGIN Prototypes */
void FDCAN1_Send_Msg(uint8_t *data, uint8_t len);
HAL_StatusTypeDef FDCAN1_Send_Any_Msg(uint16_t std_id, uint8_t *data, uint8_t len);
void CANFD_Send_Extended(uint32_t id, uint8_t pdata[8]);
void CANFD_Send_Standard(uint32_t id, uint8_t pdata[8]);

void CANFD_Send_ExtRemote(uint32_t id);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __FDCAN_H__ */

