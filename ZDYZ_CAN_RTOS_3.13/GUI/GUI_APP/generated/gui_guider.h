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
	lv_obj_t *HOME_PAGE_label_1;
	lv_obj_t *HOME_PAGE_label_2;
	lv_obj_t *HOME_PAGE_btn_Menu;
	lv_obj_t *HOME_PAGE_btn_Menu_label;
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
	lv_obj_t *HOME_MENU_shared_sidebar;
	lv_obj_t *HOME_MENU_label_menu;
	lv_obj_t *HOME_MENU_img_menu_back;
	lv_obj_t *HOME_MENU_img_menu_home;
	lv_obj_t *HOME_MENU_btn_menu_home;
	lv_obj_t *HOME_MENU_btn_menu_home_label;
	lv_obj_t *HOME_MENU_btn_menu_back;
	lv_obj_t *HOME_MENU_btn_menu_back_label;
	lv_obj_t *HOME_MENU_cont_menu_function;
	lv_obj_t *HOME_MENU_cont_1;
	lv_obj_t *HOME_MENU_label_menu_Config;
	lv_obj_t *HOME_MENU_label_menu_Protect;
	lv_obj_t *HOME_MENU_btn_menu_config;
	lv_obj_t *HOME_MENU_btn_menu_config_label;
	lv_obj_t *HOME_MENU_btn_menu_protect;
	lv_obj_t *HOME_MENU_btn_menu_protect_label;
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
	lv_obj_t *HOME_MENU_img_protect;
	lv_obj_t *HOME_MENU_img_measure;
	lv_obj_t *HOME_MENU_img_trigger;
	lv_obj_t *HOME_MENU_img_save;
	lv_obj_t *HOME_MENU_img_recall;
	lv_obj_t *HOME_MENU_img_recorder;
	lv_obj_t *HOME_MENU_img_function;
	lv_obj_t *HOME_MENU_img_delays;
	lv_obj_t *HOME_MENU_img_coupling;
	lv_obj_t *HOME_MENU_img_group;
	lv_obj_t *HOME_MENU_img_general;
	lv_obj_t *HOME_MENU_img_digital_io;
	lv_obj_t *HOME_MENU_img_preference;
	lv_obj_t *HOME_MENU_img_log;
	lv_obj_t *HOME_MENU_img_admin;
	lv_obj_t *HOME_MENU_img_communication;
	lv_obj_t *HOME_MENU_img_info;
	lv_obj_t *HOME_MENU_img_energy;
	lv_obj_t *HOME_MENU_img_date;
	lv_obj_t *HOME_MENU_img_config;
	lv_obj_t *HOME_MENU_img_meter;
	lv_obj_t *Menu_Config;
	bool Menu_Config_del;
	lv_obj_t *Menu_Config_cont;
	lv_obj_t *Menu_Protect;
	bool Menu_Protect_del;
	lv_obj_t *Menu_Protect_cont;
	lv_obj_t *Menu_Measure;
	bool Menu_Measure_del;
	lv_obj_t *Menu_Measure_cont;
	lv_obj_t *Menu_Trigger;
	bool Menu_Trigger_del;
	lv_obj_t *Menu_Trigger_cont;
	lv_obj_t *Menu_Recall;
	bool Menu_Recall_del;
	lv_obj_t *Menu_Recall_cont;
	lv_obj_t *Menu_Save;
	bool Menu_Save_del;
	lv_obj_t *Menu_Save_cont;
	lv_obj_t *Menu_Meter;
	bool Menu_Meter_del;
	lv_obj_t *Menu_Meter_cont;
	lv_obj_t *Menu_Recorder;
	bool Menu_Recorder_del;
	lv_obj_t *Menu_Recorder_cont;
	lv_obj_t *Menu_Function;
	bool Menu_Function_del;
	lv_obj_t *Menu_Function_cont;
	lv_obj_t *Menu_Delays;
	bool Menu_Delays_del;
	lv_obj_t *Menu_Delays_cont;
	lv_obj_t *Menu_Coupling;
	bool Menu_Coupling_del;
	lv_obj_t *Menu_Coupling_cont;
	lv_obj_t *Menu_Group;
	bool Menu_Group_del;
	lv_obj_t *Menu_Group_cont;
	lv_obj_t *Menu_General;
	bool Menu_General_del;
	lv_obj_t *Menu_General_cont;
	lv_obj_t *Menu_Digital_IO;
	bool Menu_Digital_IO_del;
	lv_obj_t *Menu_Digital_IO_cont;
	lv_obj_t *Menu_Preference;
	bool Menu_Preference_del;
	lv_obj_t *Menu_Preference_cont;
	lv_obj_t *Menu_Log;
	bool Menu_Log_del;
	lv_obj_t *Menu_Log_cont;
	lv_obj_t *Menu_Admin;
	bool Menu_Admin_del;
	lv_obj_t *Menu_Admin_cont;
	lv_obj_t *Menu_Communication;
	bool Menu_Communication_del;
	lv_obj_t *Menu_Communication_cont;
	lv_obj_t *Menu_Info;
	bool Menu_Info_del;
	lv_obj_t *Menu_Info_cont;
	lv_obj_t *Menu_Energy;
	bool Menu_Energy_del;
	lv_obj_t *Menu_Energy_cont;
	lv_obj_t *Menu_Date;
	bool Menu_Date_del;
	lv_obj_t *Menu_Date_cont;
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
void setup_scr_Menu_Config(lv_ui *ui);
void setup_scr_Menu_Protect(lv_ui *ui);
void setup_scr_Menu_Measure(lv_ui *ui);
void setup_scr_Menu_Trigger(lv_ui *ui);
void setup_scr_Menu_Recall(lv_ui *ui);
void setup_scr_Menu_Save(lv_ui *ui);
void setup_scr_Menu_Meter(lv_ui *ui);
void setup_scr_Menu_Recorder(lv_ui *ui);
void setup_scr_Menu_Function(lv_ui *ui);
void setup_scr_Menu_Delays(lv_ui *ui);
void setup_scr_Menu_Coupling(lv_ui *ui);
void setup_scr_Menu_Group(lv_ui *ui);
void setup_scr_Menu_General(lv_ui *ui);
void setup_scr_Menu_Digital_IO(lv_ui *ui);
void setup_scr_Menu_Preference(lv_ui *ui);
void setup_scr_Menu_Log(lv_ui *ui);
void setup_scr_Menu_Admin(lv_ui *ui);
void setup_scr_Menu_Communication(lv_ui *ui);
void setup_scr_Menu_Info(lv_ui *ui);
void setup_scr_Menu_Energy(lv_ui *ui);
void setup_scr_Menu_Date(lv_ui *ui);
LV_IMG_DECLARE(_Logo_alpha_569x159);
LV_IMG_DECLARE(_Icons_Menu_alpha_46x44);
LV_IMG_DECLARE(_keyback_alpha_245x40);
LV_IMG_DECLARE(_kk_alpha_37x36);
LV_IMG_DECLARE(_suo_alpha_30x30);
LV_IMG_DECLARE(_beep_alpha_32x30);
LV_IMG_DECLARE(_usb3_alpha_47x34);
LV_IMG_DECLARE(_back1_alpha_60x60);
LV_IMG_DECLARE(_home_alpha_60x60);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);

