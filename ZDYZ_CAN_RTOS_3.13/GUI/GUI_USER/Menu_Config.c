#include "Menu_Config.h"


void Menu_Config_Enter(void)
{
    lv_obj_clear_flag(ui.Menu_Config_cont,LV_OBJ_FLAG_HIDDEN);

}

void Menu_Config_Exit(void)
{       
    lv_obj_add_flag(ui.Menu_Config_cont,LV_OBJ_FLAG_HIDDEN);

}

void Menu_Config_GroupCreate(void)
{   
    {//初始化
    /* 1. 先创建屏幕对象 */
    setup_scr_Menu_Config(&ui);    
    /* 2. 调整父级关系 */
    lv_obj_set_parent(ui.Menu_Config_cont, ui.Back_cont_back);
    } 
    Menu_Config_Exit(); 
       
}








