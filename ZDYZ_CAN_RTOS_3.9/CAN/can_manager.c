/**
 ****************************************************************************************************
 * @file        can_manager.c
 * @brief       CAN业务逻辑管理层：负责协议解析、数据分发与任务调度
 ****************************************************************************************************
 */
#include "./CAN/can_manager.h"

/* ------------------ [私有资源] ------------------ */
static osThreadId_t canTaskHandle;
static const osThreadAttr_t canTask_attr = {
    .name = "CanTask",
    .stack_size = 512 * 4,
    .priority = osPriorityAboveNormal,
};

/* ------------------ [内部工具函数] ------------------ */
/**
 * @brief  私有工具函数：将大端序字节数组解析为 float (Big-Endian to Float)
 */
static inline float _Unpack_Float_BE(const uint8_t *p_source) {
    union {
        float f;
        uint8_t b[4];
    } conv;
    
    conv.b[3] = p_source[0];
    conv.b[2] = p_source[1];
    conv.b[1] = p_source[2];
    conv.b[0] = p_source[3];
    
    return conv.f;
}


/**
 * @brief  下位机回复函数 ( Reply)
 * @param  rx_msg: 接收到的上位机原始消息结构体
 * @param  result: 处理结果 (1: 成功, 0: 失败/有保护)
 */
void Protocol_Slave_Reply(type_can_message *rx_msg, uint16_t result) {
    type_can_message tx_msg = {0};
    // 1. 复制 ID 基础信息
    tx_msg.can_id.id = rx_msg->can_id.id;    
    // 2. 方向位：1 标记为从机发送
    tx_msg.can_id.id_bit.dir = 1; 
    // 3. 填充数据位
    // b0-b1: 动作 (直接回写上位机的动作码)
    tx_msg.can_data.u8_data[0] = rx_msg->can_data.u8_data[0];
    tx_msg.can_data.u8_data[1] = rx_msg->can_data.u8_data[1];
    // b2-b3: 结果 (1: 解析成功, 0: 解析失败/有保护)
    tx_msg.can_data.u8_data[2] = (uint8_t)(result & 0xFF);
    tx_msg.can_data.u8_data[3] = (uint8_t)((result >> 8) & 0xFF);
    // b4-b7: 留空 
    memset(&tx_msg.can_data.u8_data[4], 0, 4);
    // 4. 发送回传报文
    CANFD_Send_Extended(tx_msg.can_id.id, tx_msg.can_data.u8_data);
}

/* ------------------ [核心解析任务] ------------------ */
/**
 * @brief CAN 消息处理主循环
 */
void CAN_Msg_Process_Task(void *argument) {
    CAN_Msg_t rx_raw;
    type_can_message msg;

    for(;;) {
        if (osMessageQueueGet(can_rx_queue_handle, &rx_raw, NULL, osWaitForever) == osOK) {
            msg.can_id.id = rx_raw.Identifier;
            memcpy(msg.can_data.u8_data, rx_raw.Data, 8);
            
           // 仅处理 Host -> Slave 的数据
            if(msg.can_id.id_bit.dir == 0) {     
                uint16_t process_result = 0; // 默认失败                  
                // 判定是否为动作控制类型
                // (1. 动作控制类 (ORDER_CONTROL))
                if(msg.can_id.id_bit.comm_type == 1) {                    
                    // 提取动作码 (b0-b1)
                    uint16_t action = (uint16_t)msg.can_data.u8_data[0] | ((uint16_t)msg.can_data.u8_data[1] << 8);                    
                                      
                    // 业务逻辑处理
                    switch(action) {
                        case CONTROL_OUT_EN: // 启动
                            {
                                process_result = 1;
                            }
                            break;                            
                        case CONTROL_SET_OUTSI: // 设置电流
                            {
                                float Current = _Unpack_Float_BE(&msg.can_data.u8_data[4]);
                                IF_Power_Set_OutCurr(Current);
                                HomePage_Refresh_All_Data();
                                printf("[RX_CMD] Action: Set Current | Source Box: %d | Value: %.3f A\r\n",msg.can_id.id_bit.addr, Current);
                                process_result = 1;
                            } break;   
                        case CONTROL_SET_OUTV: // 设置电压
                            {
                                float val = _Unpack_Float_BE(&msg.can_data.u8_data[4]);
                                IF_Power_Set_OutVolt(val);
                                HomePage_Refresh_All_Data();
                                printf("[RX_CMD] Action: Set Voltage | Source Box: %d | Value: %.3f V\r\n", msg.can_id.id_bit.addr, val);
                                process_result = 1;
                            } break;                                         
                        // ... 其他动作处理 ...                        
                        default:
                            process_result = 0; // 未知动作
                            break;
                    }                   
                    // --- 关键：按照图纸回复确认报文 ---
                    Protocol_Slave_Reply(&msg, process_result);                    
//                    // 调试打印
//                    printf("[RX] Cmd:%d | Result:%s\r\n", action, 
//                            process_result ? "Success" : "Failed/Protected");
                }
            }
        }
    }
}

/* ------------------ [对外公开接口] ------------------ */
void CAN_Task_App_Start(void) {
    // 1. 初始化底层同步资源（调用 can.c 中的初始化）
    CAN_Hardware_Resources_Init(); 
    
    // 2. 启动任务
    canTaskHandle = osThreadNew(CAN_Msg_Process_Task, NULL, &canTask_attr);
    if (canTaskHandle == NULL) {
        printf("[Error] CAN Task Creation Failed!\r\n");
    }
}

