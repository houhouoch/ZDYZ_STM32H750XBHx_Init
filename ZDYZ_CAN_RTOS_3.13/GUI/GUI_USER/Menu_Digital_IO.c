// --- Menu_Digital_IO.c ---
#include "Menu_Digital_IO.h"
void Menu_Digital_IO_Enter(void) { lv_obj_clear_flag(ui.Menu_Digital_IO_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Digital_IO_Exit(void)  { lv_obj_add_flag(ui.Menu_Digital_IO_cont, LV_OBJ_FLAG_HIDDEN); }
void Menu_Digital_IO_GroupCreate(void) {
    setup_scr_Menu_Digital_IO(&ui);
    lv_obj_set_parent(ui.Menu_Digital_IO_cont, ui.Back_cont_back);
    Menu_Digital_IO_Exit();
}
