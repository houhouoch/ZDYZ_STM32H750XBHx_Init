#include "Menu_Group.h"
void Menu_Group_Enter(void) { lv_obj_clear_flag(ui.Menu_Group_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Group_Exit(void)  { lv_obj_add_flag(ui.Menu_Group_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Group_GroupCreate(void) {
    setup_scr_Menu_Group(&ui);
    lv_obj_set_parent(ui.Menu_Group_cont, ui.Back_cont_back);
    Menu_Group_Exit();
}
