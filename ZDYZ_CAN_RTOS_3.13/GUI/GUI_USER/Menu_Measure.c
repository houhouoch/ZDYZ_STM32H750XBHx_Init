#include "Menu_Measure.h"

void Menu_Measure_Enter(void)
{
    lv_obj_clear_flag(ui.Menu_Measure_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Measure_Exit(void)
{       
    lv_obj_add_flag(ui.Menu_Measure_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Measure_GroupCreate(void)
{   
    {
        setup_scr_Menu_Measure(&ui);    
        lv_obj_set_parent(ui.Menu_Measure_cont, ui.Back_cont_back);
    } 
    Menu_Measure_Exit(); 
}
