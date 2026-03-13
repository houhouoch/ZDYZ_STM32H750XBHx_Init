// --- Menu_Log.c ---
#include "Menu_Log.h"
void Menu_Log_Enter(void) { lv_obj_clear_flag(ui.Menu_Log_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Log_Exit(void)  { lv_obj_add_flag(ui.Menu_Log_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Log_GroupCreate(void) {
    setup_scr_Menu_Log(&ui);
    lv_obj_set_parent(ui.Menu_Log_cont, ui.Back_cont_back);
    Menu_Log_Exit();
}
