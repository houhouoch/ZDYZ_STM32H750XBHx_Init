/**
 ****************************************************************************************************
 * @file        can.h
 * @brief       CAN底层驱动层头文件
 ****************************************************************************************************
 */
#ifndef __CAN_H_
#define __CAN_H_

#include "main.h"
#include "fdcan.h"
#include "cmsis_os.h"

/* --------------------------------------------------------------------------------------------------
 * [数据类型定义]
 * -------------------------------------------------------------------------------------------------- */

/**
 * @brief RTOS 传输用的报文结构体
 * @details 用于在接收中断和解析任务之间传递原始 CAN 数据
 */
typedef struct {
    uint32_t Identifier;    // 原始 ID (用于 HAL 库解析)
    uint32_t IdType;        // 标识符类型: FDCAN_STANDARD_ID 或 FDCAN_EXTENDED_ID
    uint8_t  Data[8];       // 原始数据载荷 (固定 8 字节)
    uint8_t  Len;           // 数据长度 (DLC)
} CAN_Msg_t;


/* --------------------------------------------------------------------------------------------------
 * [外部资源声明] 允许其他文件使用这些同步句柄
 * -------------------------------------------------------------------------------------------------- */
extern osMessageQueueId_t can_rx_queue_handle;
extern osMutexId_t        can_tx_mutex_handle;
extern osSemaphoreId_t    can_tx_semaphore_handle;


/* --------------------------------------------------------------------------------------------------
 * [函数接口声明]
 * -------------------------------------------------------------------------------------------------- */

/* 初始化相关 */
void CAN_Hardware_Resources_Init(void);
void CANFD_Set_RX0_Filiter(void);  // 配置扩展帧过滤器（全放行）
void CAN_Set_Std_Filter_All(void); // 配置标准帧过滤器（全放行）

/* 发送相关接口 */
void CANFD_Send_Standard(uint32_t id, uint8_t pdata[8]); // 发送 8 字节标准帧
void CANFD_Send_Extended(uint32_t id, uint8_t pdata[8]); // 发送 8 字节扩展帧
void CANFD_Send_ExtRemote(uint32_t id);                  // 发送扩展远程帧

/* 诊断与工具 */
void HAL_FDCAN_PrintError(uint32_t error); // 打印 FDCAN 错误详细描述

#endif
