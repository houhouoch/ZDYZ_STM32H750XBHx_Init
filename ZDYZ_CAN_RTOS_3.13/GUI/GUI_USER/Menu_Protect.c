#include "Menu_Protect.h"

void Menu_Protect_Enter(void)
{
    lv_obj_clear_flag(ui.Menu_Protect_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Protect_Exit(void)
{       
    lv_obj_add_flag(ui.Menu_Protect_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Protect_GroupCreate(void)
{   
    {
        /* 1. 先创建屏幕对象 */
        setup_scr_Menu_Protect(&ui);    
        /* 2. 调整父级关系 */
        lv_obj_set_parent(ui.Menu_Protect_cont, ui.Back_cont_back);
    } 
    Menu_Protect_Exit(); 
}
