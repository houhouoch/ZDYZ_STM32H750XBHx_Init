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

    //Write codes HOME_MENU_shared_sidebar
    ui->HOME_MENU_shared_sidebar = lv_label_create(ui->HOME_MENU_cont_menu_set);
    lv_label_set_text(ui->HOME_MENU_shared_sidebar, "");
    lv_label_set_long_mode(ui->HOME_MENU_shared_sidebar, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_shared_sidebar, 0, 89);
    lv_obj_set_size(ui->HOME_MENU_shared_sidebar, 100, 57);

    //Write style for HOME_MENU_shared_sidebar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_shared_sidebar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_shared_sidebar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_shared_sidebar, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_shared_sidebar, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_shared_sidebar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_shared_sidebar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_shared_sidebar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_shared_sidebar, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_shared_sidebar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_shared_sidebar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_shared_sidebar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_shared_sidebar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_shared_sidebar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_shared_sidebar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu
    ui->HOME_MENU_label_menu = lv_label_create(ui->HOME_MENU_cont_menu_set);
    lv_label_set_text(ui->HOME_MENU_label_menu, "Menu");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu, 0, 99);
    lv_obj_set_size(ui->HOME_MENU_label_menu, 105, 45);

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

    //Write codes HOME_MENU_img_menu_back
    ui->HOME_MENU_img_menu_back = lv_img_create(ui->HOME_MENU_cont_menu_set);
    lv_obj_add_flag(ui->HOME_MENU_img_menu_back, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_menu_back, &_back1_alpha_60x60);
    lv_img_set_pivot(ui->HOME_MENU_img_menu_back, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_menu_back, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_menu_back, 23, 12);
    lv_obj_set_size(ui->HOME_MENU_img_menu_back, 60, 60);

    //Write style for HOME_MENU_img_menu_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_menu_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->HOME_MENU_img_menu_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_menu_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_img_menu_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_menu_back, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_menu_home
    ui->HOME_MENU_img_menu_home = lv_img_create(ui->HOME_MENU_cont_menu_set);
    lv_obj_add_flag(ui->HOME_MENU_img_menu_home, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_menu_home, &_home_alpha_60x60);
    lv_img_set_pivot(ui->HOME_MENU_img_menu_home, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_menu_home, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_menu_home, 23, 166);
    lv_obj_set_size(ui->HOME_MENU_img_menu_home, 60, 60);

    //Write style for HOME_MENU_img_menu_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_menu_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->HOME_MENU_img_menu_home, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_menu_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_img_menu_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_menu_home, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_home
    ui->HOME_MENU_btn_menu_home = lv_btn_create(ui->HOME_MENU_cont_menu_set);
    ui->HOME_MENU_btn_menu_home_label = lv_label_create(ui->HOME_MENU_btn_menu_home);
    lv_label_set_text(ui->HOME_MENU_btn_menu_home_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_home_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_home_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_home, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_home_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_home, 0, 166);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_home, 105, 69);

    //Write style for HOME_MENU_btn_menu_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_home, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_home, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_home, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
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
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_back, 0, 0);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_back, 105, 67);

    //Write style for HOME_MENU_btn_menu_back, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_back, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_back, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_back, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_back, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_back, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_back, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_cont_menu_function
    ui->HOME_MENU_cont_menu_function = lv_obj_create(ui->HOME_MENU);
    lv_obj_set_pos(ui->HOME_MENU_cont_menu_function, 105, 0);
    lv_obj_set_size(ui->HOME_MENU_cont_menu_function, 855, 240);
    lv_obj_set_scrollbar_mode(ui->HOME_MENU_cont_menu_function, LV_SCROLLBAR_MODE_OFF);

    //Write style for HOME_MENU_cont_menu_function, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_cont_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_cont_menu_function, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->HOME_MENU_cont_menu_function, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->HOME_MENU_cont_menu_function, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->HOME_MENU_cont_menu_function, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_cont_menu_function, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_MENU_cont_menu_function, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_MENU_cont_menu_function, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_cont_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_cont_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_cont_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_cont_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_cont_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_cont_1
    ui->HOME_MENU_cont_1 = lv_obj_create(ui->HOME_MENU_cont_menu_function);
    lv_obj_set_pos(ui->HOME_MENU_cont_1, 0, 0);
    lv_obj_set_size(ui->HOME_MENU_cont_1, 855, 497);
    lv_obj_set_scrollbar_mode(ui->HOME_MENU_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for HOME_MENU_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_MENU_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_MENU_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Config
    ui->HOME_MENU_label_menu_Config = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Config, "Config");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Config, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Config, 17, 91);
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

    //Write codes HOME_MENU_label_menu_Protect
    ui->HOME_MENU_label_menu_Protect = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Protect, "Protect");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Protect, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Protect, 160, 91);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Protect, 100, 26);

    //Write style for HOME_MENU_label_menu_Protect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Protect, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Protect, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Protect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Protect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_config
    ui->HOME_MENU_btn_menu_config = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_config_label = lv_label_create(ui->HOME_MENU_btn_menu_config);
    lv_label_set_text(ui->HOME_MENU_btn_menu_config_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_config_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_config_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_config, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_config_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_config, 21, 0);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_config, 95, 95);

    //Write style for HOME_MENU_btn_menu_config, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_config, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_config, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_config, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_config, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_config, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_config, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_config, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_protect
    ui->HOME_MENU_btn_menu_protect = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_protect_label = lv_label_create(ui->HOME_MENU_btn_menu_protect);
    lv_label_set_text(ui->HOME_MENU_btn_menu_protect_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_protect_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_protect_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_protect, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_protect_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_protect, 163, 0);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_protect, 95, 95);

    //Write style for HOME_MENU_btn_menu_protect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_protect, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_protect, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_protect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_protect, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_protect, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_protect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_protect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Measure
    ui->HOME_MENU_label_menu_Measure = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Measure, "Measure");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Measure, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Measure, 296, 91);
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
    ui->HOME_MENU_label_menu_Trigger = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Trigger, "Trigger");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Trigger, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Trigger, 444, 91);
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
    ui->HOME_MENU_label_menu_Recall = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Recall, "Recall");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Recall, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Recall, 586, 91);
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
    ui->HOME_MENU_label_menu_Save = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Save, "Save");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Save, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Save, 738, 91);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Save, 88, 26);

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
    ui->HOME_MENU_label_menu_Meter = lv_label_create(ui->HOME_MENU_cont_1);
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
    ui->HOME_MENU_label_menu_Recorder = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Recorder, "Recorder");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Recorder, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Recorder, 136, 210);
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
    ui->HOME_MENU_label_menu_Function = lv_label_create(ui->HOME_MENU_cont_1);
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
    ui->HOME_MENU_label_menu_Delays = lv_label_create(ui->HOME_MENU_cont_1);
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
    ui->HOME_MENU_label_menu_Coupling = lv_label_create(ui->HOME_MENU_cont_1);
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
    ui->HOME_MENU_label_menu_Group = lv_label_create(ui->HOME_MENU_cont_1);
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
    ui->HOME_MENU_btn_menu_measure = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_measure_label = lv_label_create(ui->HOME_MENU_btn_menu_measure);
    lv_label_set_text(ui->HOME_MENU_btn_menu_measure_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_measure_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_measure_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_measure, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_measure_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_measure, 305, 0);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_measure, 95, 95);

    //Write style for HOME_MENU_btn_menu_measure, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_measure, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_measure, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_measure, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_measure, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_measure, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_measure, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_measure, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_trigger
    ui->HOME_MENU_btn_menu_trigger = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_trigger_label = lv_label_create(ui->HOME_MENU_btn_menu_trigger);
    lv_label_set_text(ui->HOME_MENU_btn_menu_trigger_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_trigger_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_trigger_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_trigger, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_trigger_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_trigger, 447, 0);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_trigger, 95, 95);

    //Write style for HOME_MENU_btn_menu_trigger, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_trigger, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_trigger, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_trigger, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_trigger, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_trigger, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_trigger, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_trigger, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_recall
    ui->HOME_MENU_btn_menu_recall = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_recall_label = lv_label_create(ui->HOME_MENU_btn_menu_recall);
    lv_label_set_text(ui->HOME_MENU_btn_menu_recall_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_recall_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_recall_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_recall, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_recall_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_recall, 589, 0);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_recall, 95, 95);

    //Write style for HOME_MENU_btn_menu_recall, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_recall, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_recall, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_recall, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_recall, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_recall, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_recall, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_recall, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_save
    ui->HOME_MENU_btn_menu_save = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_save_label = lv_label_create(ui->HOME_MENU_btn_menu_save);
    lv_label_set_text(ui->HOME_MENU_btn_menu_save_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_save_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_save_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_save, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_save_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_save, 731, 0);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_save, 95, 95);

    //Write style for HOME_MENU_btn_menu_save, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_save, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_save, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_save, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_save, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_save, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_save, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_save, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_meter
    ui->HOME_MENU_btn_menu_meter = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_meter_label = lv_label_create(ui->HOME_MENU_btn_menu_meter);
    lv_label_set_text(ui->HOME_MENU_btn_menu_meter_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_meter_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_meter_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_meter, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_meter_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_meter, 21, 117);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_meter, 95, 95);

    //Write style for HOME_MENU_btn_menu_meter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_meter, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_meter, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_meter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_meter, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_meter, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_meter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_meter, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_recorder
    ui->HOME_MENU_btn_menu_recorder = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_recorder_label = lv_label_create(ui->HOME_MENU_btn_menu_recorder);
    lv_label_set_text(ui->HOME_MENU_btn_menu_recorder_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_recorder_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_recorder_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_recorder, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_recorder_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_recorder, 163, 117);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_recorder, 95, 95);

    //Write style for HOME_MENU_btn_menu_recorder, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_recorder, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_recorder, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_recorder, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_recorder, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_recorder, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_recorder, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_recorder, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_function
    ui->HOME_MENU_btn_menu_function = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_function_label = lv_label_create(ui->HOME_MENU_btn_menu_function);
    lv_label_set_text(ui->HOME_MENU_btn_menu_function_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_function_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_function_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_function, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_function_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_function, 305, 117);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_function, 95, 95);

    //Write style for HOME_MENU_btn_menu_function, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_function, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_function, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_function, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_function, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_function, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_function, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_function, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menua_delays
    ui->HOME_MENU_btn_menua_delays = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menua_delays_label = lv_label_create(ui->HOME_MENU_btn_menua_delays);
    lv_label_set_text(ui->HOME_MENU_btn_menua_delays_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menua_delays_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menua_delays_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menua_delays, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menua_delays_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menua_delays, 447, 117);
    lv_obj_set_size(ui->HOME_MENU_btn_menua_delays, 95, 95);

    //Write style for HOME_MENU_btn_menua_delays, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menua_delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menua_delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menua_delays, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menua_delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menua_delays, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menua_delays, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menua_delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menua_delays, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menua_delays, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menua_delays, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menua_delays, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_coupling
    ui->HOME_MENU_btn_menu_coupling = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_coupling_label = lv_label_create(ui->HOME_MENU_btn_menu_coupling);
    lv_label_set_text(ui->HOME_MENU_btn_menu_coupling_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_coupling_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_coupling_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_coupling, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_coupling_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_coupling, 589, 117);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_coupling, 95, 95);

    //Write style for HOME_MENU_btn_menu_coupling, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_coupling, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_coupling, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_coupling, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_coupling, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_coupling, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_coupling, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_coupling, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_group
    ui->HOME_MENU_btn_menu_group = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_group_label = lv_label_create(ui->HOME_MENU_btn_menu_group);
    lv_label_set_text(ui->HOME_MENU_btn_menu_group_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_group_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_group_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_group, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_group_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_group, 731, 118);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_group, 95, 95);

    //Write style for HOME_MENU_btn_menu_group, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_group, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_group, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_group, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_group, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_group, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_group, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_group, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_general
    ui->HOME_MENU_btn_menu_general = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_general_label = lv_label_create(ui->HOME_MENU_btn_menu_general);
    lv_label_set_text(ui->HOME_MENU_btn_menu_general_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_general_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_general_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_general, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_general_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_general, 20, 236);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_general, 95, 95);

    //Write style for HOME_MENU_btn_menu_general, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_general, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_general, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_general, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_general, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_general, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_general, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_general, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_general
    ui->HOME_MENU_label_menu_general = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_general, "General");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_general, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_general, 17, 328);
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
    ui->HOME_MENU_btn_menu_communication = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_communication_label = lv_label_create(ui->HOME_MENU_btn_menu_communication);
    lv_label_set_text(ui->HOME_MENU_btn_menu_communication_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_communication_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_communication_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_communication, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_communication_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_communication, 731, 237);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_communication, 95, 95);

    //Write style for HOME_MENU_btn_menu_communication, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_communication, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_communication, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_communication, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_communication, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_communication, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_communication, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_communication, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Communication
    ui->HOME_MENU_label_menu_Communication = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Communication, "Communi\ncation");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Communication, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Communication, 707, 328);
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
    ui->HOME_MENU_btn_menu_digital_io = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_digital_io_label = lv_label_create(ui->HOME_MENU_btn_menu_digital_io);
    lv_label_set_text(ui->HOME_MENU_btn_menu_digital_io_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_digital_io_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_digital_io_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_digital_io, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_digital_io_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_digital_io, 163, 237);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_digital_io, 95, 95);

    //Write style for HOME_MENU_btn_menu_digital_io, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_digital_io, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_digital_io, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_digital_io, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_digital_io, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_digital_io, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_digital_io, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_digital_io, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_preference
    ui->HOME_MENU_btn_menu_preference = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_preference_label = lv_label_create(ui->HOME_MENU_btn_menu_preference);
    lv_label_set_text(ui->HOME_MENU_btn_menu_preference_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_preference_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_preference_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_preference, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_preference_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_preference, 305, 237);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_preference, 95, 95);

    //Write style for HOME_MENU_btn_menu_preference, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_preference, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_preference, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_preference, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_preference, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_preference, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_preference, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_preference, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Digital_io
    ui->HOME_MENU_label_menu_Digital_io = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Digital_io, "Digital IO");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Digital_io, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Digital_io, 154, 328);
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
    ui->HOME_MENU_label_menu_Preference = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Preference, "Preference");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Preference, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Preference, 289, 328);
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
    ui->HOME_MENU_btn_menu_log = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_log_label = lv_label_create(ui->HOME_MENU_btn_menu_log);
    lv_label_set_text(ui->HOME_MENU_btn_menu_log_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_log_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_log_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_log, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_log_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_log, 447, 237);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_log, 95, 95);

    //Write style for HOME_MENU_btn_menu_log, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_log, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_log, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_log, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_log, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_log, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_log, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_log, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Log
    ui->HOME_MENU_label_menu_Log = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Log, "Log");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Log, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Log, 465, 328);
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
    ui->HOME_MENU_btn_menu_admin = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_admin_label = lv_label_create(ui->HOME_MENU_btn_menu_admin);
    lv_label_set_text(ui->HOME_MENU_btn_menu_admin_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_admin_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_admin_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_admin, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_admin_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_admin, 589, 237);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_admin, 95, 95);

    //Write style for HOME_MENU_btn_menu_admin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_admin, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_admin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_admin, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_admin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_admin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_admin, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_admin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Admin
    ui->HOME_MENU_label_menu_Admin = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Admin, "Admin");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Admin, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Admin, 593, 328);
    lv_obj_set_size(ui->HOME_MENU_label_menu_Admin, 97, 28);

    //Write style for HOME_MENU_label_menu_Admin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_label_menu_Admin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_label_menu_Admin, &lv_font_SourceHanSerifSC_Regular_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_label_menu_Admin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_label_menu_Admin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_MENU_label_menu_Admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_btn_menu_info
    ui->HOME_MENU_btn_menu_info = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_info_label = lv_label_create(ui->HOME_MENU_btn_menu_info);
    lv_label_set_text(ui->HOME_MENU_btn_menu_info_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_info_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_info_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_info, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_info_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_info, 21, 360);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_info, 95, 95);

    //Write style for HOME_MENU_btn_menu_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_info, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_info, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_info, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_info, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_info, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Info
    ui->HOME_MENU_label_menu_Info = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Info, "Info");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Info, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Info, 43, 451);
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
    ui->HOME_MENU_btn_menu_energy = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_energy_label = lv_label_create(ui->HOME_MENU_btn_menu_energy);
    lv_label_set_text(ui->HOME_MENU_btn_menu_energy_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_energy_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_energy_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_energy, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_energy_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_energy, 163, 360);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_energy, 95, 95);

    //Write style for HOME_MENU_btn_menu_energy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_energy, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_energy, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_energy, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_energy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_energy, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_energy, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_energy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Energy
    ui->HOME_MENU_label_menu_Energy = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Energy, "Energy");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Energy, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Energy, 164, 451);
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
    ui->HOME_MENU_btn_menu_date = lv_btn_create(ui->HOME_MENU_cont_1);
    ui->HOME_MENU_btn_menu_date_label = lv_label_create(ui->HOME_MENU_btn_menu_date);
    lv_label_set_text(ui->HOME_MENU_btn_menu_date_label, "");
    lv_label_set_long_mode(ui->HOME_MENU_btn_menu_date_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_MENU_btn_menu_date_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_MENU_btn_menu_date, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_MENU_btn_menu_date_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_MENU_btn_menu_date, 305, 360);
    lv_obj_set_size(ui->HOME_MENU_btn_menu_date, 95, 95);

    //Write style for HOME_MENU_btn_menu_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_MENU_btn_menu_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_MENU_btn_menu_date, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_MENU_btn_menu_date, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_MENU_btn_menu_date, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_MENU_btn_menu_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_MENU_btn_menu_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_MENU_btn_menu_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HOME_MENU_btn_menu_date, &_base3_95x95, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HOME_MENU_btn_menu_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HOME_MENU_btn_menu_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_MENU_btn_menu_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_label_menu_Date
    ui->HOME_MENU_label_menu_Date = lv_label_create(ui->HOME_MENU_cont_1);
    lv_label_set_text(ui->HOME_MENU_label_menu_Date, "Date");
    lv_label_set_long_mode(ui->HOME_MENU_label_menu_Date, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_MENU_label_menu_Date, 328, 451);
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

    //Write codes HOME_MENU_img_protect
    ui->HOME_MENU_img_protect = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_protect, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_protect, &_protect_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_protect, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_protect, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_protect, 176, 12);
    lv_obj_set_size(ui->HOME_MENU_img_protect, 70, 70);

    //Write style for HOME_MENU_img_protect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_protect, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_protect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_protect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_measure
    ui->HOME_MENU_img_measure = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_measure, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_measure, &_measure_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_measure, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_measure, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_measure, 318, 11);
    lv_obj_set_size(ui->HOME_MENU_img_measure, 70, 70);

    //Write style for HOME_MENU_img_measure, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_measure, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_measure, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_measure, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_trigger
    ui->HOME_MENU_img_trigger = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_trigger, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_trigger, &_trigger_alone_2_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_trigger, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_trigger, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_trigger, 459, 10);
    lv_obj_set_size(ui->HOME_MENU_img_trigger, 70, 70);

    //Write style for HOME_MENU_img_trigger, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_trigger, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_trigger, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_trigger, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_save
    ui->HOME_MENU_img_save = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_save, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_save, &_save_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_save, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_save, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_save, 745, 11);
    lv_obj_set_size(ui->HOME_MENU_img_save, 70, 70);

    //Write style for HOME_MENU_img_save, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_save, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_save, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_save, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_recall
    ui->HOME_MENU_img_recall = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_recall, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_recall, &_recall_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_recall, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_recall, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_recall, 601, 10);
    lv_obj_set_size(ui->HOME_MENU_img_recall, 70, 70);

    //Write style for HOME_MENU_img_recall, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_recall, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_recall, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_recall, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_recorder
    ui->HOME_MENU_img_recorder = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_recorder, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_recorder, &_recoder_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_recorder, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_recorder, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_recorder, 175, 129);
    lv_obj_set_size(ui->HOME_MENU_img_recorder, 70, 70);

    //Write style for HOME_MENU_img_recorder, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_recorder, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_recorder, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_recorder, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_function
    ui->HOME_MENU_img_function = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_function, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_function, &_Function_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_function, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_function, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_function, 317, 128);
    lv_obj_set_size(ui->HOME_MENU_img_function, 70, 70);

    //Write style for HOME_MENU_img_function, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_function, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_function, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_function, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_delays
    ui->HOME_MENU_img_delays = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_delays, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_delays, &_delays_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_delays, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_delays, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_delays, 460, 129);
    lv_obj_set_size(ui->HOME_MENU_img_delays, 70, 70);

    //Write style for HOME_MENU_img_delays, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_delays, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_delays, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_delays, 221, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->HOME_MENU_img_delays, lv_color_hex(0x40e61a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_delays, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_coupling
    ui->HOME_MENU_img_coupling = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_coupling, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_coupling, &_coupling_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_coupling, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_coupling, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_coupling, 600, 128);
    lv_obj_set_size(ui->HOME_MENU_img_coupling, 70, 70);

    //Write style for HOME_MENU_img_coupling, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_coupling, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_coupling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_coupling, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_group
    ui->HOME_MENU_img_group = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_group, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_group, &_group_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_group, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_group, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_group, 743, 130);
    lv_obj_set_size(ui->HOME_MENU_img_group, 70, 70);

    //Write style for HOME_MENU_img_group, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_group, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_group, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_group, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_general
    ui->HOME_MENU_img_general = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_general, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_general, &_general_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_general, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_general, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_general, 33, 247);
    lv_obj_set_size(ui->HOME_MENU_img_general, 70, 70);

    //Write style for HOME_MENU_img_general, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_general, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_general, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_general, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_digital_io
    ui->HOME_MENU_img_digital_io = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_digital_io, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_digital_io, &_Digital_io_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_digital_io, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_digital_io, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_digital_io, 177, 249);
    lv_obj_set_size(ui->HOME_MENU_img_digital_io, 70, 70);

    //Write style for HOME_MENU_img_digital_io, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_digital_io, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_digital_io, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_digital_io, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_preference
    ui->HOME_MENU_img_preference = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_preference, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_preference, &_perfect_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_preference, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_preference, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_preference, 319, 249);
    lv_obj_set_size(ui->HOME_MENU_img_preference, 70, 70);

    //Write style for HOME_MENU_img_preference, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_preference, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_preference, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_preference, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_log
    ui->HOME_MENU_img_log = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_log, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_log, &_log_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_log, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_log, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_log, 460, 248);
    lv_obj_set_size(ui->HOME_MENU_img_log, 70, 70);

    //Write style for HOME_MENU_img_log, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_log, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_log, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_admin
    ui->HOME_MENU_img_admin = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_admin, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_admin, &_admin_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_admin, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_admin, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_admin, 602, 248);
    lv_obj_set_size(ui->HOME_MENU_img_admin, 70, 70);

    //Write style for HOME_MENU_img_admin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_admin, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_admin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_admin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_communication
    ui->HOME_MENU_img_communication = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_communication, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_communication, &_communication_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_communication, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_communication, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_communication, 743, 248);
    lv_obj_set_size(ui->HOME_MENU_img_communication, 70, 70);

    //Write style for HOME_MENU_img_communication, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_communication, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_communication, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_communication, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_info
    ui->HOME_MENU_img_info = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_info, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_info, &_info_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_info, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_info, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_info, 34, 371);
    lv_obj_set_size(ui->HOME_MENU_img_info, 70, 70);

    //Write style for HOME_MENU_img_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_info, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_energy
    ui->HOME_MENU_img_energy = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_energy, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_energy, &_energy_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_energy, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_energy, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_energy, 176, 371);
    lv_obj_set_size(ui->HOME_MENU_img_energy, 70, 70);

    //Write style for HOME_MENU_img_energy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_energy, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_energy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_energy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_date
    ui->HOME_MENU_img_date = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_date, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_date, &_date_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_date, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_date, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_date, 318, 371);
    lv_obj_set_size(ui->HOME_MENU_img_date, 70, 70);

    //Write style for HOME_MENU_img_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_date, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_config
    ui->HOME_MENU_img_config = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_config, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_config, &_config_alone_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_config, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_config, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_config, 34, 12);
    lv_obj_set_size(ui->HOME_MENU_img_config, 70, 70);

    //Write style for HOME_MENU_img_config, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_config, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_config, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_config, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_MENU_img_meter
    ui->HOME_MENU_img_meter = lv_img_create(ui->HOME_MENU_cont_1);
    lv_obj_add_flag(ui->HOME_MENU_img_meter, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_MENU_img_meter, &_meter2_alpha_70x70);
    lv_img_set_pivot(ui->HOME_MENU_img_meter, 50,50);
    lv_img_set_angle(ui->HOME_MENU_img_meter, 0);
    lv_obj_set_pos(ui->HOME_MENU_img_meter, 32, 128);
    lv_obj_set_size(ui->HOME_MENU_img_meter, 70, 70);

    //Write style for HOME_MENU_img_meter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HOME_MENU_img_meter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_MENU_img_meter, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HOME_MENU_img_meter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->HOME_MENU_img_meter, lv_color_hex(0xf5e011), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_MENU_img_meter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of HOME_MENU.


    //Update current screen layout.
    lv_obj_update_layout(ui->HOME_MENU);

}
