/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#include "cmsis_os.h"
#include "./BSP/LED/led.h"
#include "./BSP/KEY/key.h"
#include "./BSP/MPU/mpu.h"
#include "scpi-def.h"
#include "./BSP/CAN/can.h"

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
//ͬ���ź�
#define SIGNAL_DMA2D_TC        (1UL << 0)  // 0x01: �������
#define SIGNAL_DMA2D_ERR       (1UL << 1)  // 0x02: ���ô���

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_BL_Pin GPIO_PIN_5
#define LCD_BL_GPIO_Port GPIOB
#define USART1_R_Pin GPIO_PIN_10
#define USART1_R_GPIO_Port GPIOA
#define USART1_U_Pin GPIO_PIN_9
#define USART1_U_GPIO_Port GPIOA
#define KEY2_Pin GPIO_PIN_13
#define KEY2_GPIO_Port GPIOC
#define TOUCH_RST_Pin GPIO_PIN_8
#define TOUCH_RST_GPIO_Port GPIOI
#define TOUCH_IIC_SDA_Pin GPIO_PIN_7
#define TOUCH_IIC_SDA_GPIO_Port GPIOG
#define KEY1_Pin GPIO_PIN_2
#define KEY1_GPIO_Port GPIOH
#define WK_UP_Pin GPIO_PIN_0
#define WK_UP_GPIO_Port GPIOA
#define KEY0_Pin GPIO_PIN_3
#define KEY0_GPIO_Port GPIOH
#define LED0_Pin GPIO_PIN_1
#define LED0_GPIO_Port GPIOB
#define TOUCH_IIC_SCL_Pin GPIO_PIN_6
#define TOUCH_IIC_SCL_GPIO_Port GPIOH
#define LED1_Pin GPIO_PIN_0
#define LED1_GPIO_Port GPIOB
#define TOUCH_INT_Pin GPIO_PIN_7
#define TOUCH_INT_GPIO_Port GPIOH

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
