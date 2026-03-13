// --- Menu_Admin.c ---
#include "Menu_Admin.h"
void Menu_Admin_Enter(void) { lv_obj_clear_flag(ui.Menu_Admin_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Admin_Exit(void)  { lv_obj_add_flag(ui.Menu_Admin_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Admin_GroupCreate(void) {
    setup_scr_Menu_Admin(&ui);
    lv_obj_set_parent(ui.Menu_Admin_cont, ui.Back_cont_back);
    Menu_Admin_Exit();
}
