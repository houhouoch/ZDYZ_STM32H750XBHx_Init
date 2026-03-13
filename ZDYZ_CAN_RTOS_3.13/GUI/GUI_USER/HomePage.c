#include "HomePage.h"

/**
 * @brief 主页菜单图标触摸点击回调
 */
static void homepage_menu_icon_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    
    if(code == LV_EVENT_CLICKED) 
    {
        printf("[Touch] Menu Icon Clicked -> Switching to Menu Page\n");
        
        // 核心：直接调用页面切换函数，进入菜单页面
        // 这和按下物理 MENU 键的效果是一模一样的
        UI_Switch_Page(PAGE_MENU);
    }
}

void HomePage_Enter(void)
{
    lv_obj_clear_flag(ui.HOME_PAGE_cont_Set,LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui.HOME_PAGE_cont_menu,LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui.HOME_PAGE_cont_read_back_value,LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui.HOME_PAGE_cont_2,LV_OBJ_FLAG_HIDDEN);

    ui_led_start(ui.HOME_PAGE_led_1);
  
}
void HomePage_Exit(void)
{       
    lv_obj_add_flag(ui.HOME_PAGE_cont_Set,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui.HOME_PAGE_cont_menu,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui.HOME_PAGE_cont_read_back_value,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui.HOME_PAGE_cont_2,LV_OBJ_FLAG_HIDDEN);
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
            Set_RefreshUI(obj, &index_v, VOL_SET_FORM, IF_Power_Get_OutVolt());
            break;
        }

        case LV_EVENT_KEY: {     
            
        lv_key_t key = lv_event_get_key(e);            
            double current_v = IF_Power_Get_OutVolt();
            switch(key) {
                case LV_KEY_UP:    // 对应 KEY1
                    current_v += V_step[index_v];
                    IF_Power_Set_OutVolt(current_v);
                    break;

                case LV_KEY_DOWN:  // 对应 KEY2
                    current_v -= V_step[index_v];
                    IF_Power_Set_OutVolt(current_v);
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
            Set_RefreshUI(obj, &index_v, VOL_SET_FORM, IF_Power_Get_OutVolt());
            break;
        }

        case LV_EVENT_DEFOCUSED: {
            // 失去焦点时，刷新 UI 但不传 index_v (即隐藏光标)
            Set_RefreshUI(obj, NULL, VOL_SET_FORM, IF_Power_Get_OutVolt());
            break;
        }

        default: break;
    }
}
/****************************************************************/

// 定义步进数组 (根据你的项目实际定义)
const float A_step[6] = {0.0001, 0.001, 0.01, 0.1, 1.0, 10.0};
#define AMP_SET_FORM        "%0.4f"
#define DEFAULT_INDEX_A  4

void ampSet_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    // 使用静态变量记录当前位选位置
    static uint8_t index_a = DEFAULT_INDEX_A;
    
    switch(code)
    {
        case LV_EVENT_FOCUSED: {
            // 当 Tree_UI_Sel_Enter 被调用时，会自动触发这里
            index_a = DEFAULT_INDEX_A; 
            Set_RefreshUI(obj, &index_a, AMP_SET_FORM, IF_Power_Get_OutCurr());
            break;
        }

        case LV_EVENT_KEY: {     
            
        lv_key_t key = lv_event_get_key(e);            
            double current_a_neg = IF_Power_Get_OutCurr();
            switch(key) {
                case LV_KEY_UP:    // 对应 KEY1
                    current_a_neg += A_step[index_a];
                    IF_Power_Set_OutCurr(current_a_neg);
                    break;

                case LV_KEY_DOWN:  // 对应 KEY2
                    current_a_neg -= A_step[index_a];
                    IF_Power_Set_OutCurr(current_a_neg);
                    break;

                case LV_KEY_LEFT:  // 如果你有左右键切换位选
                    if(index_a < (sizeof(A_step)/sizeof(A_step[0]) - 1)) index_a++;
                    break;

                case LV_KEY_RIGHT:
                    if(index_a > 0) index_a--;
                    break;

                case LV_KEY_ENTER:
                case LV_KEY_ESC:
                    // 关键：调用树框架的退出函数，解除高亮，返回主页状态
                    Tree_UI_Sel_Exit(); 
                    return; 
            }
            // 每次按键后刷新显示 (带光标)
            Set_RefreshUI(obj, &index_a, AMP_SET_FORM, IF_Power_Get_OutCurr());
            break;
        }

        case LV_EVENT_DEFOCUSED: {
            // 失去焦点时，刷新 UI 但不传 index_a (即隐藏光标)
            Set_RefreshUI(obj, NULL, AMP_SET_FORM, IF_Power_Get_OutCurr());
            break;
        }

        default: break;
    }
}


