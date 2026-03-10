#ifndef _BTN_TREE_H_
#define _BTN_TREE_H_

#include "tree.h"
#include "lvgl.h"
#include "MultString.h"

/* ----------------------------------------------------------------            
    1. 核心结构体定义 (搬迁自 VirtualBtnm.h)
   ---------------------------------------------------------------- */

// 节点功能类型
enum {
    BTN_TYPE_NONE = 0,
    BTN_TYPE_SEL,    // 对象选择类型 (聚焦并进入编辑)
    BTN_TYPE_UI,     // 页面切换类型
    BTN_TYPE_CALL,   // 直接函数调用类型
    BTN_TYPE_KEY,    // 纯按键转发类型
};


// 树节点关联的元数据
struct BtnInfo_Def {
    const MultStr_Def* multStr;   // 多语言名称 (用于 Tree_Print 打印调试)
    uint8_t type;                 // 节点类型 (如 BTN_TYPE_SEL)
    lv_obj_t **obj;               // 指向 LVGL 对象的指针地址
    lv_event_cb_t evencb;         // 该节点触发时要绑定的回调函数
    void (*ui_enter)(void);       // 页面进入时的初始化函数
    void (*ui_exit)(void);        // 页面退出时的清理函数
    void (*call)(void);           // 动作类型节点的直接执行函数
    lv_key_t key_short;           // 绑定的短按键逻辑
    lv_key_t key_long;            // 绑定的长按键逻辑
    uint8_t noVisable;            // 逻辑隐藏标记
};

/* ----------------------------------------------------------------            
    2. 页面枚举定义
   ---------------------------------------------------------------- */

enum {
    PAGE_NULL = 0,
    PAGE_HOME,
    PAGE_HOME2,
    PAGE_LIST,
    PAGE_LIST_TEMP,
    PAGE_LIST_MANAGER,

    PAGE_DELAY,
    PAGE_DELAY_TEMP,
    PAGE_DELAY_MANAGER,

    PAGE_PRESET,
    PAGE_MENU,
    PAGE_MONITOR,
    PAGE_OUTOPTION,
    PAGE_SETTING,
    PAGE_GROUP,
    PAGE_BATTESTER,

    PAGE_MIN = PAGE_HOME,
    PAGE_MAX = PAGE_BATTESTER,
};

/* ----------------------------------------------------------------            
    3. 核心控制接口 (Logic Controller)
   ---------------------------------------------------------------- */

/**
 * @brief  初始化 UI 树结构
 */
Tree_Def *UI_Tree_Init(void);

/**
 * @brief  系统级按键分发器 (由物理按键驱动调用)
 */
uint8_t System_Key_Process(lv_key_t key);

/**
 * @brief  树系统总事件回调 (处理按键转发与退出)
 */
void btnTree_event_handler(lv_event_t * e);

/**
 * @brief  进入指定节点 (自动聚焦对象并绑定事件)
 */
void Tree_UI_Sel_Enter(Tree_Def *node, uint8_t longFlag);

/**
 * @brief  退出当前选中节点 (解除聚焦并清空 selNode)
 */
void Tree_UI_Sel_Exit(void);

/**
 * @brief  页面切换接口
 */
void UI_Switch_Page(uint8_t page);

/**
 * @brief  通过 LVGL 对象反向获取树节点 (非常有用：触摸点击 UI 直接进入节点)
 */
Tree_Def *Tree_UI_GetNode_ByObj(Tree_Def *tree, lv_obj_t *obj);

/**
 * @brief  打印整个树结构 (后期调试利器)
 */
void Tree_Print(Tree_Def *tree, uint16_t deepth);

/* ----------------------------------------------------------------            
    4. 全局外部变量声明
   ---------------------------------------------------------------- */

// 常用树节点指针
extern Tree_Def *tree_home;
extern Tree_Def *tree_menu;
extern Tree_Def *tree_monitor;
extern Tree_Def *tree_outoption;
extern Tree_Def *tree_setting;
extern Tree_Def *tree_group;
extern Tree_Def *tree_language;

// 业务功能节点 (直达快捷键使用)
extern Tree_Def *tree_VSet;
extern Tree_Def *tree_ISet;
extern Tree_Def *tree_SR_Set;
extern Tree_Def *tree_VSR_Up_Set;
extern Tree_Def *tree_VSR_Dn_Set;
extern Tree_Def *tree_ISR_Up_Set;
extern Tree_Def *tree_ISR_Dn_Set;

// 业务元数据定义
extern const struct BtnInfo_Def btn_home;
extern struct BtnInfo_Def btn_SR_Set;
extern struct BtnInfo_Def btn_VSR_Rising;
extern struct BtnInfo_Def btn_VSR_Failing;
extern struct BtnInfo_Def btn_ISR_Rising;
extern struct BtnInfo_Def btn_ISR_Failing;

#endif
