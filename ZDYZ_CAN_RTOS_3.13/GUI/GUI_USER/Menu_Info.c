// --- Menu_Info.c ---
#include "Menu_Info.h"
void Menu_Info_Enter(void) { lv_obj_clear_flag(ui.Menu_Info_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Info_Exit(void)  { lv_obj_add_flag(ui.Menu_Info_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Info_GroupCreate(void) {
    setup_scr_Menu_Info(&ui);
    lv_obj_set_parent(ui.Menu_Info_cont, ui.Back_cont_back);
    Menu_Info_Exit();
}
