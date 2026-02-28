#include "HomePage.h"
#include "Gui_Task.h"
#include "HomePage_LED.h"


/*
 * @brief       @OutSet_Def
 * @details     输出设置结构体
 */
typedef struct {


    //定时关闭(单位:100ms)  0.1s~99999.9s
    uint8_t Timeout_onoff;  //定时关闭开关    
    float TimeOff;
    float curTime;
    
    uint8_t outled_duty;    //输出LED
    uint8_t out;            //输出开关
    uint8_t lock;
    float V_Set;            //设定电压,V
    float I_Set;            //设定电流,A  
    uint8_t OVP_onoff;      //OVP开关
    uint8_t OCP_onoff;      //OCP开关
    float V_OVP;            //过压保护,V
    float I_OCP;            //过流保护,A

     uint8_t mode;           //工作模式: @POWER_MODE_ENUM
     uint8_t P_Out;          //上电保持  
     uint8_t dvm_onoff; 
     uint8_t SR_Mode;

     float V_SR_U;           //斜率,V/S  MAX:V_MAX*2 V/s
     float V_SR_D;           //斜率,V/S  MAX:V_MAX*2 V/s
 
     float I_SR_U;           //斜率,A/S  MAX:I_MAX*2 A/s
     float I_SR_D;           //斜率,A/S  MAX:I_MAX*2 A/s
     
} OutSet_Def;

/*
 * @brief       @Group_Def
 * @details     用户组(保存)
 */
typedef struct {
    OutSet_Def outset;
    uint8_t md5Value[16];
} Group_Def;

Group_Def CurGroup;

void HomePage_Enter(void)
{
    lv_obj_clear_flag(ui.HOME_PAGE_cont_1,LV_OBJ_FLAG_HIDDEN);
    ui_led_start(ui.HOME_PAGE_led_1);
  
}
void HomePage_Exit(void)
{
    
    lv_obj_add_flag(ui.HOME_PAGE_cont_1,LV_OBJ_FLAG_HIDDEN);
    // 手动停止该对象的所有动画，节省系统开销
   // lv_anim_del(ui.HOME_PAGE_led_1, NULL);
  
}


/*
 * @brief       void label_setSelNum(lv_obj_t* label,uint16_t numpos,const char* text)
 * @details     Label选择特定数字(用于设置参数)
 */
void label_setSelNum(lv_obj_t *label, uint16_t numpos, const char *text)
{
    if(label == NULL) {
        return;
    }
    uint16_t strLen = strlen(text);
    uint16_t bitindex = 0;
    for(int16_t i = strLen - 1; i >= 0; --i)
    {
        if((('0' <= text[i]) && (text[i] <= '9')) || (text[i] == ' '))
        {
            if(bitindex == numpos)
            {
                lv_label_set_text_sel_start(label, i);
                lv_label_set_text_sel_end(label, i + 1);
                return ;
            }
            bitindex++;
        }
    }
}

// @brief 辅助函数：刷新 UI 显示
static char stringSet[64] = {0};
static void Set_RefreshUI(lv_obj_t *obj, uint8_t *editIndex, const char *dispfmt, double value)
{
    if(obj == NULL) {
        return ;
    }
    //
    sprintf(stringSet, dispfmt, value);
    if(editIndex != NULL) {
        label_setSelNum(obj, *editIndex, stringSet);
    } else {
    }
    lv_label_set_text(obj, stringSet);
    //
    if(editIndex == NULL) 
        {
          lv_obj_add_state(obj, LV_STATE_DEFAULT);
        lv_label_set_text_sel_start(obj, LV_LABEL_TEXT_SELECTION_OFF);
        lv_label_set_text_sel_end(obj, LV_LABEL_TEXT_SELECTION_OFF);
    } else {
        lv_obj_add_state(obj, LV_STATE_FOCUSED);
    }
}

// 定义步进数组 (根据你的项目实际定义)
const double V_step[] = {0.001, 0.01, 0.1, 1.0, 10.0}; 
#define VOL_SET_FORM        "%0.3f"
#define VOL_SET_VALUE       (CurGroup.outset.V_Set)

float IF_Power_Get_SetVol(void)
{
    return VOL_SET_VALUE;
}
void UI_IF_Power_SetVol(float value)
{   
   float setVol = value;        
    // 4. 更新全局变量并同步硬件 (如 DAC)
    VOL_SET_VALUE = setVol;
}

#define DEFAULT_INDEX_V  3 // 默认指向 1V 这一位

void volSet_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    // 使用静态变量记录当前位选位置
    static uint8_t index_v = DEFAULT_INDEX_V;
    
    switch(code)
    {
        case LV_EVENT_FOCUSED: {
            // 当 Tree_UI_Sel_Enter 被调用时，会自动触发这里
            index_v = DEFAULT_INDEX_V; 
            Set_RefreshUI(obj, &index_v, VOL_SET_FORM, IF_Power_Get_SetVol());
            break;
        }

        case LV_EVENT_KEY: {     
            
        lv_key_t key = lv_event_get_key(e);            
            double current_v = IF_Power_Get_SetVol();
            switch(key) {
                case LV_KEY_UP:    // 对应 KEY1
                    current_v += V_step[index_v];
                    UI_IF_Power_SetVol(current_v);
                    break;

                case LV_KEY_DOWN:  // 对应 KEY2
                    current_v -= V_step[index_v];
                    UI_IF_Power_SetVol(current_v);
                    break;

                case LV_KEY_LEFT:  // 如果你有左右键切换位选
                    if(index_v < (sizeof(V_step)/sizeof(V_step[0]) - 1)) index_v++;
                    break;

                case LV_KEY_RIGHT:
                    if(index_v > 0) index_v--;
                    break;

                case LV_KEY_ENTER:
                case LV_KEY_ESC:
                    // 关键：调用树框架的退出函数，解除高亮，返回主页状态
                    Tree_UI_Sel_Exit(); 
                    return; 
            }
            // 每次按键后刷新显示 (带光标)
            Set_RefreshUI(obj, &index_v, VOL_SET_FORM, IF_Power_Get_SetVol());
            break;
        }

        case LV_EVENT_DEFOCUSED: {
            // 失去焦点时，刷新 UI 但不传 index_v (即隐藏光标)
            Set_RefreshUI(obj, NULL, VOL_SET_FORM, IF_Power_Get_SetVol());
            break;
        }

        default: break;
    }
}

void HomePage_GroupCreate(void)
{
    
    {//初始化
    /* 1. 先创建屏幕对象 */
    setup_scr_HOME_PAGE(&ui);    
    /* 2. 调整父级关系 */
    lv_obj_set_parent(ui.HOME_PAGE_cont_1, ui.Back_cont_back);
    /* 进入页面逻辑 */
    
    } 

    HomePage_Enter();

}

