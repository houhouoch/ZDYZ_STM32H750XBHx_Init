// --- Menu_Delays.c ---
#include "Menu_Delays.h"
void Menu_Delays_Enter(void) { lv_obj_clear_flag(ui.Menu_Delays_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Delays_Exit(void)  { lv_obj_add_flag(ui.Menu_Delays_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Delays_GroupCreate(void) {
    setup_scr_Menu_Delays(&ui);
    lv_obj_set_parent(ui.Menu_Delays_cont, ui.Back_cont_back);
    Menu_Delays_Exit();
}
