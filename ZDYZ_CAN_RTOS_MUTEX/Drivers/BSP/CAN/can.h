#ifndef __CAN_H_
#define __CAN_H_

#include "main.h"
#include "fdcan.h"
#include "cmsis_os.h"

// 重新定义 RTOS 传输用的报文结构体，直接包含协议结构
typedef struct {
    uint32_t Identifier;    // 原始 ID (用于 HAL 库)
    uint32_t IdType;        // 标准/扩展帧
    uint8_t  Data[8];       // 原始数据
    uint8_t  Len;           // 长度
} CAN_Msg_t;

// 2. 外部句柄声明 (方便跨文件访问)
extern osMessageQueueId_t can_rx_queue_handle;
extern osMutexId_t        can_tx_mutex_handle;
extern osSemaphoreId_t    can_tx_semaphore_handle;


void CAN_App_Init(void); 
void CANFD_Send_Standard(uint32_t id, uint8_t pdata[8]);
void CANFD_Send_Extended(uint32_t id, uint8_t pdata[8]);
void CANFD_Send_ExtRemote(uint32_t id);
void CAN_Set_Std_Filter_All(void);
void CANFD_Set_RX0_Filiter(void);
void HAL_FDCAN_PrintError(uint32_t error);


#endif
