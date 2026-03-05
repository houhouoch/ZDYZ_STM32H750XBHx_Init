#ifndef _HOMEPAGE_H_
#define _HOMEPAGE_H_
#include "lvgl.h"

void HomePage_Refresh_All_Data(void);


#define NumberInput_Process(maxLen, SetFunction)                \
    static uint8_t inputIdx = 0;                                \
    static char inputBuf[32] = {0};                             \
    static uint8_t numInput_flag = 0;                           \
                                                                \
    /* v8 获取事件代码 */                                       \
    lv_event_code_t _code = lv_event_get_code(e);               \
    lv_obj_t * _obj = lv_event_get_target(e);                   \
                                                                \
    if(_code == LV_EVENT_KEY) {                                 \
        /* v8 获取按键值的标准方式 */                           \
        lv_key_t key = lv_event_get_key(e);                     \
                                                                \
        if((key == '.') || (('0' <= key) && (key <= '9'))) {    \
            numInput_flag = 1;                                  \
            if(inputIdx < maxLen) {                             \
                inputBuf[inputIdx] = (char)key;                 \
                inputBuf[inputIdx + 1] = '\0';                  \
                lv_label_set_text_static(_obj, inputBuf);       \
                lv_label_set_text_sel_start(_obj, inputIdx);    \
                lv_label_set_text_sel_end(_obj, inputIdx + 1);  \
                inputIdx += 1;                                  \
            }                                                   \
        }                                                       \
                                                                \
        if(numInput_flag == 1) {                                \
            switch(key) {                                       \
                case LV_KEY_LEFT:                               \
                    if(inputIdx > 0) {                          \
                        inputBuf[--inputIdx] = 0;               \
                        lv_label_set_text_static(_obj, inputBuf); \
                        /* 处理索引下限 */                      \
                        lv_label_set_text_sel_start(_obj, inputIdx-1);   \
                        lv_label_set_text_sel_end(_obj, inputIdx); \
                    }                                           \
                    return;                                     \
                                                                \
                case LV_KEY_ESC:                                \
                case LV_KEY_RETURN:                              \
                    numInput_flag = 0;                          \
                    inputIdx = 0;                               \
                    memset(inputBuf, 0, sizeof(inputBuf));      \
                    inputBuf[0] = '0';                          \
                    /* v7: LV_LABEL_TEXT_SEL_OFF -> v8: LV_LABEL_TEXT_SELECTION_OFF */ \
                    lv_label_set_text_sel_start(_obj, LV_LABEL_TEXT_SELECTION_OFF);    \
                    lv_label_set_text_sel_end(_obj, LV_LABEL_TEXT_SELECTION_OFF);      \
                    return;                                     \
                                                                \
                case LV_KEY_ENCODER: /* 适配部分编码器按键 */      \
                case LV_KEY_ENTER:                              \
                    inputIdx = 0;                               \
                    numInput_flag = 0;                          \
                    SetFunction(atof(inputBuf));                \
                    memset(inputBuf, 0, sizeof(inputBuf));      \
                    /* 手动触发点击事件以同步 UI */             \
                    lv_event_send(_obj, LV_EVENT_CLICKED, NULL);\
                    return;                                     \
                                                                \
                default:                                        \
                    return;                                     \
            }                                                   \
        }                                                       \
    }

void volSet_handler(lv_event_t * e);
    void ampSet_handler(lv_event_t * e);
void HomePage_Enter(void);
void HomePage_Exit(void);
void HomePage_GroupCreate(void);

#endif
