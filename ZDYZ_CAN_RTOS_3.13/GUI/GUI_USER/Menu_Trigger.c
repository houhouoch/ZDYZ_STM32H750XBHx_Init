#include "Menu_Trigger.h"

void Menu_Trigger_Enter(void)
{
    lv_obj_clear_flag(ui.Menu_Trigger_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Trigger_Exit(void)
{       
    lv_obj_add_flag(ui.Menu_Trigger_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Trigger_GroupCreate(void)
{   
    {
        setup_scr_Menu_Trigger(&ui);    
        lv_obj_set_parent(ui.Menu_Trigger_cont, ui.Back_cont_back);
    } 
    Menu_Trigger_Exit(); 
}
