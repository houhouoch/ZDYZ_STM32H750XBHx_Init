#include "HomePage.h"
#include "Gui_Task.h"
#include "HomePage_LED.h"

void HomePage_Enter(void)
{
    lv_obj_clear_flag(ui.HOME_PAGE_cont_1,LV_OBJ_FLAG_HIDDEN);
    ui_led_start(ui.HOME_PAGE_led_1);
    //ui_led_start(ui.HOME_PAGE_led_2);
  
}
void HomePage_Exit(void)
{
    
    lv_obj_add_flag(ui.HOME_PAGE_cont_1,LV_OBJ_FLAG_HIDDEN);
    // 手动停止该对象的所有动画，节省系统开销
   // lv_anim_del(ui.HOME_PAGE_led_1, NULL);
  
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