// 定义步进数组 (根据你的项目实际定义)
const float A_neg_step[6] = {0.0001, 0.001, 0.01, 0.1, 1.0, 10.0};
#define AMP_neg_SET_FORM        "%0.4f"
#define DEFAULT_INDEX_A_neg  4
void ampSet_handler_neg(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    // 使用静态变量记录当前位选位置
    static uint8_t index_a_neg = DEFAULT_INDEX_A_neg;
    
    switch(code)
    {
        case LV_EVENT_FOCUSED: {
            // 当 Tree_UI_Sel_Enter 被调用时，会自动触发这里
            index_a_neg = DEFAULT_INDEX_A_neg; 
            Set_RefreshUI(obj, &index_a_neg, AMP_neg_SET_FORM, IF_Power_Get_OutCurr());
            break;
        }

        case LV_EVENT_KEY: {     
            
        lv_key_t key = lv_event_get_key(e);            
            double current_a_neg = IF_Power_Get_OutCurr();
            switch(key) {
                case LV_KEY_UP:    // 对应 KEY1
                    current_a_neg += A_neg_step[index_a_neg];
                    IF_Power_Set_OutCurr(current_a_neg);
                    break;

                case LV_KEY_DOWN:  // 对应 KEY2
                    current_a_neg -= A_neg_step[index_a_neg];
                    IF_Power_Set_OutCurr(current_a_neg);
                    break;

                case LV_KEY_LEFT:  // 如果你有左右键切换位选
                    if(index_a_neg < (sizeof(A_neg_step)/sizeof(A_neg_step[0]) - 1)) index_a_neg++;
                    break;

                case LV_KEY_RIGHT:
                    if(index_a_neg > 0) index_a_neg--;
                    break;

                case LV_KEY_ENTER:
                case LV_KEY_ESC:
                    // 关键：调用树框架的退出函数，解除高亮，返回主页状态
                    Tree_UI_Sel_Exit(); 
                    return; 
            }
            // 每次按键后刷新显示 (带光标)
            Set_RefreshUI(obj, &index_a_neg, AMP_neg_SET_FORM, IF_Power_Get_OutCurr());
            break;
        }

        case LV_EVENT_DEFOCUSED: {
            // 失去焦点时，刷新 UI 但不传 index_a_neg (即隐藏光标)
            Set_RefreshUI(obj, NULL, AMP_neg_SET_FORM, IF_Power_Get_OutCurr());
            break;
        }

        default: break;
    }
}




/**
 * @brief 主页数字区域触摸点击回调
 */
static void homepage_touch_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    
    // 关键：获取触发该事件的输入设备
    lv_indev_t * indev = lv_event_get_indev(e);

    if(code == LV_EVENT_CLICKED) 
    {
        /* 只有当 indev != NULL 时，说明这是物理触摸产生真实事件。
           如果 indev == NULL，说明是 Tree_UI_Sel_Enter 内部手动模拟的事件，直接跳过，防止递归。
        */
        if(indev == NULL) return; 

        // 1. 如果点击的是电压设置区域
        if(obj == ui.HOME_PAGE_edit_Vset) {
            if(tree_VSet != NULL) {
                printf("[Touch] Physical Click -> Entering Voltage Set\n");
                Tree_UI_Sel_Enter(tree_VSet, 0);
            }
        }
        // 2. 电流区域逻辑同理
        else if(obj == ui.HOME_PAGE_edit_Iset_pos) {
            if(tree_ISet != NULL) {
                printf("[Touch] Physical Click -> Entering Current Set\n");
                Tree_UI_Sel_Enter(tree_ISet, 0);
            }
        }
        else if(obj == ui.HOME_PAGE_edit_Iset_neg) {
            if(tree_ISet_neg != NULL) {
                printf("[Touch] Physical Click -> Entering Current Set_neg\n");
                Tree_UI_Sel_Enter(tree_ISet_neg, 0);
            }
        }
    }
}


