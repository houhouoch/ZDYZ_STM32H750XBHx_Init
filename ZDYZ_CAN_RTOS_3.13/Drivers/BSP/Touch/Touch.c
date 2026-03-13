#include "./BSP/TOUCH/Touch.h"
#include "./BSP/TOUCH/ctiic.h"
#include <string.h>
#include <stdio.h>


#define CT_REG_CTRL          0x8040  // 控制寄存器
#define CT_REG_PID           0x8140  // PID 寄存器 (读取 "1151")
#define CT_REG_TPINFO        0x814E  // 状态寄存器 (最高位为1表示有按下)
#define CT_REG_TP1           0x8150  // 触摸点 1 基地址
//#define CT_REG_TP2           0x8158  // 触摸点 2 基地址
//#define CT_REG_TP3           0x8160  // 触摸点 3 基地址
//#define CT_REG_TP4           0x8168  // 触摸点 4 基地址
//#define CT_REG_TP5           0x8170  // 触摸点 5 基地址
//#define CT_POINT_SIZE        8       // 每个触摸点占用的字节数

static uint8_t g_touch_addr = CT_IIC_ADDR_14;

/**
 * @brief 硬件复位并选定 I2C 地址
 * @note GT1151Q 通过复位期间 INT 引脚电平确定地址
 */

static void touch_hw_reset(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    
    // 【关键补全1】开启 INT 和 RST 引脚所在端口的时钟
    // 假设你的引脚在 GPIOB/GPIOC，请根据实际情况修改
    __HAL_RCC_GPIOH_CLK_ENABLE(); 
    __HAL_RCC_GPIOI_CLK_ENABLE();

    // 【关键补全2】必须初始化 RST 引脚为输出
    GPIO_InitStruct.Pin = TOUCH_RST_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(TOUCH_RST_GPIO_Port, &GPIO_InitStruct);

    // 初始化 INT 引脚为输出（用于设置地址）
    GPIO_InitStruct.Pin = TOUCH_INT_Pin;
    HAL_GPIO_Init(TOUCH_INT_GPIO_Port, &GPIO_InitStruct);

    // --- 复位序列 ---
    CT_RST(0);          // 拉低复位
    CT_INT(0);          // 初始设为低
    HAL_Delay(20);      // 保持至少 10ms [cite: 35, 209]
    
    CT_INT(1);         // 【关键】释放复位前拉高 INT，以选择 0x14 地址 [cite: 37]
    HAL_Delay(2);
    CT_RST(1);          // 释放复位
    HAL_Delay(20);      // 等待芯片锁存地址

    // 将 INT 切换回输入模式
    GPIO_InitStruct.Pin = TOUCH_INT_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL; 
    HAL_GPIO_Init(TOUCH_INT_GPIO_Port, &GPIO_InitStruct);
    
    g_touch_addr = CT_IIC_ADDR_14; 
    HAL_Delay(100);     // 给予充分的上电延时
}
/**
 * @brief 写入寄存器 (适配你的 ctiic.c)
 */
static uint8_t touch_write_reg(uint16_t reg, uint8_t *buf, uint8_t len)
{
    uint8_t i;
    ct_iic_start();
    ct_iic_send_byte((g_touch_addr << 1) | 0); // 写命令
    if(ct_iic_wait_ack()) { ct_iic_stop(); return TOUCH_ERROR; }
    
    ct_iic_send_byte(reg >> 8);  // 寄存器高8位
    ct_iic_wait_ack();
    ct_iic_send_byte(reg & 0xFF); // 寄存器低8位
    ct_iic_wait_ack();

    for (i = 0; i < len; i++) {
        ct_iic_send_byte(buf[i]);
        ct_iic_wait_ack();
    }
    ct_iic_stop();
    return TOUCH_OK;
}

/**
 * @brief 读取寄存器（修正最后字节的处理）
 */
static void touch_read_reg(uint16_t reg, uint8_t *buf, uint8_t len)
{
    uint8_t i;
    ct_iic_start();
    ct_iic_send_byte((g_touch_addr << 1) | 0); 
    ct_iic_wait_ack();
    ct_iic_send_byte(reg >> 8);  
    ct_iic_wait_ack();
    ct_iic_send_byte(reg & 0xFF); 
    ct_iic_wait_ack();

    // 重新起始
    ct_iic_start();
    ct_iic_send_byte((g_touch_addr << 1) | 1); 
    ct_iic_wait_ack();

    for (i = 0; i < len; i++) {
        // 读取最后一个字节时发送 NACK (0) 
        buf[i] = ct_iic_read_byte( (i == (len - 1)) ? 0 : 1 );
    }
    ct_iic_stop();
}

/**
 * @brief 初始化触摸芯片
 */
uint8_t touch_init(void)
{
    char pid[5] = {0};
    
    touch_hw_reset();  
    ct_iic_init();     

    // 读取 PID 校验
    touch_read_reg(CT_REG_PID, (uint8_t *)pid, 4);
    pid[4] = '\0';
   
    if (strcmp(pid, "1151") != 0 && strcmp(pid, "1158") != 0) 
    {
        printf("Unknown Touch Chip! PID: %s\n", pid);
        return TOUCH_ERROR;
    }
    printf("Touch Chip Identified: %s, Initializing...\n", pid);
    // 软件复位指令 
    uint8_t dat = 0x02;
    touch_write_reg(CT_REG_CTRL, &dat, 1);
    HAL_Delay(10);
    dat = 0x00;
    touch_write_reg(CT_REG_CTRL, &dat, 1);

    return TOUCH_OK;
}

/**
 * @brief 扫描触摸点
 */
uint8_t touch_scan(touch_point_t *point, uint8_t max_points)
{
    uint8_t tp_info;
    uint8_t tp_cnt;
    uint8_t tp_raw[6];
    
    touch_read_reg(CT_REG_TPINFO, &tp_info, 1);
    

    if ((tp_info & 0x80) && ((tp_info & 0x0F) <= 5)) {
        tp_cnt = tp_info & 0x0F;
        if (tp_cnt > max_points) tp_cnt = max_points;

        for (uint8_t i = 0; i < tp_cnt; i++) {
            touch_read_reg(CT_REG_TP1 + (i * 8), tp_raw, 6);
            point[i].x = (uint16_t)(tp_raw[1] << 8) | tp_raw[0];
            point[i].y = (uint16_t)(tp_raw[3] << 8) | tp_raw[2];
            point[i].size = (uint16_t)(tp_raw[5] << 8) | tp_raw[4];
        }

        // 读完后必须清零状态位，否则芯片不会上报下一次数据
        tp_info = 0;
        touch_write_reg(CT_REG_TPINFO, &tp_info, 1);
        return tp_cnt;
    }
    return 0;
}
