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



void setup_scr_Back(lv_ui *ui)
{
    //Write codes Back
    ui->Back = lv_obj_create(NULL);
    lv_obj_set_size(ui->Back, 960, 240);
    lv_obj_set_scrollbar_mode(ui->Back, LV_SCROLLBAR_MODE_OFF);

    //Write style for Back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Back_cont_back
    ui->Back_cont_back = lv_obj_create(ui->Back);
    lv_obj_set_pos(ui->Back_cont_back, 0, 0);
    lv_obj_set_size(ui->Back_cont_back, 960, 240);
    lv_obj_set_scrollbar_mode(ui->Back_cont_back, LV_SCROLLBAR_MODE_OFF);

    //Write style for Back_cont_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Back_cont_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Back_cont_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Back_cont_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Back_cont_back, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Back_cont_back, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Back_cont_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Back_cont_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Back_cont_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Back_cont_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Back_cont_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Back_img_Logo
    ui->Back_img_Logo = lv_img_create(ui->Back_cont_back);
    lv_obj_add_flag(ui->Back_img_Logo, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Back_img_Logo, &_Logo_alpha_569x159);
    lv_img_set_pivot(ui->Back_img_Logo, 50,50);
    lv_img_set_angle(ui->Back_img_Logo, 0);
    lv_obj_set_pos(ui->Back_img_Logo, 208, 35);
    lv_obj_set_size(ui->Back_img_Logo, 569, 159);

    //Write style for Back_img_Logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Back_img_Logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Back_img_Logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Back_img_Logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Back_img_Logo, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Back.


    //Update current screen layout.
    lv_obj_update_layout(ui->Back);

}
