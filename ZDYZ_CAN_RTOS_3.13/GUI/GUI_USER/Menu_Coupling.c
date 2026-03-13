// --- Menu_Coupling.c ---
#include "Menu_Coupling.h"
void Menu_Coupling_Enter(void) { lv_obj_clear_flag(ui.Menu_Coupling_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Coupling_Exit(void)  { lv_obj_add_flag(ui.Menu_Coupling_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Coupling_GroupCreate(void) {
    setup_scr_Menu_Coupling(&ui);
    lv_obj_set_parent(ui.Menu_Coupling_cont, ui.Back_cont_back);
    Menu_Coupling_Exit();
}