LV_IMG_DECLARE(_base3_95x95);
LV_IMG_DECLARE(_protect_alone_alpha_70x70);
LV_IMG_DECLARE(_measure_alone_alpha_70x70);
LV_IMG_DECLARE(_trigger_alone_2_alpha_70x70);
LV_IMG_DECLARE(_save_alone_alpha_70x70);
LV_IMG_DECLARE(_recall_alone_alpha_70x70);
LV_IMG_DECLARE(_recoder_alone_alpha_70x70);
LV_IMG_DECLARE(_Function_alone_alpha_70x70);
LV_IMG_DECLARE(_delays_alone_alpha_70x70);
LV_IMG_DECLARE(_coupling_alone_alpha_70x70);
LV_IMG_DECLARE(_group_alone_alpha_70x70);
LV_IMG_DECLARE(_general_alone_alpha_70x70);
LV_IMG_DECLARE(_Digital_io_alone_alpha_70x70);
LV_IMG_DECLARE(_perfect_alone_alpha_70x70);
LV_IMG_DECLARE(_log_alone_alpha_70x70);
LV_IMG_DECLARE(_admin_alone_alpha_70x70);
LV_IMG_DECLARE(_communication_alone_alpha_70x70);
LV_IMG_DECLARE(_info_alone_alpha_70x70);
LV_IMG_DECLARE(_energy_alone_alpha_70x70);
LV_IMG_DECLARE(_date_alone_alpha_70x70);
LV_IMG_DECLARE(_config_alone_alpha_70x70);
LV_IMG_DECLARE(_meter2_alpha_70x70);

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
