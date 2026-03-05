/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *Back;
	bool Back_del;
	lv_obj_t *Back_cont_back;
	lv_obj_t *Back_img_Logo;
	lv_obj_t *HOME_PAGE;
	bool HOME_PAGE_del;
	lv_obj_t *HOME_PAGE_cont_1;
	lv_obj_t *HOME_PAGE_img_1;
	lv_obj_t *HOME_PAGE_led_1;
	lv_obj_t *HOME_PAGE_label_Vout;
	lv_obj_t *HOME_PAGE_label_Iout;
	lv_obj_t *HOME_PAGE_label_VoUnit;
	lv_obj_t *HOME_PAGE_label_IoUnit;
	lv_obj_t *HOME_PAGE_img_Menu;
	lv_obj_t *HOME_PAGE_img_SET;
	lv_obj_t *HOME_PAGE_back_label_Out_On_Off;
	lv_obj_t *HOME_PAGE_label_Out_On_Off;
	lv_obj_t *HOME_PAGE_back_edit_v_set;
	lv_obj_t *HOME_PAGE_label_Set_V;
	lv_obj_t *HOME_PAGE_label_Set_I_POS;
	lv_obj_t *HOME_PAGE_back_edit_i_set_pos;
	lv_obj_t *HOME_PAGE_label_Set_I_NEG;
	lv_obj_t *HOME_PAGE_back_edit_i_set_neg;
	lv_obj_t *HOME_PAGE_edit_Vset;
	lv_obj_t *HOME_PAGE_edit_Iset_pos;
	lv_obj_t *HOME_PAGE_edit_Iset_neg;
	lv_obj_t *HOME_PAGE_edit_VUnit;
	lv_obj_t *HOME_PAGE_edit_IUnit_pos;
	lv_obj_t *HOME_PAGE_edit_IUnit_neg;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_Back(lv_ui *ui);
void setup_scr_HOME_PAGE(lv_ui *ui);
LV_IMG_DECLARE(_Logo_alpha_569x159);
LV_IMG_DECLARE(_kk_alpha_37x36);
LV_IMG_DECLARE(_Icons_Menu_alpha_46x44);
LV_IMG_DECLARE(_Icons_Settings_alpha_56x53);

LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_110)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_16)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_25)


#ifdef __cplusplus
}
#endif
#endif
