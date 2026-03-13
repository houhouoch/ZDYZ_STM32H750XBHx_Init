// --- Menu_Energy.c ---
#include "Menu_Energy.h"
void Menu_Energy_Enter(void) { lv_obj_clear_flag(ui.Menu_Energy_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Energy_Exit(void)  { lv_obj_add_flag(ui.Menu_Energy_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Energy_GroupCreate(void) {
    setup_scr_Menu_Energy(&ui);
    lv_obj_set_parent(ui.Menu_Energy_cont, ui.Back_cont_back);
    Menu_Energy_Exit();
}
