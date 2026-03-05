#ifndef __Touch_H
#define __Touch_H
#include "main.h"



#ifndef __TOUCH_H
#define __TOUCH_H

#include "main.h"

/* ---------------- 引脚定义 (根据 CubeMX 的 Label 修改) ---------------- */
#define CT_INT_READ()       HAL_GPIO_ReadPin(TOUCH_INT_GPIO_Port, TOUCH_INT_Pin)
#define CT_RST(x)           HAL_GPIO_WritePin(TOUCH_RST_GPIO_Port, TOUCH_RST_Pin, x ? GPIO_PIN_SET : GPIO_PIN_RESET)
#define CT_INT(x)           HAL_GPIO_WritePin(TOUCH_INT_GPIO_Port, TOUCH_INT_Pin, x ? GPIO_PIN_SET : GPIO_PIN_RESET)

typedef enum
{
    CT_IIC_ADDR_14 = 0x14,    // 7-bit 地址 (INT复位期间为高)
    CT_IIC_ADDR_5D = 0x5D,    // 7-bit 地址 (INT复位期间为低)
} ct_iic_addr_t;

typedef struct
{
    uint16_t x;
    uint16_t y;
    uint16_t size;
} touch_point_t;

/* 错误代码 */
#define TOUCH_OK       0
#define TOUCH_ERROR    1

/* 函数声明 */
uint8_t touch_init(void);
uint8_t touch_scan(touch_point_t *point, uint8_t max_points);

#endif






#endif
