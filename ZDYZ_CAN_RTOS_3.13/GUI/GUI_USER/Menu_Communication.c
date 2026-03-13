// --- Menu_Communication.c ---
#include "Menu_Communication.h"
void Menu_Communication_Enter(void) { lv_obj_clear_flag(ui.Menu_Communication_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Communication_Exit(void)  { lv_obj_add_flag(ui.Menu_Communication_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Communication_GroupCreate(void) {
    setup_scr_Menu_Communication(&ui);
    lv_obj_set_parent(ui.Menu_Communication_cont, ui.Back_cont_back);
    Menu_Communication_Exit();
}
