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
    lv_obj_set_size(ui->HOME_PAGE, 960, 240);
    lv_obj_set_scrollbar_mode(ui->HOME_PAGE, LV_SCROLLBAR_MODE_OFF);

    //Write style for HOME_PAGE, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_PAGE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_cont_Set
    ui->HOME_PAGE_cont_Set = lv_obj_create(ui->HOME_PAGE);
    lv_obj_set_pos(ui->HOME_PAGE_cont_Set, 715, 40);
    lv_obj_set_size(ui->HOME_PAGE_cont_Set, 245, 200);
    lv_obj_set_scrollbar_mode(ui->HOME_PAGE_cont_Set, LV_SCROLLBAR_MODE_OFF);

    //Write style for HOME_PAGE_cont_Set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_cont_Set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_cont_Set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_cont_Set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_PAGE_cont_Set, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_PAGE_cont_Set, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_cont_Set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_cont_Set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_cont_Set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_cont_Set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_cont_Set, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_Set_I_NEG
    ui->HOME_PAGE_label_Set_I_NEG = lv_label_create(ui->HOME_PAGE_cont_Set);
    lv_label_set_text(ui->HOME_PAGE_label_Set_I_NEG, "-I");
    lv_label_set_long_mode(ui->HOME_PAGE_label_Set_I_NEG, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_Set_I_NEG, 3, 159);
    lv_obj_set_size(ui->HOME_PAGE_label_Set_I_NEG, 40, 33);

    //Write style for HOME_PAGE_label_Set_I_NEG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_Set_I_NEG, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_Set_I_NEG, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_Set_I_NEG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_Set_I_NEG, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_Set_I_NEG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_back_edit_i_set_pos
    ui->HOME_PAGE_back_edit_i_set_pos = lv_label_create(ui->HOME_PAGE_cont_Set);
    lv_label_set_text(ui->HOME_PAGE_back_edit_i_set_pos, "");
    lv_label_set_long_mode(ui->HOME_PAGE_back_edit_i_set_pos, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_back_edit_i_set_pos, 41, 159);
    lv_obj_set_size(ui->HOME_PAGE_back_edit_i_set_pos, 166, 39);

    //Write style for HOME_PAGE_back_edit_i_set_pos, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_back_edit_i_set_pos, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->HOME_PAGE_back_edit_i_set_pos, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->HOME_PAGE_back_edit_i_set_pos, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->HOME_PAGE_back_edit_i_set_pos, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_back_edit_i_set_pos, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes HOME_PAGE_edit_IUnit_neg
    ui->HOME_PAGE_edit_IUnit_neg = lv_label_create(ui->HOME_PAGE_cont_Set);
    lv_label_set_text(ui->HOME_PAGE_edit_IUnit_neg, "A");
    lv_label_set_long_mode(ui->HOME_PAGE_edit_IUnit_neg, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_edit_IUnit_neg, 178, 162);
    lv_obj_set_size(ui->HOME_PAGE_edit_IUnit_neg, 24, 31);

    //Write style for HOME_PAGE_edit_IUnit_neg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_edit_IUnit_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_edit_IUnit_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_edit_IUnit_neg, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_edit_IUnit_neg, &lv_font_SourceHanSerifSC_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes HOME_PAGE_edit_Iset_neg
    ui->HOME_PAGE_edit_Iset_neg = lv_label_create(ui->HOME_PAGE_cont_Set);
    lv_label_set_text(ui->HOME_PAGE_edit_Iset_neg, "15.4999");
    lv_label_set_long_mode(ui->HOME_PAGE_edit_Iset_neg, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_edit_Iset_neg, 0, 149);
    lv_obj_set_size(ui->HOME_PAGE_edit_Iset_neg, 240, 46);

    //Write style for HOME_PAGE_edit_Iset_neg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_edit_Iset_neg, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_edit_Iset_neg, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_edit_Iset_neg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_edit_Iset_neg, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_edit_Iset_neg, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_edit_Iset_neg, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_edit_Iset_neg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_Set_I_POS
    ui->HOME_PAGE_label_Set_I_POS = lv_label_create(ui->HOME_PAGE_cont_Set);
    lv_label_set_text(ui->HOME_PAGE_label_Set_I_POS, "+I");
    lv_label_set_long_mode(ui->HOME_PAGE_label_Set_I_POS, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_Set_I_POS, 0, 103);
    lv_obj_set_size(ui->HOME_PAGE_label_Set_I_POS, 40, 33);

    //Write style for HOME_PAGE_label_Set_I_POS, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_Set_I_POS, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_Set_I_POS, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_Set_I_POS, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_Set_I_POS, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_Set_I_POS, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_back_edit_i_set_neg
    ui->HOME_PAGE_back_edit_i_set_neg = lv_label_create(ui->HOME_PAGE_cont_Set);
    lv_label_set_text(ui->HOME_PAGE_back_edit_i_set_neg, "");
    lv_label_set_long_mode(ui->HOME_PAGE_back_edit_i_set_neg, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_back_edit_i_set_neg, 41, 103);
    lv_obj_set_size(ui->HOME_PAGE_back_edit_i_set_neg, 166, 39);

    //Write style for HOME_PAGE_back_edit_i_set_neg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_back_edit_i_set_neg, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->HOME_PAGE_back_edit_i_set_neg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->HOME_PAGE_back_edit_i_set_neg, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->HOME_PAGE_back_edit_i_set_neg, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_back_edit_i_set_neg, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes HOME_PAGE_edit_IUnit_pos
    ui->HOME_PAGE_edit_IUnit_pos = lv_label_create(ui->HOME_PAGE_cont_Set);
    lv_label_set_text(ui->HOME_PAGE_edit_IUnit_pos, "A");
    lv_label_set_long_mode(ui->HOME_PAGE_edit_IUnit_pos, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_edit_IUnit_pos, 178, 106);
    lv_obj_set_size(ui->HOME_PAGE_edit_IUnit_pos, 24, 32);

    //Write style for HOME_PAGE_edit_IUnit_pos, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_edit_IUnit_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_edit_IUnit_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_edit_IUnit_pos, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_edit_IUnit_pos, &lv_font_SourceHanSerifSC_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes HOME_PAGE_edit_Iset_pos
    ui->HOME_PAGE_edit_Iset_pos = lv_label_create(ui->HOME_PAGE_cont_Set);
    lv_label_set_text(ui->HOME_PAGE_edit_Iset_pos, "15.4999");
    lv_label_set_long_mode(ui->HOME_PAGE_edit_Iset_pos, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_edit_Iset_pos, 0, 75);
    lv_obj_set_size(ui->HOME_PAGE_edit_Iset_pos, 240, 64);

    //Write style for HOME_PAGE_edit_Iset_pos, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_edit_Iset_pos, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_edit_Iset_pos, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_edit_Iset_pos, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_edit_Iset_pos, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_edit_Iset_pos, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_edit_Iset_pos, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_edit_Iset_pos, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_set_i
    ui->HOME_PAGE_label_set_i = lv_label_create(ui->HOME_PAGE_cont_Set);
    lv_label_set_text(ui->HOME_PAGE_label_set_i, "Iset");
    lv_label_set_long_mode(ui->HOME_PAGE_label_set_i, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_set_i, 85, 69);
    lv_obj_set_size(ui->HOME_PAGE_label_set_i, 81, 34);

    //Write style for HOME_PAGE_label_set_i, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_set_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_set_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_set_i, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_set_i, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_set_i, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_set_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_set_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_set_i, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_set_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_set_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_set_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_set_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_set_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_set_i, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_back_edit_v_set
    ui->HOME_PAGE_back_edit_v_set = lv_label_create(ui->HOME_PAGE_cont_Set);
    lv_label_set_text(ui->HOME_PAGE_back_edit_v_set, "");
    lv_label_set_long_mode(ui->HOME_PAGE_back_edit_v_set, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_back_edit_v_set, 41, 32);
    lv_obj_set_size(ui->HOME_PAGE_back_edit_v_set, 166, 39);

    //Write style for HOME_PAGE_back_edit_v_set, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_back_edit_v_set, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->HOME_PAGE_back_edit_v_set, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->HOME_PAGE_back_edit_v_set, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->HOME_PAGE_back_edit_v_set, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_back_edit_v_set, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes HOME_PAGE_edit_VUnit
    ui->HOME_PAGE_edit_VUnit = lv_label_create(ui->HOME_PAGE_cont_Set);
    lv_label_set_text(ui->HOME_PAGE_edit_VUnit, "V");
    lv_label_set_long_mode(ui->HOME_PAGE_edit_VUnit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_edit_VUnit, 178, 37);
    lv_obj_set_size(ui->HOME_PAGE_edit_VUnit, 25, 32);

    //Write style for HOME_PAGE_edit_VUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_edit_VUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_edit_VUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_edit_VUnit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_edit_VUnit, &lv_font_SourceHanSerifSC_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes HOME_PAGE_label_Set_V
    ui->HOME_PAGE_label_Set_V = lv_label_create(ui->HOME_PAGE_cont_Set);
    lv_label_set_text(ui->HOME_PAGE_label_Set_V, "Vset");
    lv_label_set_long_mode(ui->HOME_PAGE_label_Set_V, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_Set_V, 85, -2);
    lv_obj_set_size(ui->HOME_PAGE_label_Set_V, 81, 39);

    //Write style for HOME_PAGE_label_Set_V, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_Set_V, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_Set_V, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_Set_V, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_Set_V, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_Set_V, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_edit_Vset
    ui->HOME_PAGE_edit_Vset = lv_label_create(ui->HOME_PAGE_cont_Set);
    lv_label_set_text(ui->HOME_PAGE_edit_Vset, "61.999");
    lv_label_set_long_mode(ui->HOME_PAGE_edit_Vset, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_edit_Vset, 0, 0);
    lv_obj_set_size(ui->HOME_PAGE_edit_Vset, 240, 70);

    //Write style for HOME_PAGE_edit_Vset, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_edit_Vset, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_edit_Vset, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_edit_Vset, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_edit_Vset, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_edit_Vset, 34, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_edit_Vset, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_cont_read_back_value
    ui->HOME_PAGE_cont_read_back_value = lv_obj_create(ui->HOME_PAGE);
    lv_obj_set_pos(ui->HOME_PAGE_cont_read_back_value, 105, 0);
    lv_obj_set_size(ui->HOME_PAGE_cont_read_back_value, 610, 240);
    lv_obj_set_scrollbar_mode(ui->HOME_PAGE_cont_read_back_value, LV_SCROLLBAR_MODE_OFF);

    //Write style for HOME_PAGE_cont_read_back_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_cont_read_back_value, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->HOME_PAGE_cont_read_back_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->HOME_PAGE_cont_read_back_value, lv_color_hex(0xa43546), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->HOME_PAGE_cont_read_back_value, LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_cont_read_back_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_cont_read_back_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_PAGE_cont_read_back_value, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_PAGE_cont_read_back_value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_cont_read_back_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_cont_read_back_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_cont_read_back_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_cont_read_back_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_cont_read_back_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_IoUnit
    ui->HOME_PAGE_label_IoUnit = lv_label_create(ui->HOME_PAGE_cont_read_back_value);
    lv_label_set_text(ui->HOME_PAGE_label_IoUnit, "A");
    lv_label_set_long_mode(ui->HOME_PAGE_label_IoUnit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_IoUnit, 510, 130);
    lv_obj_set_size(ui->HOME_PAGE_label_IoUnit, 81, 106);

    //Write style for HOME_PAGE_label_IoUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_IoUnit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_IoUnit, &lv_font_SourceHanSerifSC_Regular_110, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_IoUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_IoUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_IoUnit, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_IoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_VoUnit
    ui->HOME_PAGE_label_VoUnit = lv_label_create(ui->HOME_PAGE_cont_read_back_value);
    lv_label_set_text(ui->HOME_PAGE_label_VoUnit, "V");
    lv_label_set_long_mode(ui->HOME_PAGE_label_VoUnit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_VoUnit, 513, 7);
    lv_obj_set_size(ui->HOME_PAGE_label_VoUnit, 79, 110);

    //Write style for HOME_PAGE_label_VoUnit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_VoUnit, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_VoUnit, &lv_font_SourceHanSerifSC_Regular_110, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_VoUnit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_VoUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_VoUnit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_Iout
    ui->HOME_PAGE_label_Iout = lv_label_create(ui->HOME_PAGE_cont_read_back_value);
    lv_label_set_text(ui->HOME_PAGE_label_Iout, "-0.0000");
    lv_label_set_long_mode(ui->HOME_PAGE_label_Iout, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_Iout, 15, 103);
    lv_obj_set_size(ui->HOME_PAGE_label_Iout, 488, 204);

    //Write style for HOME_PAGE_label_Iout, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_Iout, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_Iout, &lv_font_SourceHanSerifSC_Regular_140, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_Iout, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_Iout, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_Iout, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_Iout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_Vout
    ui->HOME_PAGE_label_Vout = lv_label_create(ui->HOME_PAGE_cont_read_back_value);
    lv_label_set_text(ui->HOME_PAGE_label_Vout, "0.0000");
    lv_label_set_long_mode(ui->HOME_PAGE_label_Vout, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_Vout, 23, -16);
    lv_obj_set_size(ui->HOME_PAGE_label_Vout, 481, 150);

    //Write style for HOME_PAGE_label_Vout, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_Vout, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_Vout, &lv_font_SourceHanSerifSC_Regular_140, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_Vout, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_Vout, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_Vout, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_cont_menu
    ui->HOME_PAGE_cont_menu = lv_obj_create(ui->HOME_PAGE);
    lv_obj_set_pos(ui->HOME_PAGE_cont_menu, 0, 0);
    lv_obj_set_size(ui->HOME_PAGE_cont_menu, 105, 240);
    lv_obj_set_scrollbar_mode(ui->HOME_PAGE_cont_menu, LV_SCROLLBAR_MODE_OFF);

    //Write style for HOME_PAGE_cont_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_cont_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_PAGE_cont_menu, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_PAGE_cont_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_img_Menu
    ui->HOME_PAGE_img_Menu = lv_img_create(ui->HOME_PAGE_cont_menu);
    lv_obj_add_flag(ui->HOME_PAGE_img_Menu, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_PAGE_img_Menu, &_Icons_Menu_alpha_46x44);
    lv_img_set_pivot(ui->HOME_PAGE_img_Menu, 50,50);
    lv_img_set_angle(ui->HOME_PAGE_img_Menu, 0);
    lv_obj_set_pos(ui->HOME_PAGE_img_Menu, 27, 184);
    lv_obj_set_size(ui->HOME_PAGE_img_Menu, 46, 44);

    //Write style for HOME_PAGE_img_Menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->HOME_PAGE_img_Menu, 135, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->HOME_PAGE_img_Menu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_PAGE_img_Menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_img_Menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_PAGE_img_Menu, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_CC
    ui->HOME_PAGE_label_CC = lv_label_create(ui->HOME_PAGE_cont_menu);
    lv_label_set_text(ui->HOME_PAGE_label_CC, "CC");
    lv_label_set_long_mode(ui->HOME_PAGE_label_CC, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_CC, 21, 59);
    lv_obj_set_size(ui->HOME_PAGE_label_CC, 60, 41);

    //Write style for HOME_PAGE_label_CC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_CC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_CC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_CC, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_CC, &lv_font_SourceHanSerifSC_Regular_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_CC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_CC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_CC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_CC, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_CC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_CC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_CC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_CC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_CC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_CC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_CV
    ui->HOME_PAGE_label_CV = lv_label_create(ui->HOME_PAGE_cont_menu);
    lv_label_set_text(ui->HOME_PAGE_label_CV, "CV");
    lv_label_set_long_mode(ui->HOME_PAGE_label_CV, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_CV, 20, 59);
    lv_obj_set_size(ui->HOME_PAGE_label_CV, 60, 50);

    //Write style for HOME_PAGE_label_CV, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_CV, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_CV, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_CV, lv_color_hex(0x99981c), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_CV, &lv_font_SourceHanSerifSC_Regular_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_CV, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_CV, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_CV, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_CV, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_CV, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_CV, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_CV, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_CV, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_CV, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_CV, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_1
    ui->HOME_PAGE_label_1 = lv_label_create(ui->HOME_PAGE_cont_menu);
    lv_label_set_text(ui->HOME_PAGE_label_1, "");
    lv_label_set_long_mode(ui->HOME_PAGE_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_1, 6, 109);
    lv_obj_set_size(ui->HOME_PAGE_label_1, 93, 43);

    //Write style for HOME_PAGE_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->HOME_PAGE_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->HOME_PAGE_label_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->HOME_PAGE_label_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_1, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_1, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_1, 70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_PAGE_label_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_PAGE_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_label_2
    ui->HOME_PAGE_label_2 = lv_label_create(ui->HOME_PAGE_cont_menu);
    lv_label_set_text(ui->HOME_PAGE_label_2, "OFF");
    lv_label_set_long_mode(ui->HOME_PAGE_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HOME_PAGE_label_2, 0, 109);
    lv_obj_set_size(ui->HOME_PAGE_label_2, 105, 44);

    //Write style for HOME_PAGE_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_label_2, lv_color_hex(0x67ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_label_2, &lv_font_SourceHanSerifSC_Regular_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HOME_PAGE_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HOME_PAGE_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_label_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_btn_Menu
    ui->HOME_PAGE_btn_Menu = lv_btn_create(ui->HOME_PAGE_cont_menu);
    ui->HOME_PAGE_btn_Menu_label = lv_label_create(ui->HOME_PAGE_btn_Menu);
    lv_label_set_text(ui->HOME_PAGE_btn_Menu_label, "");
    lv_label_set_long_mode(ui->HOME_PAGE_btn_Menu_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HOME_PAGE_btn_Menu_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HOME_PAGE_btn_Menu, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HOME_PAGE_btn_Menu_label, LV_PCT(100));
    lv_obj_set_pos(ui->HOME_PAGE_btn_Menu, 2, 176);
    lv_obj_set_size(ui->HOME_PAGE_btn_Menu, 100, 59);

    //Write style for HOME_PAGE_btn_Menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_btn_Menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HOME_PAGE_btn_Menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_btn_Menu, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_btn_Menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HOME_PAGE_btn_Menu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HOME_PAGE_btn_Menu, &lv_font_SourceHanSerifSC_Regular_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HOME_PAGE_btn_Menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HOME_PAGE_btn_Menu, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_cont_2
    ui->HOME_PAGE_cont_2 = lv_obj_create(ui->HOME_PAGE);
    lv_obj_set_pos(ui->HOME_PAGE_cont_2, 715, 0);
    lv_obj_set_size(ui->HOME_PAGE_cont_2, 245, 40);
    lv_obj_set_scrollbar_mode(ui->HOME_PAGE_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for HOME_PAGE_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HOME_PAGE_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HOME_PAGE_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HOME_PAGE_cont_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HOME_PAGE_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HOME_PAGE_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HOME_PAGE_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HOME_PAGE_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HOME_PAGE_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HOME_PAGE_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_img_2
    ui->HOME_PAGE_img_2 = lv_img_create(ui->HOME_PAGE_cont_2);
    lv_obj_add_flag(ui->HOME_PAGE_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_PAGE_img_2, &_keyback_alpha_245x40);
    lv_img_set_pivot(ui->HOME_PAGE_img_2, 50,50);
    lv_img_set_angle(ui->HOME_PAGE_img_2, 0);
    lv_obj_set_pos(ui->HOME_PAGE_img_2, -1, 0);
    lv_obj_set_size(ui->HOME_PAGE_img_2, 245, 40);

    //Write style for HOME_PAGE_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->HOME_PAGE_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_PAGE_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_PAGE_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_img_1
    ui->HOME_PAGE_img_1 = lv_img_create(ui->HOME_PAGE_cont_2);
    lv_obj_add_flag(ui->HOME_PAGE_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_PAGE_img_1, &_kk_alpha_37x36);
    lv_img_set_pivot(ui->HOME_PAGE_img_1, 50,50);
    lv_img_set_angle(ui->HOME_PAGE_img_1, 0);
    lv_obj_set_pos(ui->HOME_PAGE_img_1, 164, 1);
    lv_obj_set_size(ui->HOME_PAGE_img_1, 37, 36);

    //Write style for HOME_PAGE_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->HOME_PAGE_img_1, 243, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->HOME_PAGE_img_1, lv_color_hex(0xfff1f3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_PAGE_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_PAGE_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_led_1
    ui->HOME_PAGE_led_1 = lv_led_create(ui->HOME_PAGE_cont_2);
    lv_led_set_brightness(ui->HOME_PAGE_led_1, 255);
    lv_led_set_color(ui->HOME_PAGE_led_1, lv_color_hex(0x52ff00));
    lv_obj_set_pos(ui->HOME_PAGE_led_1, 212, 9);
    lv_obj_set_size(ui->HOME_PAGE_led_1, 20, 20);

    //Write codes HOME_PAGE_img_3
    ui->HOME_PAGE_img_3 = lv_img_create(ui->HOME_PAGE_cont_2);
    lv_obj_add_flag(ui->HOME_PAGE_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_PAGE_img_3, &_suo_alpha_30x30);
    lv_img_set_pivot(ui->HOME_PAGE_img_3, 50,50);
    lv_img_set_angle(ui->HOME_PAGE_img_3, 0);
    lv_obj_set_pos(ui->HOME_PAGE_img_3, 38, 3);
    lv_obj_set_size(ui->HOME_PAGE_img_3, 30, 30);

    //Write style for HOME_PAGE_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->HOME_PAGE_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_PAGE_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_PAGE_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_img_4
    ui->HOME_PAGE_img_4 = lv_img_create(ui->HOME_PAGE_cont_2);
    lv_obj_add_flag(ui->HOME_PAGE_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_PAGE_img_4, &_beep_alpha_32x30);
    lv_img_set_pivot(ui->HOME_PAGE_img_4, 50,50);
    lv_img_set_angle(ui->HOME_PAGE_img_4, 0);
    lv_obj_set_pos(ui->HOME_PAGE_img_4, 5, 5);
    lv_obj_set_size(ui->HOME_PAGE_img_4, 32, 30);

    //Write style for HOME_PAGE_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->HOME_PAGE_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_PAGE_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_PAGE_img_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HOME_PAGE_img_5
    ui->HOME_PAGE_img_5 = lv_img_create(ui->HOME_PAGE_cont_2);
    lv_obj_add_flag(ui->HOME_PAGE_img_5, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HOME_PAGE_img_5, &_usb3_alpha_47x34);
    lv_img_set_pivot(ui->HOME_PAGE_img_5, 0,0);
    lv_img_set_angle(ui->HOME_PAGE_img_5, 1800);
    lv_obj_set_pos(ui->HOME_PAGE_img_5, 114, 35);
    lv_obj_set_size(ui->HOME_PAGE_img_5, 47, 34);

    //Write style for HOME_PAGE_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->HOME_PAGE_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->HOME_PAGE_img_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HOME_PAGE_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HOME_PAGE_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HOME_PAGE_img_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of HOME_PAGE.


    //Update current screen layout.
    lv_obj_update_layout(ui->HOME_PAGE);

}
