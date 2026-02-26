#include "./BSP/CAN/can.h"
#include "fdcan.h"

// 模拟主机中的大端序浮点数写入逻辑
typedef union {
    float f;
    uint8_t p[4];
} float_conv_t;

void Write_Float_To_Buffer(uint8_t *buf, float val) {
    float_conv_t temp;
    temp.f = val;
    // 转换为大端序
    buf[0] = temp.p[3];
    buf[1] = temp.p[2];
    buf[2] = temp.p[1];
    buf[3] = temp.p[0];
}

/**
 * @brief 发送 CAN 报文设置主机电压
 * @param voltage 电压值 (float)
 */
void DevBoard_Set_Host_Voltage(float voltage) {
    uint8_t tx_data[8] = {0};
    
    // 主机协议规定：data[0]是设备类型，data[1]是模式
    // 假设我们模拟一个普通电源，模式为并联主控(1)
    tx_data[0] = 0x01; 
    tx_data[1] = 0x01; 
    
    // 数据从第 4 个字节开始 (offset 4)
    Write_Float_To_Buffer(&tx_data[4], voltage);
    
    // 发送扩展帧 ID: 0x10001
    // 注意：实际 ID 可能还需要加上 (Mode<<4 | ID)<<8，此处以最基础 ID 为例
    DevBoard_Send_FDCAN_Msg(0x11001, tx_data, 8); 
}

/**
 * @brief 发送 CAN 报文设置主机电流
 */
void DevBoard_Set_Host_Current(float current) {
    uint8_t tx_data[8] = {0};
    tx_data[0] = 0x01; 
    tx_data[1] = 0x01; 
    
    Write_Float_To_Buffer(&tx_data[4], current);
    
    // 发送扩展帧 ID: 0x10002
    DevBoard_Send_FDCAN_Msg(0x11002, tx_data, 8);
}

/**
 * @brief 发送 CAN 报文控制主机输出开关
 * @param state 1 为开启 (ON), 0 为关闭 (OFF)
 */
void DevBoard_Set_Host_Output(uint8_t state) {
    uint8_t tx_data[8] = {0};
    
    // 模拟身份信息 (参考主机协议 data[0]=类型, data[1]=模式)
    tx_data[0] = 0x01; 
    tx_data[1] = 0x01; 
    
    // 写入开关状态：使用 2 字节大端序整数 (uint16_t)
    // 根据主机 CAN_READ_INT16 宏，data[4] 是高位，data[5] 是低位
    tx_data[4] = 0x00;           // 高字节
    tx_data[5] = (state ? 1 : 0); // 低字节 (1代表ON, 0代表OFF)
    
    // 发送 ID: 0x11000 (并联模式寄存器 0)
    DevBoard_Send_FDCAN_Msg(0x11000, tx_data, 8); 
}
/**
 * @brief 发送 CAN 报文控制主机输出开关
 * @param state 1 为开启 (ON), 0 为关闭 (OFF)
 */
void DevBoard_Set_Host_Output_test(uint8_t state) {
    uint8_t tx_data[8] = {0};
    
    // 模拟身份信息 (参考主机协议 data[0]=类型, data[1]=模式)
    tx_data[0] = 0x01; 
    tx_data[1] = 0x01; 
    
    // 写入开关状态：使用 2 字节大端序整数 (uint16_t)
    // 根据主机 CAN_READ_INT16 宏，data[4] 是高位，data[5] 是低位
    tx_data[4] = 0x00;           // 高字节
    tx_data[5] = (state ? 1 : 0); // 低字节 (1代表ON, 0代表OFF)
    
    // 发送 ID: 0x11000 (并联模式寄存器 0)
    DevBoard_Send_FDCAN_Msg(0x1100C, tx_data, 8); 

}
