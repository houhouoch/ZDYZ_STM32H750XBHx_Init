/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_Menu_Group(lv_ui *ui)
{
    //Write codes Menu_Group
    ui->Menu_Group = lv_obj_create(NULL);
    lv_obj_set_size(ui->Menu_Group, 960, 240);
    lv_obj_set_scrollbar_mode(ui->Menu_Group, LV_SCROLLBAR_MODE_OFF);

    //Write style for Menu_Group, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Menu_Group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Menu_Group_cont
    ui->Menu_Group_cont = lv_obj_create(ui->Menu_Group);
    lv_obj_set_pos(ui->Menu_Group_cont, 105, 0);
    lv_obj_set_size(ui->Menu_Group_cont, 855, 240);
    lv_obj_set_scrollbar_mode(ui->Menu_Group_cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for Menu_Group_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Menu_Group_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Menu_Group_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Menu_Group_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Menu_Group_cont, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Menu_Group_cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Menu_Group_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Menu_Group_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Menu_Group_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Menu_Group_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Menu_Group_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Menu_Group.


    //Update current screen layout.
    lv_obj_update_layout(ui->Menu_Group);

}