void HomePage_GroupCreate(void)
{
    
    {//初始化
    /* 1. 先创建屏幕对象 */
    setup_scr_HOME_PAGE(&ui);    
    /* 2. 调整父级关系 */
    lv_obj_set_parent(ui.HOME_PAGE_cont_Set, ui.Back_cont_back);
    lv_obj_set_parent(ui.HOME_PAGE_cont_menu, ui.Back_cont_back);
    lv_obj_set_parent(ui.HOME_PAGE_cont_read_back_value, ui.Back_cont_back);
    lv_obj_set_parent(ui.HOME_PAGE_cont_2, ui.Back_cont_back);
    /* 进入页面逻辑 */
    
    } 

    // --- 【新增：触摸联动代码】 ---
    
    // 给电压 Label 开启点击并绑定
    lv_obj_add_flag(ui.HOME_PAGE_edit_Vset, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui.HOME_PAGE_edit_Vset, homepage_touch_handler, LV_EVENT_CLICKED, NULL);

    // 给电流 Label 开启点击并绑定 (实现触摸版 F1)
    lv_obj_add_flag(ui.HOME_PAGE_edit_Iset_pos, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui.HOME_PAGE_edit_Iset_pos, homepage_touch_handler, LV_EVENT_CLICKED, NULL);    

    // 给电流 Label 开启点击并绑定 (实现触摸版 F1)
    lv_obj_add_flag(ui.HOME_PAGE_edit_Iset_neg, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui.HOME_PAGE_edit_Iset_neg, homepage_touch_handler, LV_EVENT_CLICKED, NULL);    
      
    // 2. 处理按钮：绑定进入菜单的逻辑
    if(ui.HOME_PAGE_btn_Menu != NULL) 
    {
        // 按钮默认就是 CLICKABLE 的，不需要额外 add_flag
        
        // 绑定回调函数（复用你之前的处理函数）
        lv_obj_add_event_cb(ui.HOME_PAGE_btn_Menu, homepage_menu_icon_handler, LV_EVENT_CLICKED, NULL);
        
        // 如果你的按钮是全透明盖在上面的，确保它没有被 Hidden 掉
        lv_obj_clear_flag(ui.HOME_PAGE_btn_Menu, LV_OBJ_FLAG_HIDDEN);
        
        // 提高扩展点击区域（可选）
        lv_obj_set_ext_click_area(ui.HOME_PAGE_btn_Menu, 10);
    }
    
    HomePage_Enter();

}

/**
 * @brief 核心函数：根据内部数据结构同步所有 UI 部件
 * @note  只有在非编辑状态下才会强制覆盖
 */
void HomePage_Refresh_All_Data(void)
{
    // 1. 刷新设置值 (只有在没被选中修改时才自动同步)
    // 电压设置
    if (!(lv_obj_get_state(ui.HOME_PAGE_edit_Vset) & LV_STATE_FOCUSED)) {
        Set_RefreshUI(ui.HOME_PAGE_edit_Vset, NULL, "%0.3f", PowerInfo.outSet.volt_set);
    }
       if (!(lv_obj_get_state(ui.HOME_PAGE_edit_Iset_pos) & LV_STATE_FOCUSED)) {
        Set_RefreshUI(ui.HOME_PAGE_edit_Iset_pos, NULL, "%0.4f", PowerInfo.outSet.curr_set);
    }
}

