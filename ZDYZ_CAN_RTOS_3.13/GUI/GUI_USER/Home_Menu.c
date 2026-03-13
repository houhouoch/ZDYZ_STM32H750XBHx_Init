#include "Home_Menu.h"
#include "Gui_Task.h"
#include "HomePage_LED.h"
#include "./User/power_interface.h"

/* --- 静态变量与私有声明 --- */
static lv_group_t * main_nav_group = NULL;
static lv_style_t style_focus_border;

static void menu_btn_direct_enter_handler(lv_event_t * e);
static void sidebar_common_event_handler(lv_event_t * e);

/**
 * @brief 内部辅助：统一管理菜单中的 21 个按钮及图标
 * 所有的对象指针集中在这里维护，方便后续循环处理
 */
static uint32_t _get_menu_btns(lv_obj_t ** btns, lv_obj_t ** imgs) {
    if(btns) {
        btns[0] = ui.HOME_MENU_btn_menu_config;    btns[1] = ui.HOME_MENU_btn_menu_protect;
        btns[2] = ui.HOME_MENU_btn_menu_measure;   btns[3] = ui.HOME_MENU_btn_menu_trigger;
        btns[4] = ui.HOME_MENU_btn_menu_recall;    btns[5] = ui.HOME_MENU_btn_menu_save;
        btns[6] = ui.HOME_MENU_btn_menu_meter;     btns[7] = ui.HOME_MENU_btn_menu_recorder;
        btns[8] = ui.HOME_MENU_btn_menu_function;  btns[9] = ui.HOME_MENU_btn_menua_delays;
        btns[10] = ui.HOME_MENU_btn_menu_coupling; btns[11] = ui.HOME_MENU_btn_menu_group;
        btns[12] = ui.HOME_MENU_btn_menu_general;  btns[13] = ui.HOME_MENU_btn_menu_digital_io;
        btns[14] = ui.HOME_MENU_btn_menu_preference; btns[15] = ui.HOME_MENU_btn_menu_log;
        btns[16] = ui.HOME_MENU_btn_menu_admin;    btns[17] = ui.HOME_MENU_btn_menu_communication;
        btns[18] = ui.HOME_MENU_btn_menu_info;     btns[19] = ui.HOME_MENU_btn_menu_energy;
        btns[20] = ui.HOME_MENU_btn_menu_date;
    }
    if(imgs) {
        imgs[0] = ui.HOME_MENU_img_config;    imgs[1] = ui.HOME_MENU_img_protect;
        imgs[2] = ui.HOME_MENU_img_measure;   imgs[3] = ui.HOME_MENU_img_trigger;
        imgs[4] = ui.HOME_MENU_img_recall;    imgs[5] = ui.HOME_MENU_img_save;
        imgs[6] = ui.HOME_MENU_img_meter;     imgs[7] = ui.HOME_MENU_img_recorder;
        imgs[8] = ui.HOME_MENU_img_function;  imgs[9] = ui.HOME_MENU_img_delays;
        imgs[10] = ui.HOME_MENU_img_coupling; imgs[11] = ui.HOME_MENU_img_group;
        imgs[12] = ui.HOME_MENU_img_general;  imgs[13] = ui.HOME_MENU_img_digital_io;
        imgs[14] = ui.HOME_MENU_img_preference; imgs[15] = ui.HOME_MENU_img_log;
        imgs[16] = ui.HOME_MENU_img_admin;    imgs[17] = ui.HOME_MENU_img_communication;
        imgs[18] = ui.HOME_MENU_img_info;     imgs[19] = ui.HOME_MENU_img_energy;
        imgs[20] = ui.HOME_MENU_img_date;
    }
    return 21;
}

/* --- 1. 事件处理模块 --- */

/**
 * @brief 主菜单按钮点击：实现“点哪进哪”，并防止递归触发
 */
static void menu_btn_direct_enter_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);
    lv_indev_t * indev = lv_event_get_indev(e);

    if(code == LV_EVENT_CLICKED) 
    {
        // 关键防护：如果不是真实的物理触摸（indev为NULL），不执行跳转逻辑，防止重复打印
        if(indev == NULL) return; 

        Tree_Def * target_node = Tree_UI_GetNode_ByObj(tree_menu, obj);
        if(target_node != NULL) {
            printf("[Menu] Direct Enter -> Target Node Found\n");
            Tree_UI_Sel_Enter(target_node, 0); 
        }
    }
}

/**
 * @brief 侧边栏回调：将触摸点击转化为全局物理按键事件
 */
static void sidebar_common_event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    if(lv_event_get_code(e) == LV_EVENT_CLICKED) 
    {
        lv_key_t key = LV_KEY_DEFAULT;
        if(obj == ui.HOME_MENU_btn_menu_back) key = LV_KEY_ESC;
        else if(obj == ui.HOME_MENU_btn_menu_home) key = LV_KEY_HOME;

        if(key != LV_KEY_DEFAULT) {
            lv_event_send(ui.Back_cont_back, LV_EVENT_KEY, &key);
            printf("[Sidebar] Redirect Touch to Key: %d\n", key);
        }
    }
}

/* --- 2. 导航与样式模块 --- */

