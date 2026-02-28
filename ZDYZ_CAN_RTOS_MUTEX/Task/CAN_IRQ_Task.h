#ifndef _CAN_IRQ_TASK_H_
#define _CAN_IRQ_TASK_H_
#include "FDCAN.h"

void CAN_Task_App_Start(void); // 导出启动接口
void CAN_Msg_Process_Task(void *argument);




// 1. ID 协议联合体 (29位扩展ID解析)
typedef union {
    uint32_t id;
    struct {
        uint32_t addr         :8;  // 0-7   设备地址
        uint32_t ch_num       :8;  // 8-15  通道号
        uint32_t device_type  :3;  // 16-18 设备类型
        uint32_t mode         :3;  // 19-21 模式
        uint32_t NC1          :1;  // 22    空
        uint32_t NC2          :1;  // 23    空
        uint32_t comm_type    :4;  // 24-27 指令类型
        uint32_t dir          :1;  // 28    数据方向，0接收，1发送
        uint32_t nc           :3;  // 29-31 空
    } id_bit;
} type_can_id;

// 2. 数据载荷联合体 (8字节解析)
typedef union {
    uint32_t  u32_data[2];
    float     f32_data[2];
    uint16_t  u16_data[4];
    uint8_t   u8_data[8];
} type_can_data;

// 3. 完整消息结构体
typedef struct {
    type_can_id   can_id;
    type_can_data can_data;
} type_can_message;


// 协议对象封装
typedef struct {
    uint8_t  addr;
    uint8_t  ch_num;
    uint8_t  device_type;
    uint8_t  mode;
    uint8_t  comm_type;
    uint8_t  dir;
} CAN_ID_Config_t;

// 核心：将配置压包成 29 位扩展 ID
static inline uint32_t CAN_Pack_ID(CAN_ID_Config_t cfg) {
    return (uint32_t)((cfg.addr & 0xFF) |
                      ((cfg.ch_num & 0xFF) << 8) |
                      ((cfg.device_type & 0x07) << 16) |
                      ((cfg.mode & 0x07) << 19) |
                      ((cfg.comm_type & 0x0F) << 24) |
                      ((cfg.dir & 0x01) << 28));
}




#endif
