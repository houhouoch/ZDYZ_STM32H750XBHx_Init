// --- Menu_Date.c ---
#include "Menu_Date.h"
#include "Gui_Task.h"
void Menu_Date_Enter(void) { lv_obj_clear_flag(ui.Menu_Date_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Date_Exit(void)  { lv_obj_add_flag(ui.Menu_Date_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Date_GroupCreate(void) {
    setup_scr_Menu_Date(&ui);
    lv_obj_set_parent(ui.Menu_Date_cont, ui.Back_cont_back);
    Menu_Date_Exit();
}
