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



void setup_scr_HOME_MENU(lv_ui *ui)
{
    //Write codes HOME_MENU
    ui->HOME_MENU = lv_obj_create(NULL);
    lv_obj_set_size(ui->HOME_MENU, 960, 240);
    lv_obj_set_scrollbar_mode(ui->HOME_MENU, LV_SCROLLBAR_MODE_OFF);

    //Write style for HOME_MENU, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_cont_menu_set
    ui->HOME_MENU_cont_menu_set = lv_obj_create(ui->HOME_MENU);
    lv_obj_set_pos(ui->HOME_MENU_cont_menu_set, 0, 0);
    lv_obj_set_size(ui->HOME_MENU_cont_menu_set, 105, 240);
    lv_obj_set_scrollbar_mode(ui->HOME_MENU_cont_menu_set, LV_SCROLLBAR_MODE_OFF);

    //Write style for HOME_MENU_cont_menu_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_cont_menu_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_cont_menu_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_cont_menu_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_MENU_cont_menu_set, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_MENU_cont_menu_set, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_cont_menu_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_cont_menu_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_cont_menu_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_cont_menu_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_cont_menu_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_home
    ui->HOME_MENU_btn_menu_home = lv_btn_create(ui->HOME_MENU_cont_menu_set);
    ui->HOME_MENU_btn_menu_home_label = lv_label_create(ui->HOME_MENU_btn_menu_home);
    lv_label_set_text(ui->HOME_MENU_btn_menu_home_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_home_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_home_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_home, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_home_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_home, 25, 173);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_home, 50, 50);

    //Write style for HOME_MENU_btn_menu_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_home, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_home, &_home_50x50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui->HOME_MENU_btn_menu_home, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_home, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_home, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_home, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_back
    ui->HOME_MENU_btn_menu_back = lv_btn_create(ui->HOME_MENU_cont_menu_set);
    ui->HOME_MENU_btn_menu_back_label = lv_label_create(ui->HOME_MENU_btn_menu_back);
    lv_label_set_text(ui->HOME_MENU_btn_menu_back_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_back_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_back_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_back, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_back_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_back, 21, 0);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_back, 60, 60);

    //Write style for HOME_MENU_btn_menu_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_back, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_back, &_back2_60x60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui->HOME_MENU_btn_menu_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_back, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu
    ui->HOME_MENU_label_menu = lv_label_create(ui->HOME_MENU_cont_menu_set);
    lv_label_set_text(ui->HOME_MENU_label_menu, "Menu");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu, 4, 96);
    lv_obj_set_size(ui->HOME_MENU_label_menu, 103, 51);

    //Write style for HOME_MENU_label_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_cont_menu_function
    ui->HOME_MENU_cont_menu_function = lv_obj_create(ui->HOME_MENU);
    lv_obj_set_pos(ui->HOME_MENU_cont_menu_function, 105, 0);
    lv_obj_set_size(ui->HOME_MENU_cont_menu_function, 855, 240);
    lv_obj_set_scrollbar_mode(ui->HOME_MENU_cont_menu_function, LV_SCROLLBAR_MODE_OFF);

    //Write style for HOME_MENU_cont_menu_function, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_cont_menu_function, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->HOME_MENU_cont_menu_function, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->HOME_MENU_cont_menu_function, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->HOME_MENU_cont_menu_function, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_cont_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_cont_menu_function, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_MENU_cont_menu_function, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_MENU_cont_menu_function, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_cont_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_cont_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_cont_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_cont_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_cont_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_tileview_1
    ui->HOME_MENU_tileview_1 = lv_tileview_create(ui->HOME_MENU_cont_menu_function);
    ui->HOME_MENU_tileview_1_tile = lv_tileview_add_tile(ui->HOME_MENU_tileview_1, 0, 0, LV_DIR_BOTTOM);
    lv_obj_set_pos(ui->HOME_MENU_tileview_1, 0, 0);
    lv_obj_set_size(ui->HOME_MENU_tileview_1, 855, 494);
    lv_obj_set_scrollbar_mode(ui->HOME_MENU_tileview_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for HOME_MENU_tileview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_tileview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_MENU_tileview_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_MENU_tileview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HOME_MENU_tileview_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_tileview_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_MENU_tileview_1, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_MENU_tileview_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_tileview_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



    //Write codes HOME_MENU_label_menu_Config
    ui->HOME_MENU_label_menu_Config = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Config, "Config");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Config, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Config, 18, 96);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Config, 106, 30);

    //Write style for HOME_MENU_label_menu_Config, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Config, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Config, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Config, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Config, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_config
    ui->HOME_MENU_btn_menu_config = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_config_label = lv_label_create(ui->HOME_MENU_btn_menu_config);
    lv_label_set_text(ui->HOME_MENU_btn_menu_config_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_config_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_config_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_config, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_config_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_config, 20, 2);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_config, 95, 95);

    //Write style for HOME_MENU_btn_menu_config, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_config, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_config, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_config, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_config, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_config, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_config, &_config2_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_config, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_protect
    ui->HOME_MENU_btn_menu_protect = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_protect_label = lv_label_create(ui->HOME_MENU_btn_menu_protect);
    lv_label_set_text(ui->HOME_MENU_btn_menu_protect_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_protect_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_protect_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_protect, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_protect_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_protect, 159, 4);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_protect, 95, 95);

    //Write style for HOME_MENU_btn_menu_protect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_protect, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_protect, &_protect_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_protect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_protect, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_protect, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_protect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_protect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Protect
    ui->HOME_MENU_label_menu_Protect = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Protect, "Protect");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Protect, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Protect, 160, 96);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Protect, 100, 26);

    //Write style for HOME_MENU_label_menu_Protect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Protect, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Protect, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Protect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Protect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Measure
    ui->HOME_MENU_label_menu_Measure = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Measure, "Measure");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Measure, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Measure, 296, 96);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Measure, 112, 25);

    //Write style for HOME_MENU_label_menu_Measure, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Measure, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Measure, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Measure, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Measure, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Trigger
    ui->HOME_MENU_label_menu_Trigger = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Trigger, "Trigger");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Trigger, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Trigger, 436, 92);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Trigger, 106, 30);

    //Write style for HOME_MENU_label_menu_Trigger, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Trigger, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Trigger, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Trigger, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Trigger, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Recall
    ui->HOME_MENU_label_menu_Recall = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Recall, "Recall");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Recall, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Recall, 586, 95);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Recall, 100, 25);

    //Write style for HOME_MENU_label_menu_Recall, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Recall, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Recall, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Recall, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Recall, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Save
    ui->HOME_MENU_label_menu_Save = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Save, "Save");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Save, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Save, 722, 96);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Save, 100, 26);

    //Write style for HOME_MENU_label_menu_Save, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Save, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Save, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Save, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Save, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Meter
    ui->HOME_MENU_label_menu_Meter = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Meter, "Meter\n");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Meter, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Meter, 22, 211);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Meter, 100, 21);

    //Write style for HOME_MENU_label_menu_Meter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Meter, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Meter, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Meter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Meter, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Recorder
    ui->HOME_MENU_label_menu_Recorder = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Recorder, "Recorder");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Recorder, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Recorder, 136, 211);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Recorder, 137, 23);

    //Write style for HOME_MENU_label_menu_Recorder, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Recorder, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Recorder, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Recorder, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Recorder, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Function
    ui->HOME_MENU_label_menu_Function = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Function, "Function");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Function, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Function, 291, 211);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Function, 119, 23);

    //Write style for HOME_MENU_label_menu_Function, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Function, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Function, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Function, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Function, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Delays
    ui->HOME_MENU_label_menu_Delays = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Delays, "Delays");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Delays, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Delays, 440, 210);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Delays, 100, 28);

    //Write style for HOME_MENU_label_menu_Delays, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Delays, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Delays, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Delays, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Delays, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Coupling
    ui->HOME_MENU_label_menu_Coupling = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Coupling, "Coupling\n");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Coupling, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Coupling, 575, 211);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Coupling, 112, 30);

    //Write style for HOME_MENU_label_menu_Coupling, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Coupling, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Coupling, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Coupling, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Coupling, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Group
    ui->HOME_MENU_label_menu_Group = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Group, "Group\n");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Group, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Group, 726, 211);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Group, 103, 34);

    //Write style for HOME_MENU_label_menu_Group, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Group, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Group, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Group, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Group, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_measure
    ui->HOME_MENU_btn_menu_measure = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_measure_label = lv_label_create(ui->HOME_MENU_btn_menu_measure);
    lv_label_set_text(ui->HOME_MENU_btn_menu_measure_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_measure_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_measure_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_measure, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_measure_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_measure, 299, 3);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_measure, 95, 95);

    //Write style for HOME_MENU_btn_menu_measure, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_measure, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_measure, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_measure, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_measure, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_measure, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_measure, &_measure2_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_measure, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_trigger
    ui->HOME_MENU_btn_menu_trigger = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_trigger_label = lv_label_create(ui->HOME_MENU_btn_menu_trigger);
    lv_label_set_text(ui->HOME_MENU_btn_menu_trigger_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_trigger_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_trigger_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_trigger, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_trigger_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_trigger, 440, 0);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_trigger, 100, 99);

    //Write style for HOME_MENU_btn_menu_trigger, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_trigger, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_trigger, &_Trigger2_100x99, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_trigger, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_trigger, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_trigger, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_trigger, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_trigger, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_recall
    ui->HOME_MENU_btn_menu_recall = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_recall_label = lv_label_create(ui->HOME_MENU_btn_menu_recall);
    lv_label_set_text(ui->HOME_MENU_btn_menu_recall_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_recall_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_recall_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_recall, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_recall_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_recall, 581, 0);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_recall, 99, 97);

    //Write style for HOME_MENU_btn_menu_recall, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_recall, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_recall, &_recall_99x97, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_recall, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_recall, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_recall, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_recall, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_recall, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_save
    ui->HOME_MENU_btn_menu_save = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_save_label = lv_label_create(ui->HOME_MENU_btn_menu_save);
    lv_label_set_text(ui->HOME_MENU_btn_menu_save_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_save_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_save_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_save, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_save_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_save, 725, 2);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_save, 98, 95);

    //Write style for HOME_MENU_btn_menu_save, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_save, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_save, &_save_98x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_save, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_save, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_save, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_save, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_save, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_meter
    ui->HOME_MENU_btn_menu_meter = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_meter_label = lv_label_create(ui->HOME_MENU_btn_menu_meter);
    lv_label_set_text(ui->HOME_MENU_btn_menu_meter_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_meter_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_meter_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_meter, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_meter_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_meter, 17, 121);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_meter, 99, 95);

    //Write style for HOME_MENU_btn_menu_meter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_meter, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_meter, &_meter_99x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_meter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_meter, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_meter, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_meter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_meter, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_recorder
    ui->HOME_MENU_btn_menu_recorder = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_recorder_label = lv_label_create(ui->HOME_MENU_btn_menu_recorder);
    lv_label_set_text(ui->HOME_MENU_btn_menu_recorder_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_recorder_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_recorder_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_recorder, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_recorder_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_recorder, 156, 115);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_recorder, 99, 99);

    //Write style for HOME_MENU_btn_menu_recorder, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_recorder, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_recorder, &_recorder_99x99, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_recorder, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_recorder, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_recorder, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_recorder, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_recorder, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_function
    ui->HOME_MENU_btn_menu_function = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_function_label = lv_label_create(ui->HOME_MENU_btn_menu_function);
    lv_label_set_text(ui->HOME_MENU_btn_menu_function_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_function_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_function_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_function, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_function_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_function, 297, 120);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_function, 100, 96);

    //Write style for HOME_MENU_btn_menu_function, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_function, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_function, &_function_100x96, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_function, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_function, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_function, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_function, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_function, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menua_delays
    ui->HOME_MENU_btn_menua_delays = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menua_delays_label = lv_label_create(ui->HOME_MENU_btn_menua_delays);
    lv_label_set_text(ui->HOME_MENU_btn_menua_delays_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menua_delays_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menua_delays_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menua_delays, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menua_delays_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menua_delays, 437, 117);
    lv_obj_set_size(ui->HOME_MENU_btn_menua_delays, 98, 95);

    //Write style for HOME_MENU_btn_menua_delays, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menua_delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menua_delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menua_delays, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menua_delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menua_delays, &_delays_98x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menua_delays, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menua_delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menua_delays, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menua_delays, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menua_delays, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menua_delays, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_coupling
    ui->HOME_MENU_btn_menu_coupling = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_coupling_label = lv_label_create(ui->HOME_MENU_btn_menu_coupling);
    lv_label_set_text(ui->HOME_MENU_btn_menu_coupling_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_coupling_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_coupling_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_coupling, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_coupling_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_coupling, 575, 114);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_coupling, 107, 104);

    //Write style for HOME_MENU_btn_menu_coupling, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_coupling, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_coupling, &_coupling_107x104, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_coupling, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_coupling, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_coupling, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_coupling, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_coupling, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_group
    ui->HOME_MENU_btn_menu_group = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_group_label = lv_label_create(ui->HOME_MENU_btn_menu_group);
    lv_label_set_text(ui->HOME_MENU_btn_menu_group_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_group_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_group_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_group, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_group_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_group, 723, 117);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_group, 100, 96);

    //Write style for HOME_MENU_btn_menu_group, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_group, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_group, &_group_100x96, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_group, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_group, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_group, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_group, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_group, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_line_1
    ui->HOME_MENU_line_1 = lv_line_create(ui->HOME_MENU_tileview_1_tile);
    static lv_point_t HOME_MENU_line_1[] = {{0, 0},{850, 0},};
    lv_line_set_points(ui->HOME_MENU_line_1, HOME_MENU_line_1, 2);
    lv_obj_set_pos(ui->HOME_MENU_line_1, -1, 240);
    lv_obj_set_size(ui->HOME_MENU_line_1, 981, 1);
    lv_obj_add_flag(ui->HOME_MENU_line_1, LV_OBJ_FLAG_HIDDEN);

    //Write style for HOME_MENU_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->HOME_MENU_line_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->HOME_MENU_line_1, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->HOME_MENU_line_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->HOME_MENU_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_general
    ui->HOME_MENU_btn_menu_general = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_general_label = lv_label_create(ui->HOME_MENU_btn_menu_general);
    lv_label_set_text(ui->HOME_MENU_btn_menu_general_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_general_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_general_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_general, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_general_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_general, 18, 246);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_general, 99, 95);

    //Write style for HOME_MENU_btn_menu_general, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_general, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_general, &_General_99x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_general, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_general, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_general, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_general, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_general, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_general
    ui->HOME_MENU_label_menu_general = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_general, "General");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_general, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_general, 17, 341);
    lv_obj_set_size(ui->HOME_MENU_label_menu_general, 100, 25);

    //Write style for HOME_MENU_label_menu_general, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_general, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_general, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_general, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_general, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_communication
    ui->HOME_MENU_btn_menu_communication = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_communication_label = lv_label_create(ui->HOME_MENU_btn_menu_communication);
    lv_label_set_text(ui->HOME_MENU_btn_menu_communication_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_communication_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_communication_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_communication, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_communication_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_communication, 724, 244);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_communication, 98, 99);

    //Write style for HOME_MENU_btn_menu_communication, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_communication, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_communication, &_communication_98x99, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_communication, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_communication, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_communication, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_communication, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_communication, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Communication
    ui->HOME_MENU_label_menu_Communication = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Communication, "Communi\ncation");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Communication, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Communication, 707, 341);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Communication, 138, 45);

    //Write style for HOME_MENU_label_menu_Communication, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Communication, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Communication, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Communication, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Communication, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_digital_io
    ui->HOME_MENU_btn_menu_digital_io = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_digital_io_label = lv_label_create(ui->HOME_MENU_btn_menu_digital_io);
    lv_label_set_text(ui->HOME_MENU_btn_menu_digital_io_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_digital_io_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_digital_io_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_digital_io, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_digital_io_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_digital_io, 156, 238);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_digital_io, 101, 100);

    //Write style for HOME_MENU_btn_menu_digital_io, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_digital_io, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_digital_io, &_digital_io3_101x100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_digital_io, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_digital_io, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_digital_io, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_digital_io, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_digital_io, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_preference
    ui->HOME_MENU_btn_menu_preference = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_preference_label = lv_label_create(ui->HOME_MENU_btn_menu_preference);
    lv_label_set_text(ui->HOME_MENU_btn_menu_preference_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_preference_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_preference_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_preference, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_preference_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_preference, 304, 246);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_preference, 98, 95);

    //Write style for HOME_MENU_btn_menu_preference, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_preference, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_preference, &_preference_98x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_preference, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_preference, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_preference, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_preference, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_preference, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Digital_io
    ui->HOME_MENU_label_menu_Digital_io = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Digital_io, "Digital IO");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Digital_io, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Digital_io, 155, 341);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Digital_io, 114, 28);

    //Write style for HOME_MENU_label_menu_Digital_io, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Digital_io, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Digital_io, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Digital_io, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Digital_io, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Preference
    ui->HOME_MENU_label_menu_Preference = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Preference, "Preference");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Preference, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Preference, 287, 344);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Preference, 132, 28);

    //Write style for HOME_MENU_label_menu_Preference, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Preference, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Preference, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Preference, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Preference, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_log
    ui->HOME_MENU_btn_menu_log = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_log_label = lv_label_create(ui->HOME_MENU_btn_menu_log);
    lv_label_set_text(ui->HOME_MENU_btn_menu_log_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_log_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_log_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_log, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_log_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_log, 443, 246);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_log, 99, 95);

    //Write style for HOME_MENU_btn_menu_log, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_log, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_log, &_log_99x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_log, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_log, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_log, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_log, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_log, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Log
    ui->HOME_MENU_label_menu_Log = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Log, "Log");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Log, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Log, 462, 344);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Log, 57, 28);

    //Write style for HOME_MENU_label_menu_Log, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Log, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Log, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Log, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Log, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_admin
    ui->HOME_MENU_btn_menu_admin = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_admin_label = lv_label_create(ui->HOME_MENU_btn_menu_admin);
    lv_label_set_text(ui->HOME_MENU_btn_menu_admin_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_admin_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_admin_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_admin, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_admin_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_admin, 583, 242);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_admin, 100, 99);

    //Write style for HOME_MENU_btn_menu_admin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_admin, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_admin, &_admin_100x99, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_admin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_admin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_admin, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_admin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_admin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Admin
    ui->HOME_MENU_label_menu_Admin = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Admin, "Admin");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Admin, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Admin, 584, 346);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Admin, 97, 28);

    //Write style for HOME_MENU_label_menu_Admin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Admin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Admin, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Admin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Admin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_info
    ui->HOME_MENU_btn_menu_info = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_info_label = lv_label_create(ui->HOME_MENU_btn_menu_info);
    lv_label_set_text(ui->HOME_MENU_btn_menu_info_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_info_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_info_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_info, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_info_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_info, 25, 370);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_info, 100, 95);

    //Write style for HOME_MENU_btn_menu_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_info, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_info, &_info_100x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_info, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_info, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_info, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Info
    ui->HOME_MENU_label_menu_Info = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Info, "Info");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Info, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Info, 42, 463);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Info, 61, 28);

    //Write style for HOME_MENU_label_menu_Info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Info, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Info, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Info, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_energy
    ui->HOME_MENU_btn_menu_energy = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_energy_label = lv_label_create(ui->HOME_MENU_btn_menu_energy);
    lv_label_set_text(ui->HOME_MENU_btn_menu_energy_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_energy_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_energy_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_energy, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_energy_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_energy, 165, 370);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_energy, 97, 93);

    //Write style for HOME_MENU_btn_menu_energy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_energy, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_energy, &_Energy_97x93, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_energy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_energy, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_energy, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_energy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_energy, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Energy
    ui->HOME_MENU_label_menu_Energy = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Energy, "Energy");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Energy, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Energy, 163, 458);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Energy, 97, 30);

    //Write style for HOME_MENU_label_menu_Energy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Energy, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Energy, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Energy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Energy, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_date
    ui->HOME_MENU_btn_menu_date = lv_btn_create(ui->HOME_MENU_tileview_1_tile);
    ui->HOME_MENU_btn_menu_date_label = lv_label_create(ui->HOME_MENU_btn_menu_date);
    lv_label_set_text(ui->HOME_MENU_btn_menu_date_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_date_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_date_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_date, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_date_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_date, 307, 370);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_date, 99, 94);

    //Write style for HOME_MENU_btn_menu_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_date, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_date, &_date_99x94, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_date, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_date, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Date
    ui->HOME_MENU_label_menu_Date = lv_label_create(ui->HOME_MENU_tileview_1_tile);
    lv_label_set_text(ui->HOME_MENU_label_menu_Date, "Date");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Date, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Date, 327, 462);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Date, 65, 28);

    //Write style for HOME_MENU_label_menu_Date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Date, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Date, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_1
    ui->HOME_MENU_label_1 = lv_label_create(ui->HOME_MENU);
    lv_label_set_text(ui->HOME_MENU_label_1, "Energy");
    lv_label_set_long_mode(ui->HOME_MENU_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_1, 164, 478);
    lv_obj_set_size(ui->HOME_MENU_label_1, 97, 28);

    //Write style for HOME_MENU_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_1, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of HOME_MENU.


    //Update current screen layout.
    lv_obj_update_layout(ui->HOME_MENU);

}
