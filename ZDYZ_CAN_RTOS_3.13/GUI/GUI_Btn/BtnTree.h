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
    const void * icon_src;  // --- 新增：存储图标的数据源（如 &_config_70x70） ---
};

/* ----------------------------------------------------------------            
    2. 页面枚举定义
   ---------------------------------------------------------------- */

enum {
    PAGE_NULL = 0,
    PAGE_HOME,
    PAGE_MENU,
    

    PAGE_MENU_Config,  
    PAGE_MENU_Protect,  
    PAGE_MENU_Measure,
    PAGE_MENU_Trigger,
    PAGE_MENU_Recall,
    PAGE_MENU_Save,
    PAGE_MENU_Meter,
    PAGE_MENU_Recorder,
    PAGE_MENU_Function,
    PAGE_MENU_Delays,
    PAGE_MENU_Coupling,
    PAGE_MENU_Group,
    PAGE_MENU_General,
    PAGE_MENU_Digital_IO,
    PAGE_MENU_Preference,
    PAGE_MENU_Log,
    PAGE_MENU_Admin,
    PAGE_MENU_Communication,
    PAGE_MENU_Info,
    PAGE_MENU_Energy,
    PAGE_MENU_Date,

    /* --- 其他独立页面 --- */
    PAGE_BATTESTER,

    /* --- 边界定义 --- */
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
/* ----------------------------------------------------------------            
    1. 核心根节点与主页面
   ---------------------------------------------------------------- */
extern Tree_Def *tree_home;      // 主页
extern Tree_Def *tree_menu;      // 主菜单根节点

/* ----------------------------------------------------------------            
    2. 原始 8 个功能页面节点
   ---------------------------------------------------------------- */
extern Tree_Def *tree_config;    // 系统配置
extern Tree_Def *tree_protect;   // 保护设置
extern Tree_Def *tree_measure;   // 测量分析
extern Tree_Def *tree_trigger;   // 触发控制
extern Tree_Def *tree_recall;    // 文件读取
extern Tree_Def *tree_save;      // 数据保存
extern Tree_Def *tree_meter;     // 仪表模式
extern Tree_Def *tree_recorder;  // 记录仪

/* ----------------------------------------------------------------            
    3. 新增 13 个功能页面节点 (对应你的 13 个 setup_scr 函数)
   ---------------------------------------------------------------- */
extern Tree_Def *tree_function;       // 辅助功能
extern Tree_Def *tree_delays;         // 延时设置
extern Tree_Def *tree_coupling;       // 耦合控制
extern Tree_Def *tree_group;          // 分组管理
extern Tree_Def *tree_general;        // 通用设置
extern Tree_Def *tree_digital_io;     // 数字 I/O
extern Tree_Def *tree_preference;     // 用户偏好
extern Tree_Def *tree_log;            // 系统日志
extern Tree_Def *tree_admin;          // 管理员权限
extern Tree_Def *tree_communication;  // 通讯配置
extern Tree_Def *tree_info;           // 设备信息
extern Tree_Def *tree_energy;         // 能量统计
extern Tree_Def *tree_date;           // 日期时间

/* ----------------------------------------------------------------            
    4. 独立业务页面
   ---------------------------------------------------------------- */
extern Tree_Def *tree_battester;      // 电池测试页面



// 业务功能节点 (直达快捷键使用)
extern Tree_Def *tree_VSet;
extern Tree_Def *tree_ISet;
extern Tree_Def *tree_ISet_neg;
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
