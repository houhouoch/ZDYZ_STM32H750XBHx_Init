#include "Menu_Meter.h"

void Menu_Meter_Enter(void)
{
    lv_obj_clear_flag(ui.Menu_Meter_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Meter_Exit(void)
{       
    lv_obj_add_flag(ui.Menu_Meter_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Meter_GroupCreate(void)
{   
    {
        setup_scr_Menu_Meter(&ui);    
        lv_obj_set_parent(ui.Menu_Meter_cont, ui.Back_cont_back);
    } 
    Menu_Meter_Exit(); 
}
