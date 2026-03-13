// --- Menu_Function.c ---
#include "Menu_Function.h"
void Menu_Function_Enter(void) { lv_obj_clear_flag(ui.Menu_Function_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Function_Exit(void)  { lv_obj_add_flag(ui.Menu_Function_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Function_GroupCreate(void) {
    setup_scr_Menu_Function(&ui);
    lv_obj_set_parent(ui.Menu_Function_cont, ui.Back_cont_back);
    Menu_Function_Exit();
}
