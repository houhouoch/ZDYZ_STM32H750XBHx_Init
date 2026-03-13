#include "Menu_Recall.h"

void Menu_Recall_Enter(void)
{
    lv_obj_clear_flag(ui.Menu_Recall_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Recall_Exit(void)
{       
    lv_obj_add_flag(ui.Menu_Recall_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Recall_GroupCreate(void)
{   
    {
        setup_scr_Menu_Recall(&ui);    
        lv_obj_set_parent(ui.Menu_Recall_cont, ui.Back_cont_back);
    } 
    Menu_Recall_Exit(); 
}
