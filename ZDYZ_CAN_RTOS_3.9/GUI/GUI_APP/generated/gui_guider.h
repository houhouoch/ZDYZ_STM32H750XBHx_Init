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
	lv_obj_t *HOME_PAGE_cont_Set;
	lv_obj_t *HOME_PAGE_label_Set_I_NEG;
	lv_obj_t *HOME_PAGE_back_edit_i_set_pos;
	lv_obj_t *HOME_PAGE_edit_IUnit_neg;
	lv_obj_t *HOME_PAGE_edit_Iset_neg;
	lv_obj_t *HOME_PAGE_label_Set_I_POS;
	lv_obj_t *HOME_PAGE_back_edit_i_set_neg;
	lv_obj_t *HOME_PAGE_edit_IUnit_pos;
	lv_obj_t *HOME_PAGE_edit_Iset_pos;
	lv_obj_t *HOME_PAGE_label_set_i;
	lv_obj_t *HOME_PAGE_back_edit_v_set;
	lv_obj_t *HOME_PAGE_edit_VUnit;
	lv_obj_t *HOME_PAGE_label_Set_V;
	lv_obj_t *HOME_PAGE_edit_Vset;
	lv_obj_t *HOME_PAGE_cont_read_back_value;
	lv_obj_t *HOME_PAGE_label_IoUnit;
	lv_obj_t *HOME_PAGE_label_VoUnit;
	lv_obj_t *HOME_PAGE_label_Iout;
	lv_obj_t *HOME_PAGE_label_Vout;
	lv_obj_t *HOME_PAGE_cont_menu;
	lv_obj_t *HOME_PAGE_img_Menu;
	lv_obj_t *HOME_PAGE_label_CC;
	lv_obj_t *HOME_PAGE_label_CV;
	lv_obj_t *HOME_PAGE_label_2;
	lv_obj_t *HOME_PAGE_label_1;
	lv_obj_t *HOME_PAGE_cont_2;
	lv_obj_t *HOME_PAGE_img_2;
	lv_obj_t *HOME_PAGE_img_1;
	lv_obj_t *HOME_PAGE_led_1;
	lv_obj_t *HOME_PAGE_img_3;
	lv_obj_t *HOME_PAGE_img_4;
	lv_obj_t *HOME_PAGE_img_5;
	lv_obj_t *HOME_MENU;
	bool HOME_MENU_del;
	lv_obj_t *HOME_MENU_cont_menu_set;
	lv_obj_t *HOME_MENU_btn_menu_home;
	lv_obj_t *HOME_MENU_btn_menu_home_label;
	lv_obj_t *HOME_MENU_btn_menu_back;
	lv_obj_t *HOME_MENU_btn_menu_back_label;
	lv_obj_t *HOME_MENU_label_menu;
	lv_obj_t *HOME_MENU_cont_menu_function;
	lv_obj_t *HOME_MENU_tileview_1;
	lv_obj_t *HOME_MENU_tileview_1_tile;
	lv_obj_t *HOME_MENU_label_menu_Config;
	lv_obj_t *HOME_MENU_btn_menu_config;
	lv_obj_t *HOME_MENU_btn_menu_config_label;
	lv_obj_t *HOME_MENU_btn_menu_protect;
	lv_obj_t *HOME_MENU_btn_menu_protect_label;
	lv_obj_t *HOME_MENU_label_menu_Protect;
	lv_obj_t *HOME_MENU_label_menu_Measure;
	lv_obj_t *HOME_MENU_label_menu_Trigger;
	lv_obj_t *HOME_MENU_label_menu_Recall;
	lv_obj_t *HOME_MENU_label_menu_Save;
	lv_obj_t *HOME_MENU_label_menu_Meter;
	lv_obj_t *HOME_MENU_label_menu_Recorder;
	lv_obj_t *HOME_MENU_label_menu_Function;
	lv_obj_t *HOME_MENU_label_menu_Delays;
	lv_obj_t *HOME_MENU_label_menu_Coupling;
	lv_obj_t *HOME_MENU_label_menu_Group;
	lv_obj_t *HOME_MENU_btn_menu_measure;
	lv_obj_t *HOME_MENU_btn_menu_measure_label;
	lv_obj_t *HOME_MENU_btn_menu_trigger;
	lv_obj_t *HOME_MENU_btn_menu_trigger_label;
	lv_obj_t *HOME_MENU_btn_menu_recall;
	lv_obj_t *HOME_MENU_btn_menu_recall_label;
	lv_obj_t *HOME_MENU_btn_menu_save;
	lv_obj_t *HOME_MENU_btn_menu_save_label;
	lv_obj_t *HOME_MENU_btn_menu_meter;
	lv_obj_t *HOME_MENU_btn_menu_meter_label;
	lv_obj_t *HOME_MENU_btn_menu_recorder;
	lv_obj_t *HOME_MENU_btn_menu_recorder_label;
	lv_obj_t *HOME_MENU_btn_menu_function;
	lv_obj_t *HOME_MENU_btn_menu_function_label;
	lv_obj_t *HOME_MENU_btn_menua_delays;
	lv_obj_t *HOME_MENU_btn_menua_delays_label;
	lv_obj_t *HOME_MENU_btn_menu_coupling;
	lv_obj_t *HOME_MENU_btn_menu_coupling_label;
	lv_obj_t *HOME_MENU_btn_menu_group;
	lv_obj_t *HOME_MENU_btn_menu_group_label;
	lv_obj_t *HOME_MENU_line_1;
	lv_obj_t *HOME_MENU_btn_menu_general;
	lv_obj_t *HOME_MENU_btn_menu_general_label;
	lv_obj_t *HOME_MENU_label_menu_general;
	lv_obj_t *HOME_MENU_btn_menu_communication;
	lv_obj_t *HOME_MENU_btn_menu_communication_label;
	lv_obj_t *HOME_MENU_label_menu_Communication;
	lv_obj_t *HOME_MENU_btn_menu_digital_io;
	lv_obj_t *HOME_MENU_btn_menu_digital_io_label;
	lv_obj_t *HOME_MENU_btn_menu_preference;
	lv_obj_t *HOME_MENU_btn_menu_preference_label;
	lv_obj_t *HOME_MENU_label_menu_Digital_io;
	lv_obj_t *HOME_MENU_label_menu_Preference;
	lv_obj_t *HOME_MENU_btn_menu_log;
	lv_obj_t *HOME_MENU_btn_menu_log_label;
	lv_obj_t *HOME_MENU_label_menu_Log;
	lv_obj_t *HOME_MENU_btn_menu_admin;
	lv_obj_t *HOME_MENU_btn_menu_admin_label;
	lv_obj_t *HOME_MENU_label_menu_Admin;
	lv_obj_t *HOME_MENU_btn_menu_info;
	lv_obj_t *HOME_MENU_btn_menu_info_label;
	lv_obj_t *HOME_MENU_label_menu_Info;
	lv_obj_t *HOME_MENU_btn_menu_energy;
	lv_obj_t *HOME_MENU_btn_menu_energy_label;
	lv_obj_t *HOME_MENU_label_menu_Energy;
	lv_obj_t *HOME_MENU_btn_menu_date;
	lv_obj_t *HOME_MENU_btn_menu_date_label;
	lv_obj_t *HOME_MENU_label_menu_Date;
	lv_obj_t *HOME_MENU_label_1;
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
void setup_scr_HOME_MENU(lv_ui *ui);
LV_IMG_DECLARE(_Logo_alpha_569x159);
LV_IMG_DECLARE(_Icons_Menu_alpha_46x44);
LV_IMG_DECLARE(_keyback_alpha_245x40);
LV_IMG_DECLARE(_kk_alpha_37x36);
LV_IMG_DECLARE(_suo_alpha_30x30);
LV_IMG_DECLARE(_beep_alpha_32x30);
LV_IMG_DECLARE(_usb3_alpha_47x34);

