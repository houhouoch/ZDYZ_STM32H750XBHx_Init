// --- Menu_Preference.c ---
#include "Menu_Preference.h"
void Menu_Preference_Enter(void) { lv_obj_clear_flag(ui.Menu_Preference_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Preference_Exit(void)  { lv_obj_add_flag(ui.Menu_Preference_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Preference_GroupCreate(void) {
    setup_scr_Menu_Preference(&ui);
    lv_obj_set_parent(ui.Menu_Preference_cont, ui.Back_cont_back);
    Menu_Preference_Exit();
}
