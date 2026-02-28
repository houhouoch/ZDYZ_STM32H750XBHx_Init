#include "CAN_IRQ_Task.h"
#include "./BSP/CAN/can.h"

osThreadId_t canTaskHandle;
const osThreadAttr_t canTask_attr = {
    .name = "CanTask",
    .stack_size = 512 * 4,
    .priority = osPriorityAboveNormal,
};

/**
 * @brief 外部调用的启动函数
 */
void CAN_Task_App_Start(void) {
    // 1. 先初始化底层的同步资源（队列、互斥锁、信号量）
    CAN_App_Init(); 
    
    // 2. 创建并启动任务
    canTaskHandle = osThreadNew(CAN_Msg_Process_Task, NULL, &canTask_attr);
}

#define CANID_DATA_SEND      3  //输出电流电压数据主动输出
#define CANID_CONTROL        1  //动作控制
#define ANALYSIS_CORRECT        1//接收到 解析成功

void CAN_Msg_Process_Task(void *argument) {
    CAN_Msg_t rx_raw;           // 接收队列里的原始数据
    type_can_message msg;       // 按照公司协议解析后的消息

for(;;) {
        if (osMessageQueueGet(can_rx_queue_handle, &rx_raw, NULL, osWaitForever) == osOK) {
            // 1. 解析 ID (这一步你已经做对了)
            msg.can_id.id = rx_raw.Identifier;

            // 2. 处理大端序数据 (Payload)
            // 我们手动把 rx_raw.Data[0..3] 倒序拼成一个小端浮点数
            if(msg.can_id.id_bit.comm_type == CANID_DATA_SEND) {
                uint32_t temp_v = ((uint32_t)rx_raw.Data[0] << 24) | 
                                  ((uint32_t)rx_raw.Data[1] << 16) | 
                                  ((uint32_t)rx_raw.Data[2] << 8)  | 
                                   (uint32_t)rx_raw.Data[3];
                
                uint32_t temp_i = ((uint32_t)rx_raw.Data[4] << 24) | 
                                  ((uint32_t)rx_raw.Data[5] << 16) | 
                                  ((uint32_t)rx_raw.Data[6] << 8)  | 
                                   (uint32_t)rx_raw.Data[7];

                // 使用 memcpy 避开对齐问题，将拼好的 32 位整型转为 float
                float voltage, current;
                memcpy(&voltage, &temp_v, 4);
                memcpy(&current, &temp_i, 4);

                printf("[ID:%d] Volt:%.2fV, Curr:%.2fA\n", (int)msg.can_id.id_bit.addr, voltage, current);
            }
        }
    }
}

#define CANID_BUCK          1   //BUCK
#define CANID_DIR_TX  1    //DSP发送出去数据
#define CANID_WORK_MODE     1 //正常工作模式
/**
 * @brief 发送一个符合公司协议的控制指令
 * @param addr: 目标设备地址
 * @param cmd:  指令内容 (如 CONTROL_OUT_EN)
 */
void Protocol_Send_Command(uint8_t addr, uint8_t cmd) {
    type_can_message tx_msg = {0};
    
    // 1. 组装 ID 位域
    tx_msg.can_id.id_bit.addr = addr;
    tx_msg.can_id.id_bit.device_type = CANID_BUCK;
    tx_msg.can_id.id_bit.comm_type = CANID_CONTROL;
    tx_msg.can_id.id_bit.dir = CANID_DIR_TX;
    tx_msg.can_id.id_bit.mode = CANID_WORK_MODE;
    
    // 2. 填充数据
    tx_msg.can_data.u8_data[0] = cmd;
    
    // 3. 调用你的底层发送 (自动处理互斥锁和信号量)
    CANFD_Send_Extended(tx_msg.can_id.id, tx_msg.can_data.u8_data);
}