void nav_style_init(void)
{
    lv_style_init(&style_focus_border);
    lv_style_set_border_width(&style_focus_border, 3);
    lv_style_set_border_color(&style_focus_border, lv_color_hex(0x00AEEF));
    lv_style_set_border_opa(&style_focus_border, 255);
    lv_style_set_shadow_width(&style_focus_border, 10);
    lv_style_set_shadow_color(&style_focus_border, lv_color_hex(0x00AEEF));
}

/**
 * @brief 核心初始化：绑定事件、禁用图标点击、加入导航组
 */
void Home_Menu_Buttons_Events_Init(lv_ui *p_ui)
{
    lv_obj_t * btns[21];
    lv_obj_t * imgs[21];
    uint32_t cnt = _get_menu_btns(btns, imgs);

    // 1. 创建导航组（兼容物理按键）
    if(main_nav_group == NULL) main_nav_group = lv_group_create();

    for(uint32_t i = 0; i < cnt; i++) {
        if(btns[i] == NULL) continue;

        // A. 绑定进入逻辑 (先删后加，双重保险)
        lv_obj_remove_event_cb(btns[i], menu_btn_direct_enter_handler);
        lv_obj_add_event_cb(btns[i], menu_btn_direct_enter_handler, LV_EVENT_CLICKED, NULL);

        // B. 加入导航组以支持编码器，并应用高亮样式
        lv_group_add_obj(main_nav_group, btns[i]);
        lv_obj_add_style(btns[i], &style_focus_border, LV_STATE_FOCUSED);

        // C. 彻底禁用图标点击属性，确保点击按钮时信号不被拦截
        if(imgs[i]) lv_obj_clear_flag(imgs[i], LV_OBJ_FLAG_CLICKABLE);
    }

    // 2. 绑定侧边栏功能
    lv_obj_remove_event_cb(p_ui->HOME_MENU_btn_menu_back, sidebar_common_event_handler);
    lv_obj_add_event_cb(p_ui->HOME_MENU_btn_menu_back, sidebar_common_event_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_remove_event_cb(p_ui->HOME_MENU_btn_menu_home, sidebar_common_event_handler);
    lv_obj_add_event_cb(p_ui->HOME_MENU_btn_menu_home, sidebar_common_event_handler, LV_EVENT_CLICKED, NULL);

    printf("[System] Menu Management System Initialized.\n");
}

/**
 * @brief 按键分发接口 (对接编码器)
 */
void nav_process_key(lv_event_t * e)
{
    if(main_nav_group == NULL || lv_event_get_code(e) != LV_EVENT_KEY) return;
    
    lv_key_t key = lv_event_get_key(e);
    switch(key) {
        case LV_KEY_RIGHT: case LV_KEY_UP:   lv_group_focus_next(main_nav_group); break;
        case LV_KEY_LEFT:  case LV_KEY_DOWN: lv_group_focus_prev(main_nav_group); break;
        case LV_KEY_ENTER: {
            lv_obj_t * focused_obj = lv_group_get_focused(main_nav_group);
            if(focused_obj) {
                Tree_Def * target = Tree_UI_GetNode_ByObj(tree_menu, focused_obj);
                if(target) Tree_UI_Sel_Enter(target, 0);
            }
            break;
        }
    }
}

/* --- 3. 页面生命周期控制 --- */

void Home_Menu_Enter(void)
{
    lv_obj_clear_flag(ui.HOME_MENU_cont_menu_function, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui.HOME_MENU_cont_menu_set, LV_OBJ_FLAG_HIDDEN);

    // --- 【解决高亮残留的核心代码】 ---
    // 1. 让导航组暂时失去焦点
    if(main_nav_group) lv_group_focus_obj(NULL);

    // 2. 暴力清除第一个按钮的 FOCUSED 状态（防止 indev 自动抓取）
    if(ui.HOME_MENU_btn_menu_config) {
        lv_obj_clear_state(ui.HOME_MENU_btn_menu_config, LV_STATE_FOCUSED);
        lv_obj_invalidate(ui.HOME_MENU_btn_menu_config); 
    }
}

void Home_Menu_Exit(void)
{       
    lv_obj_add_flag(ui.HOME_MENU_cont_menu_function, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui.HOME_MENU_cont_menu_set, LV_OBJ_FLAG_HIDDEN);
}

void Home_Menu_GroupCreate(void)
{
    /* 1. 创建基础UI */
    setup_scr_HOME_MENU(&ui); 
    
    /* 2. 建立层级关系 */
    lv_obj_set_parent(ui.HOME_MENU_cont_menu_function, ui.Back_cont_back);
    lv_obj_set_parent(ui.HOME_MENU_cont_menu_set, ui.Back_cont_back);
    
    /* 3. 核心：样式与事件一键初始化 */
    nav_style_init();
    Home_Menu_Buttons_Events_Init(&ui);

    /* 4. 配置动态侧边栏图标 */
    ui.HOME_MENU_shared_sidebar = lv_img_create(ui.HOME_MENU_cont_menu_set);
    lv_obj_set_pos(ui.HOME_MENU_shared_sidebar, 17, 85);
    lv_obj_set_size(ui.HOME_MENU_shared_sidebar, 70, 70);
    lv_obj_add_flag(ui.HOME_MENU_shared_sidebar, LV_OBJ_FLAG_HIDDEN);

    Home_Menu_Exit(); 
}
