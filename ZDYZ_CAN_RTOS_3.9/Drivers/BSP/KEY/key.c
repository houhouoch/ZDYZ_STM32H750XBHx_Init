/**
 ****************************************************************************************************
 * @file        key.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2023-06-12
 * @brief       按键驱动代码
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 * 
 * 实验平台:正点原子 北极星 H750开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 * 
 ****************************************************************************************************
 */

#include "./BSP/KEY/key.h"

//按键映射
typedef struct {
    uint8_t buttonNum;
    uint8_t key_short;
    uint8_t key_long;
    uint8_t key_hold;
} Button_KeyTable_Def;

// 针对你当前 4 个按键的映射配置
static const Button_KeyTable_Def Btn_KeyTable[] = {
    // 物理ID      | 短按触发(1)   | 长按触发(1.5s)     | 按住触发(50ms)
    {ID_KEY0,      LV_KEY_MENU,  LV_KEY_ENTER_LONGP,  LV_KEY_DEFAULT}, 
    {ID_KEY1,      LV_KEY_ESC,    LV_KEY_ESC_LONGP,    LV_KEY_DEFAULT},
    {ID_KEY2,      LV_KEY_DOWN,   LV_KEY_DOWN,         LV_KEY_DEFAULT}, // 重点：HOLD 设为 DEFAULT
    {ID_WKUP,      LV_KEY_UP,     LV_KEY_UP,           LV_KEY_DEFAULT}, // 重点：HOLD 设为 DEFAULT
};

//主页面对象

uint8_t matrixButton_Scan(void)
{
    // KEY0 按下 (低电平有效)
    if (HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET) return ID_KEY0;
    
    // KEY1 按下 (低电平有效)
    if (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET) return ID_KEY1;
    
    // KEY2 按下 (低电平有效)
    if (HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin) == GPIO_PIN_RESET) return ID_KEY2;
    
    // WK_UP 按下 (高电平有效)
    if (HAL_GPIO_ReadPin(WK_UP_GPIO_Port, WK_UP_Pin) == GPIO_PIN_SET) return ID_WKUP;

    return ID_NONE; // 无按键按下
}

#define LONGPPRESS_TIME 1500
#define SHORTPRESS_TIME 50
//长按键自动跳出
#define BUTTON_LONGPRESS_AUTO_RETURN 1

static uint32_t timeDiff(uint16_t t0, uint16_t t1)
{
    uint32_t time = 0;
    if(t0 > t1) {
        time = 65536 + t1 - t0;
    } else {
        time = t1 - t0;
    }
    return time;
}
uint8_t keyScan(uint8_t *pkey)
{
    if(pkey == NULL)
    { return KEY_STATE_RELEASED; }
    //返回值(按键状态)
    uint8_t keystate = KEY_DEFAULT;
    *pkey = 0xff;
    //开始矩阵扫描
    uint8_t keyValue = matrixButton_Scan();
    static uint8_t lastKey = 0xff;
    static uint8_t triggerFlag = 0;
    static uint8_t holdSendFlag = 0;
    //计算时间差
    static uint16_t t0 = 0;
    uint16_t t1 = HAL_GetTick();
    uint32_t count = timeDiff(t0, t1);
    *pkey = 0xff;
    {
        //按键状态发生变化
        if(lastKey != keyValue)
        {
            //按下记录时间
            if(lastKey == 0xff) {
                triggerFlag = 0;
                holdSendFlag = 0;
                //锚定时间
                t0 = HAL_GetTick();
            }
            if((lastKey != 0xff) && (keyValue == 0xff))
            {
                if(triggerFlag == 0)
                {
                    //释放计算时间
                    if((count  < LONGPPRESS_TIME) && (count  > SHORTPRESS_TIME))
                    {
                        //短按
                        triggerFlag = 1;
                        printf("ShortPress %d \r\n", lastKey);
                        *pkey = lastKey;
                        keystate = KEY_STATE_CLICKED;
                    } else
                        if(count > LONGPPRESS_TIME) {
                            //长按
                            triggerFlag = 1;
                            printf("LongPress %d \r\n", lastKey);
                            *pkey = lastKey;
                            keystate = KEY_STATE_LONGGP;
                        }
                }
            }
            lastKey = keyValue;
        } else
            if(keyValue != 0xff)     //按键已被按下
            {
                if(triggerFlag == 0)
                {
                    //已按下,超过长按时间自动跳出
                    #if (BUTTON_LONGPRESS_AUTO_RETURN != 0)
                    if(count >= LONGPPRESS_TIME) {
                        triggerFlag = 1;
                        printf("LongPress H %d\r\n", lastKey);
                        *pkey = lastKey;
                        keystate = KEY_STATE_LONGGP;
                    }
                    #endif
                }
                if(holdSendFlag == 0)
                {
                    if(count > (SHORTPRESS_TIME + 1)) {
                        *pkey = lastKey;
                        keystate = KEY_STATE_HOLD;
                        holdSendFlag = 1;
                    }
                }
            }
    }
    return keystate;
}

/*
 * @brief       lv_key_t Button_toKey(uint8_t buttonNum,uint8_t flag)
 * @details     将实体按键转为LV_KEY事件
 */
lv_key_t Button_toKey(uint8_t buttonNum, uint8_t flag)
{
    static uint8_t waitCount = 0;
    if(buttonNum == 0xff) {
    } else {
        //实体按键
        uint16_t tablesize = sizeof(Btn_KeyTable) / sizeof(Btn_KeyTable[0]);
        for(uint8_t i = 0; i < tablesize; ++i)
        {
            if(buttonNum == Btn_KeyTable[i].buttonNum)
            {
                lv_key_t key = LV_KEY_DEFAULT;
                switch(flag)
                {
                    case KEY_STATE_HOLD:
                        key = Btn_KeyTable[i].key_hold;
                        break;
                    case KEY_STATE_CLICKED:
                        key = Btn_KeyTable[i].key_short;
                        break;
                    case KEY_STATE_LONGGP:
                        key = Btn_KeyTable[i].key_long;
                        break;
                    default:
                        key = LV_KEY_DEFAULT;
                        break;
                }
                //                if((key == LV_KEY_ENCODER) || (key == LV_KEY_ENCODER_LONGP))
                {
                    waitCount = 5;
                }
                return key;
            }
        }
    }
//    //编码器转换
//    lv_key_t encoderKey = Encoder_Get();
//    //防止按下编码器 误触发旋转
//    if(waitCount == 0) {
//        if(encoderKey != LV_KEY_DEFAULT)
//        {
//            return encoderKey;
//        }
//    } else {
//        waitCount--;
//    }
    return LV_KEY_DEFAULT;
}