LV_IMG_DECLARE(_home_50x50);

LV_IMG_DECLARE(_back2_60x60);

LV_IMG_DECLARE(_config2_95x95);

LV_IMG_DECLARE(_protect_95x95);

LV_IMG_DECLARE(_measure2_95x95);

LV_IMG_DECLARE(_Trigger2_100x99);

LV_IMG_DECLARE(_recall_99x97);

LV_IMG_DECLARE(_save_98x95);

LV_IMG_DECLARE(_meter_99x95);

LV_IMG_DECLARE(_recorder_99x99);

LV_IMG_DECLARE(_function_100x96);

LV_IMG_DECLARE(_delays_98x95);

LV_IMG_DECLARE(_coupling_107x104);

LV_IMG_DECLARE(_group_100x96);

LV_IMG_DECLARE(_General_99x95);

LV_IMG_DECLARE(_communication_98x99);

LV_IMG_DECLARE(_digital_io3_101x100);

LV_IMG_DECLARE(_preference_98x95);

LV_IMG_DECLARE(_log_99x95);

LV_IMG_DECLARE(_admin_100x99);

LV_IMG_DECLARE(_info_100x95);

LV_IMG_DECLARE(_Energy_97x93);

LV_IMG_DECLARE(_date_99x94);

LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_35)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_16)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_30)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_110)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_140)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_40)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_23)


#ifdef __cplusplus
}
#endif
#endif
