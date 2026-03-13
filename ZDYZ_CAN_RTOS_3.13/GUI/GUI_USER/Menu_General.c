// --- Menu_General.c ---
#include "Menu_General.h"
#include "Gui_Task.h"
void Menu_General_Enter(void) { lv_obj_clear_flag(ui.Menu_General_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_General_Exit(void)  { lv_obj_add_flag(ui.Menu_General_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_General_GroupCreate(void) {
    setup_scr_Menu_General(&ui);
    lv_obj_set_parent(ui.Menu_General_cont, ui.Back_cont_back);
    Menu_General_Exit();
}
