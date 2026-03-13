#include "Menu_Save.h"

void Menu_Save_Enter(void)
{
    lv_obj_clear_flag(ui.Menu_Save_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Save_Exit(void)
{       
    lv_obj_add_flag(ui.Menu_Save_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Save_GroupCreate(void)
{   
    {
        setup_scr_Menu_Save(&ui);    
        lv_obj_set_parent(ui.Menu_Save_cont, ui.Back_cont_back);
    } 
    Menu_Save_Exit(); 
}
