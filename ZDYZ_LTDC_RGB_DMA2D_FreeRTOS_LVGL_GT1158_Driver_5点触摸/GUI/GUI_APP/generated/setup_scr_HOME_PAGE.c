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



void setup_scr_HOME_PAGE(lv_ui *ui)
{
    //Write codes HOME_PAGE
    ui->HOME_PAGE = lv_obj_create(NULL);
    lv_obj_set_size(ui->HOME_PAGE, 800, 268);
    lv_obj_set_scrollbar_mode(ui->HOME_PAGE, LV_SCROLLBAR_MODE_OFF);

    //Write style for HOME_PAGE, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_PAGE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_cont_1
    ui->HOME_PAGE_cont_1 = lv_obj_create(ui->HOME_PAGE);
    lv_obj_set_pos(ui->HOME_PAGE_cont_1, 0, 0);
    lv_obj_set_size(ui->HOME_PAGE_cont_1, 800, 268);
    lv_obj_set_scrollbar_mode(ui->HOME_PAGE_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for HOME_PAGE_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_PAGE_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_PAGE_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_img_1
    ui->HOME_PAGE_img_1 = lv_img_create(ui->HOME_PAGE_cont_1);
    lv_obj_add_flag(ui->HOME_PAGE_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_PAGE_img_1, &_kk_alpha_37x36);
    lv_img_set_pivot(ui->HOME_PAGE_img_1, 50,50);
    lv_img_set_angle(ui->HOME_PAGE_img_1, 0);
    lv_obj_set_pos(ui->HOME_PAGE_img_1, 751, 43);
    lv_obj_set_size(ui->HOME_PAGE_img_1, 37, 36);

    //Write style for HOME_PAGE_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->HOME_PAGE_img_1, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->HOME_PAGE_img_1, lv_color_hex(0xf5052a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_PAGE_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_PAGE_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_led_1
    ui->HOME_PAGE_led_1 = lv_led_create(ui->HOME_PAGE_cont_1);
    lv_led_set_brightness(ui->HOME_PAGE_led_1, 255);
    lv_led_set_color(ui->HOME_PAGE_led_1, lv_color_hex(0x52ff00));
    lv_obj_set_pos(ui->HOME_PAGE_led_1, 761, 12);
    lv_obj_set_size(ui->HOME_PAGE_led_1, 15, 15);

    //Write codes HOME_PAGE_label_Vout
    ui->HOME_PAGE_label_Vout = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_label_Vout, "00.000");
    lv_label_set_long_mode(ui->HOME_PAGE_label_Vout, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_Vout, 203, -7);
    lv_obj_set_size(ui->HOME_PAGE_label_Vout, 355, 108);

    //Write style for HOME_PAGE_label_Vout, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_Vout, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_Vout, &lv_font_SourceHanSerifSC_Regular_110, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_Vout, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_Vout, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_Iout
    ui->HOME_PAGE_label_Iout = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_label_Iout, "0.0000");
    lv_label_set_long_mode(ui->HOME_PAGE_label_Iout, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_Iout, 203, 85);
    lv_obj_set_size(ui->HOME_PAGE_label_Iout, 355, 110);

    //Write style for HOME_PAGE_label_Iout, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_Iout, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_Iout, &lv_font_SourceHanSerifSC_Regular_110, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_Iout, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_Iout, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_VoUnit
    ui->HOME_PAGE_label_VoUnit = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_label_VoUnit, "V");
    lv_label_set_long_mode(ui->HOME_PAGE_label_VoUnit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_VoUnit, 551, -5);
    lv_obj_set_size(ui->HOME_PAGE_label_VoUnit, 96, 112);

    //Write style for HOME_PAGE_label_VoUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_VoUnit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_VoUnit, &lv_font_SourceHanSerifSC_Regular_110, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_VoUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_VoUnit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_IoUnit
    ui->HOME_PAGE_label_IoUnit = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_label_IoUnit, "A");
    lv_label_set_long_mode(ui->HOME_PAGE_label_IoUnit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_IoUnit, 552, 87);
    lv_obj_set_size(ui->HOME_PAGE_label_IoUnit, 96, 112);

    //Write style for HOME_PAGE_label_IoUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_IoUnit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_IoUnit, &lv_font_SourceHanSerifSC_Regular_110, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_IoUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_IoUnit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_img_Menu
    ui->HOME_PAGE_img_Menu = lv_img_create(ui->HOME_PAGE_cont_1);
    lv_obj_add_flag(ui->HOME_PAGE_img_Menu, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_PAGE_img_Menu, &_Icons_Menu_alpha_46x44);
    lv_img_set_pivot(ui->HOME_PAGE_img_Menu, 50,50);
    lv_img_set_angle(ui->HOME_PAGE_img_Menu, 0);
    lv_obj_set_pos(ui->HOME_PAGE_img_Menu, 15, 205);
    lv_obj_set_size(ui->HOME_PAGE_img_Menu, 46, 44);

    //Write style for HOME_PAGE_img_Menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->HOME_PAGE_img_Menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_PAGE_img_Menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_img_Menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_PAGE_img_Menu, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_img_SET
    ui->HOME_PAGE_img_SET = lv_img_create(ui->HOME_PAGE_cont_1);
    lv_obj_add_flag(ui->HOME_PAGE_img_SET, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_PAGE_img_SET, &_Icons_Settings_alpha_56x53);
    lv_img_set_pivot(ui->HOME_PAGE_img_SET, 50,50);
    lv_img_set_angle(ui->HOME_PAGE_img_SET, 0);
    lv_obj_set_pos(ui->HOME_PAGE_img_SET, 15, 9);
    lv_obj_set_size(ui->HOME_PAGE_img_SET, 56, 53);

    //Write style for HOME_PAGE_img_SET, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->HOME_PAGE_img_SET, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_PAGE_img_SET, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_img_SET, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_PAGE_img_SET, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_back_label_Out_On_Off
    ui->HOME_PAGE_back_label_Out_On_Off = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_back_label_Out_On_Off, "");
    lv_label_set_long_mode(ui->HOME_PAGE_back_label_Out_On_Off, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_back_label_Out_On_Off, 78, 204);
    lv_obj_set_size(ui->HOME_PAGE_back_label_Out_On_Off, 79, 45);

    //Write style for HOME_PAGE_back_label_Out_On_Off, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_back_label_Out_On_Off, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->HOME_PAGE_back_label_Out_On_Off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->HOME_PAGE_back_label_Out_On_Off, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->HOME_PAGE_back_label_Out_On_Off, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_back_label_Out_On_Off, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_back_label_Out_On_Off, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_back_label_Out_On_Off, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_back_label_Out_On_Off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_back_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_back_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_back_label_Out_On_Off, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_back_label_Out_On_Off, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_PAGE_back_label_Out_On_Off, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_PAGE_back_label_Out_On_Off, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->HOME_PAGE_back_label_Out_On_Off, lv_color_hex(0x261099), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->HOME_PAGE_back_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->HOME_PAGE_back_label_Out_On_Off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_back_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_back_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_back_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_back_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_back_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_Out_On_Off
    ui->HOME_PAGE_label_Out_On_Off = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_label_Out_On_Off, "OFF");
    lv_label_set_long_mode(ui->HOME_PAGE_label_Out_On_Off, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_Out_On_Off, 90, 213);
    lv_obj_set_size(ui->HOME_PAGE_label_Out_On_Off, 52, 30);

    //Write style for HOME_PAGE_label_Out_On_Off, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_Out_On_Off, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_Out_On_Off, &lv_font_SourceHanSerifSC_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_Out_On_Off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_Out_On_Off, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_Out_On_Off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_back_edit_v_set
    ui->HOME_PAGE_back_edit_v_set = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_back_edit_v_set, "");
    lv_label_set_long_mode(ui->HOME_PAGE_back_edit_v_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_back_edit_v_set, 232, 212);
    lv_obj_set_size(ui->HOME_PAGE_back_edit_v_set, 114, 34);

    //Write style for HOME_PAGE_back_edit_v_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_back_edit_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_back_edit_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_back_edit_v_set, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_back_edit_v_set, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_back_edit_v_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_back_edit_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_back_edit_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_back_edit_v_set, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_back_edit_v_set, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_PAGE_back_edit_v_set, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_PAGE_back_edit_v_set, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_back_edit_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_back_edit_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_back_edit_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_back_edit_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_back_edit_v_set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_Set_V
    ui->HOME_PAGE_label_Set_V = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_label_Set_V, "Vset");
    lv_label_set_long_mode(ui->HOME_PAGE_label_Set_V, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_Set_V, 173, 214);
    lv_obj_set_size(ui->HOME_PAGE_label_Set_V, 52, 30);

    //Write style for HOME_PAGE_label_Set_V, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_Set_V, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_Set_V, &lv_font_SourceHanSerifSC_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_Set_V, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_Set_V, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_Set_I_POS
    ui->HOME_PAGE_label_Set_I_POS = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_label_Set_I_POS, "+I");
    lv_label_set_long_mode(ui->HOME_PAGE_label_Set_I_POS, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_Set_I_POS, 364, 215);
    lv_obj_set_size(ui->HOME_PAGE_label_Set_I_POS, 31, 30);

    //Write style for HOME_PAGE_label_Set_I_POS, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_Set_I_POS, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_Set_I_POS, &lv_font_SourceHanSerifSC_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_Set_I_POS, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_Set_I_POS, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_back_edit_i_set_pos
    ui->HOME_PAGE_back_edit_i_set_pos = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_back_edit_i_set_pos, "");
    lv_label_set_long_mode(ui->HOME_PAGE_back_edit_i_set_pos, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_back_edit_i_set_pos, 397, 212);
    lv_obj_set_size(ui->HOME_PAGE_back_edit_i_set_pos, 115, 34);

    //Write style for HOME_PAGE_back_edit_i_set_pos, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_back_edit_i_set_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_back_edit_i_set_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_back_edit_i_set_pos, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_back_edit_i_set_pos, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_back_edit_i_set_pos, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_back_edit_i_set_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_back_edit_i_set_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_back_edit_i_set_pos, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_back_edit_i_set_pos, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_PAGE_back_edit_i_set_pos, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_PAGE_back_edit_i_set_pos, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_back_edit_i_set_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_back_edit_i_set_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_back_edit_i_set_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_back_edit_i_set_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_back_edit_i_set_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_Set_I_NEG
    ui->HOME_PAGE_label_Set_I_NEG = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_label_Set_I_NEG, "-I");
    lv_label_set_long_mode(ui->HOME_PAGE_label_Set_I_NEG, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_Set_I_NEG, 536, 215);
    lv_obj_set_size(ui->HOME_PAGE_label_Set_I_NEG, 21, 30);

    //Write style for HOME_PAGE_label_Set_I_NEG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_Set_I_NEG, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_Set_I_NEG, &lv_font_SourceHanSerifSC_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_Set_I_NEG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_Set_I_NEG, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_back_edit_i_set_neg
    ui->HOME_PAGE_back_edit_i_set_neg = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_back_edit_i_set_neg, "");
    lv_label_set_long_mode(ui->HOME_PAGE_back_edit_i_set_neg, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_back_edit_i_set_neg, 566, 212);
    lv_obj_set_size(ui->HOME_PAGE_back_edit_i_set_neg, 115, 34);

    //Write style for HOME_PAGE_back_edit_i_set_neg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_back_edit_i_set_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_back_edit_i_set_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_back_edit_i_set_neg, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_back_edit_i_set_neg, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_back_edit_i_set_neg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_back_edit_i_set_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_back_edit_i_set_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_back_edit_i_set_neg, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_back_edit_i_set_neg, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_PAGE_back_edit_i_set_neg, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_PAGE_back_edit_i_set_neg, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_back_edit_i_set_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_back_edit_i_set_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_back_edit_i_set_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_back_edit_i_set_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_back_edit_i_set_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_edit_Vset
    ui->HOME_PAGE_edit_Vset = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_edit_Vset, "61.999");
    lv_label_set_long_mode(ui->HOME_PAGE_edit_Vset, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_edit_Vset, 234, 214);
    lv_obj_set_size(ui->HOME_PAGE_edit_Vset, 80, 28);

    //Write style for HOME_PAGE_edit_Vset, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_edit_Vset, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_edit_Vset, &lv_font_SourceHanSerifSC_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_edit_Vset, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_edit_Vset, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_edit_Iset_pos
    ui->HOME_PAGE_edit_Iset_pos = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_edit_Iset_pos, "15.4999");
    lv_label_set_long_mode(ui->HOME_PAGE_edit_Iset_pos, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_edit_Iset_pos, 399, 214);
    lv_obj_set_size(ui->HOME_PAGE_edit_Iset_pos, 102, 30);

    //Write style for HOME_PAGE_edit_Iset_pos, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_edit_Iset_pos, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_edit_Iset_pos, &lv_font_SourceHanSerifSC_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_edit_Iset_pos, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_edit_Iset_pos, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_edit_Iset_neg
    ui->HOME_PAGE_edit_Iset_neg = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_edit_Iset_neg, "15.4999");
    lv_label_set_long_mode(ui->HOME_PAGE_edit_Iset_neg, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_edit_Iset_neg, 569, 216);
    lv_obj_set_size(ui->HOME_PAGE_edit_Iset_neg, 102, 30);

    //Write style for HOME_PAGE_edit_Iset_neg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_edit_Iset_neg, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_edit_Iset_neg, &lv_font_SourceHanSerifSC_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_edit_Iset_neg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_edit_Iset_neg, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_edit_VUnit
    ui->HOME_PAGE_edit_VUnit = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_edit_VUnit, "V");
    lv_label_set_long_mode(ui->HOME_PAGE_edit_VUnit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_edit_VUnit, 318, 215);
    lv_obj_set_size(ui->HOME_PAGE_edit_VUnit, 17, 30);

    //Write style for HOME_PAGE_edit_VUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_edit_VUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_edit_VUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_edit_VUnit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_edit_VUnit, &lv_font_SourceHanSerifSC_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_edit_VUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_edit_VUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_edit_VUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_edit_VUnit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_edit_VUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_edit_VUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_edit_VUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_edit_VUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_edit_VUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_edit_VUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_edit_IUnit_pos
    ui->HOME_PAGE_edit_IUnit_pos = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_edit_IUnit_pos, "A");
    lv_label_set_long_mode(ui->HOME_PAGE_edit_IUnit_pos, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_edit_IUnit_pos, 493, 214);
    lv_obj_set_size(ui->HOME_PAGE_edit_IUnit_pos, 17, 30);

    //Write style for HOME_PAGE_edit_IUnit_pos, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_edit_IUnit_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_edit_IUnit_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_edit_IUnit_pos, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_edit_IUnit_pos, &lv_font_SourceHanSerifSC_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_edit_IUnit_pos, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_edit_IUnit_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_edit_IUnit_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_edit_IUnit_pos, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_edit_IUnit_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_edit_IUnit_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_edit_IUnit_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_edit_IUnit_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_edit_IUnit_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_edit_IUnit_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_edit_IUnit_neg
    ui->HOME_PAGE_edit_IUnit_neg = lv_label_create(ui->HOME_PAGE_cont_1);
    lv_label_set_text(ui->HOME_PAGE_edit_IUnit_neg, "A");
    lv_label_set_long_mode(ui->HOME_PAGE_edit_IUnit_neg, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_edit_IUnit_neg, 660, 216);
    lv_obj_set_size(ui->HOME_PAGE_edit_IUnit_neg, 18, 30);

    //Write style for HOME_PAGE_edit_IUnit_neg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_edit_IUnit_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_edit_IUnit_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_edit_IUnit_neg, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_edit_IUnit_neg, &lv_font_SourceHanSerifSC_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_edit_IUnit_neg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_edit_IUnit_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_edit_IUnit_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_edit_IUnit_neg, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_edit_IUnit_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_edit_IUnit_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_edit_IUnit_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_edit_IUnit_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_edit_IUnit_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_edit_IUnit_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of HOME_PAGE.


    //Update current screen layout.
    lv_obj_update_layout(ui->HOME_PAGE);

}
