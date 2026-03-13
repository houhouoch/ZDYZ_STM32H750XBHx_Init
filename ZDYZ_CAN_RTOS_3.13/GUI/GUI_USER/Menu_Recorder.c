#include "Menu_Recorder.h"

void Menu_Recorder_Enter(void)
{
    lv_obj_clear_flag(ui.Menu_Recorder_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Recorder_Exit(void)
{       
    lv_obj_add_flag(ui.Menu_Recorder_cont, LV_OBJ_FLAG_HIDDEN);
}

void Menu_Recorder_GroupCreate(void)
{   
    {
        setup_scr_Menu_Recorder(&ui);    
        lv_obj_set_parent(ui.Menu_Recorder_cont, ui.Back_cont_back);
    } 
    Menu_Recorder_Exit(); 
}
