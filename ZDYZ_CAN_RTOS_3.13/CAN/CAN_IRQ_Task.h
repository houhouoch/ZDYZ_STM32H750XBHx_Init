#ifndef _CAN_IRQ_TASK_H_
#define _CAN_IRQ_TASK_H_
#include "FDCAN.h"
#include "./User/power_interface.h"
#include "./CAN/can_manager.h"









void CAN_Task_App_Start(void); // 导出启动接口
void CAN_Msg_Process_Task(void *argument);
void Protocol_Send_Command(e_can_addr addr, e_can_control cmd);


#endif
