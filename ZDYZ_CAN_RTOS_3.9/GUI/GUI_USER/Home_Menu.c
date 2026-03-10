#include "Home_Menu.h"
#include "Gui_Task.h"
#include "HomePage_LED.h"
#include "./User/power_interface.h"


void Home_Menu_Enter(void)
{
    lv_obj_clear_flag(ui.HOME_MENU_cont_menu_function,LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui.HOME_MENU_cont_menu_set,LV_OBJ_FLAG_HIDDEN);

  
}
void Home_Menu_Exit(void)
{       
    lv_obj_add_flag(ui.HOME_MENU_cont_menu_function,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui.HOME_MENU_cont_menu_set,LV_OBJ_FLAG_HIDDEN);
  
}

void Home_Menu_GroupCreate(void)
{
    
    {//初始化
    /* 1. 先创建屏幕对象 */
    setup_scr_HOME_MENU(&ui);    
    /* 2. 调整父级关系 */
    lv_obj_set_parent(ui.HOME_MENU_cont_menu_function, ui.Back_cont_back);
    lv_obj_set_parent(ui.HOME_MENU_cont_menu_set, ui.Back_cont_back);
    } 

    Home_Menu_Exit();        
}

/**
 * @brief 核心函数：根据内部数据结构同步所有 UI 部件
 * @note  只有在非编辑状态下才会强制覆盖
 */
void Home_Menu_Refresh_All_Data(void)
{

}










