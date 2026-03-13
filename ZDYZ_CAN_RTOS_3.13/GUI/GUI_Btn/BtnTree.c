#include "BtnTree.h"
#include <string.h>
#include <stdio.h>
#include "HomePage.h"
#include "Home_Menu.h"
#include "All_Pages_Includes.h"



/* ----------------------------------------------------------------            
    1. 静态变量与结构体定义
   ---------------------------------------------------------------- */

// 树 UI 管理状态结构体
typedef struct {
    Tree_Def *curNode;      // 当前菜单层级节点
    Tree_Def *selNode;      // 当前选中的交互对象节点 (如选中的 Edit 控件)
    Tree_Def *uiNode;       // 当前所在的页面节点 (如 PAGE_HOME 根节点)
} Tree_UI_Def;

static Tree_UI_Def tree_ui = {0};

// 用于调试查看申请的树节点内存数量
extern uint16_t Tree_NodeCount; 

/* ----------------------------------------------------------------            
    2. 辅助与调试工具
   ---------------------------------------------------------------- */

/*!
 * @brief   打印树结构 (保留用于调试)
 */
void Tree_Print(Tree_Def *tree, uint16_t deepth)
{
    if(tree != NULL)
    {
        for(uint16_t i = 0; i < deepth; ++i)
        {
            Tree_Printf("    ");
        }
        if(tree->pdata != NULL)
        {
            // 获取多国语言字符串并打印
            Tree_Printf("[%s]\r\n", MultStr_GetS(tree->pdata->multStr));
        }
        if(tree->child != NULL) {
            Tree_Print(tree->child, deepth + 1);
        }
        if(tree->next != NULL) {
            Tree_Print(tree->next, deepth);
        }
    }
}

/**
 * @brief 递归向 UI 对象及其子对象发送事件 
 */
void lv_event_send_recursive(lv_obj_t * obj, lv_event_code_t code, void * param)
{
    if(obj == NULL) return;

    // 1. 给自己发送事件
    lv_event_send(obj, code, param);

    // 2. 遍历并给所有子对象发送
    uint32_t i;
    uint32_t child_cnt = lv_obj_get_child_cnt(obj);
    for(i = 0; i < child_cnt; i++) {
        lv_obj_t * child = lv_obj_get_child(obj, i);
        lv_event_send_recursive(child, code, param);
    }
}

/* ----------------------------------------------------------------            
    3. 核心节点操作 (Enter / Exit)
   ---------------------------------------------------------------- */

/**
 * @brief 退出/返回逻辑：实现“退出编辑 -> 返回父级”的二级跳
 */
void Tree_UI_Sel_Exit(void)
{
    // 1. 获取当前选中的交互对象（比如正在改电压的那个数字）
    Tree_Def *temp_selNode = tree_ui.selNode;

    // --- 第一阶段：如果当前正在“选中/编辑”某个控件 ---
    if(temp_selNode != NULL)
    {
        if(temp_selNode->pdata && temp_selNode->pdata->obj && *temp_selNode->pdata->obj)
        {
            lv_obj_t * obj = *temp_selNode->pdata->obj;
            // 清除聚焦和编辑状态
            lv_obj_clear_state(obj, LV_STATE_FOCUSED | LV_STATE_EDITED);
            lv_event_send(obj, LV_EVENT_DEFOCUSED, NULL);
            lv_obj_invalidate(obj); // 强制重绘，去掉高亮框
        }
        
        // 关键：清空选中记录
        tree_ui.selNode = NULL;

        // 【高手注意】：如果你希望“退出编辑”和“返回上一页”分两步走
        // 那么这里就 return。这样用户按第一次 ESC 只是关掉光标。
        printf("[Tree] Exit Edit Mode\n");
        return; 
    }

    // --- 第二阶段：如果当前没有选中控件，则执行“返回上一级页面” ---
    // 逻辑：寻找当前所在的 UI 页面（uiNode）或者 逻辑层级（curNode）的父节点
    Tree_Def *target_parent = NULL;

    if(tree_ui.uiNode && tree_ui.uiNode->parent) {
        target_parent = tree_ui.uiNode->parent;
    } else if(tree_ui.curNode && tree_ui.curNode->parent) {
        target_parent = tree_ui.curNode->parent;
    }

    if(target_parent != NULL)
    {
        printf("[Tree] ESC Back to Parent: %s\n", MultStr_GetS(target_parent->pdata->multStr));
        
        // 核心：调用进入函数切换回父节点
        // 这会自动触发我们之前写的：隐藏图标、显示"Menu"文字等逻辑
        Tree_UI_Sel_Enter(target_parent, 0);
    }
    else
    {
        printf("[Tree] Already at Root, nowhere to go.\n");
    }
}
/*!
 * @brief  进入节点逻辑 (核心)
 */
void Tree_UI_Sel_Enter(Tree_Def *node, uint8_t longFlag)
{
    if(node == NULL || node->pdata == NULL) return;
   // printf("Entering Node: %p, Type: %d\n", node, node->pdata->type);
    // A. 自动冲突处理：如果当前在编辑 A，现在点 B，先安全退出 A
    if((tree_ui.selNode != NULL) && (tree_ui.selNode != node))
    {
        Tree_UI_Sel_Exit();
    }

    const struct BtnInfo_Def *pdata = node->pdata;

    switch(pdata->type)
    {
        // 1. 对象选择类型 (如电压输入框)
        case BTN_TYPE_SEL: 
        {
            if(pdata->obj != NULL && *pdata->obj != NULL)
            {
                lv_obj_t * obj = *pdata->obj;
                tree_ui.selNode = node;

                // --- 自动绑定回调 (适配 v8.3) ---
                if(pdata->evencb != NULL) {
                    lv_obj_remove_event_cb(obj, pdata->evencb);
                    lv_obj_add_event_cb(obj, pdata->evencb, LV_EVENT_ALL, NULL);
                }

                // --- 设置交互状态 ---
                lv_obj_add_state(obj, LV_STATE_FOCUSED);
                lv_event_send(obj, LV_EVENT_FOCUSED, NULL); // 触发业务层的初始化(如光标位置)
                lv_event_send(obj, LV_EVENT_CLICKED, NULL);

                // 发送关联按键 (模拟进入即按下某键)
                lv_key_t key = (longFlag == 0) ? pdata->key_short : pdata->key_long;
                if(key != LV_KEY_DEFAULT) {
                    lv_event_send(obj, LV_EVENT_KEY, &key);
                }

                lv_obj_invalidate(obj);
            }
        }
        break;

        // 2. 界面切换类型 (Page Switch)
//        case BTN_TYPE_UI: 
//        {
//            if(tree_ui.uiNode != node) 
//            {
//                // 如果不是子节点且当前有页面，执行旧页面的 Exit
//                if(tree_ui.uiNode != NULL && Tree_IsChild(tree_ui.uiNode, node) == 0)
//                {
//                    if(tree_ui.uiNode->pdata->ui_exit != NULL) {
//                        tree_ui.uiNode->pdata->ui_exit();
//                    }
//                }
//                
//                // 执行新页面的 Enter
//                if(pdata->ui_enter != NULL) {
//                    pdata->ui_enter();
//                }
//                tree_ui.uiNode = node;
//              
//                if( ui.HOME_MENU_label_menu != NULL)
//                {
//                    // 情况 A：进入子功能页面 (Config, Protect...)
//                    if(Tree_IsChild(tree_menu, node) && (node != tree_menu)) 
//                    {
//                        lv_obj_add_flag(ui.HOME_MENU_label_menu, LV_OBJ_FLAG_HIDDEN);
//                        if(node->pdata->icon_src) {
//                            lv_img_set_src(ui.shared_sidebar_icon, node->pdata->icon_src);
//                            lv_obj_clear_flag(ui.shared_sidebar_icon, LV_OBJ_FLAG_HIDDEN);
//                        }

//                    } 
//                    // 情况 B：回到主菜单 (tree_menu)
//                    else if(node == tree_menu)
//                    {
//                        lv_obj_add_flag(ui.shared_sidebar_icon, LV_OBJ_FLAG_HIDDEN);

//                        lv_obj_clear_flag(ui.HOME_MENU_label_menu, LV_OBJ_FLAG_HIDDEN);
//                        lv_label_set_text_static(ui.HOME_MENU_label_menu, MultStr_GetS(node->pdata->multStr));
//                    }
//                    // --- 【核心修复：当你点击 Home 按钮时，会跑进这里】 ---
//                    else if(node == tree_home)
//                    {
//                        // 1. 彻底关闭整个菜单 UI 系统
//                        Home_Menu_Exit(); 
//                        
//                        // 2. 隐藏侧边栏所有动态组件
//                        lv_obj_add_flag(ui.shared_sidebar_icon, LV_OBJ_FLAG_HIDDEN);
//                  
//                        lv_obj_add_flag(ui.HOME_MENU_label_menu, LV_OBJ_FLAG_HIDDEN);
//                        
//                        printf("[UI] Cleanup: Menu UI hidden, Back to HomePage\n");
//                    }
//                }

//            }
//        }
//        break;
        case BTN_TYPE_UI: {
            if(tree_ui.uiNode != node) {
                //非子节点,退出UI
                if(0 == Tree_IsChild(tree_ui.uiNode, node))
                {
                    //退出上次UI节点
                    if((tree_ui.uiNode != NULL)
                            && (tree_ui.uiNode->pdata != NULL))
                    {
                        if(tree_ui.uiNode->pdata->ui_exit != NULL)
                        {
                            tree_ui.uiNode->pdata->ui_exit();
                        }
                    }
                }
                //进入新的UI节点
                if(pdata->ui_enter != NULL)
                {
                    pdata->ui_enter();
                }
                tree_ui.uiNode = node;
                if( ui.HOME_MENU_label_menu != NULL)
                {
                    // 情况 A：进入子功能页面 (Config, Protect...)
                    if(Tree_IsChild(tree_menu, node) && (node != tree_menu)) 
                    {
                        lv_obj_add_flag(ui.HOME_MENU_label_menu, LV_OBJ_FLAG_HIDDEN);
                        if(node->pdata->icon_src) {
                            lv_img_set_src(ui.HOME_MENU_shared_sidebar, node->pdata->icon_src);
                            lv_obj_clear_flag(ui.HOME_MENU_shared_sidebar, LV_OBJ_FLAG_HIDDEN);
                        }

                    } 
                    // 情况 B：回到主菜单 (tree_menu)
                    else if(node == tree_menu)
                    {
                        lv_obj_add_flag(ui.HOME_MENU_shared_sidebar, LV_OBJ_FLAG_HIDDEN);

                        lv_obj_clear_flag(ui.HOME_MENU_label_menu, LV_OBJ_FLAG_HIDDEN);
                        lv_label_set_text_static(ui.HOME_MENU_label_menu, MultStr_GetS(node->pdata->multStr));
                        // 即使 Group 内部认为它有焦点，我们通过底层强制去掉它的 FOCUSED 样式状态
                        if(ui.HOME_MENU_btn_menu_config != NULL) {
                            lv_obj_clear_state(ui.HOME_MENU_btn_menu_config, LV_STATE_FOCUSED);
                            
                            // 如果你的样式还带了外发光阴影等，手动发送一个失去焦点事件确保彻底刷新
                            lv_event_send(ui.HOME_MENU_btn_menu_config, LV_EVENT_DEFOCUSED, NULL);
                            
                            // 强制对象立刻重画
                            lv_obj_invalidate(ui.HOME_MENU_btn_menu_config);
                        }

                        printf("[UI] Back to Menu: Focus Force Cleared\n");
                    }
                }
            }
        }
        break;
        // 3. 函数跳转类型
        case BTN_TYPE_CALL: 
        {
            if(pdata->call != NULL) {
                pdata->call();
            }
        }
        break;

        default: break;
    }

    // 更新当前层级指针 (虽然没有底栏，但用于记录逻辑深度)
    if(node->child != NULL) {
        tree_ui.curNode = node;
    }
}

/* ----------------------------------------------------------------            
    4. 页面管理与查找
   ---------------------------------------------------------------- */
static int8_t __curPage = 0;
/**
 * @brief  获取当前页面 ID
 */
uint8_t __Get_CurrentPage(void)
{
    extern Tree_Def *tree_home;
    if(tree_ui.uiNode == tree_home) return PAGE_HOME;else
    if(tree_ui.uiNode == tree_menu) return PAGE_MENU;else
    if(tree_ui.uiNode == tree_config) return PAGE_MENU_Config;else
    if(tree_ui.uiNode == tree_protect)  return PAGE_MENU_Protect;else
    if(tree_ui.uiNode == tree_measure)  return PAGE_MENU_Measure;else
    if(tree_ui.uiNode == tree_trigger)  return PAGE_MENU_Trigger;else
    if(tree_ui.uiNode == tree_recall)   return PAGE_MENU_Recall;else
    if(tree_ui.uiNode == tree_save)     return PAGE_MENU_Save;else
    if(tree_ui.uiNode == tree_meter)    return PAGE_MENU_Meter;else
    if(tree_ui.uiNode == tree_recorder) return PAGE_MENU_Recorder;else       
    if(tree_ui.uiNode == tree_function)      return PAGE_MENU_Function;else
    if(tree_ui.uiNode == tree_delays)        return PAGE_MENU_Delays;else
    if(tree_ui.uiNode == tree_coupling)      return PAGE_MENU_Coupling;else
    if(tree_ui.uiNode == tree_group)         return PAGE_MENU_Group;else
    if(tree_ui.uiNode == tree_general)       return PAGE_MENU_General;else
    if(tree_ui.uiNode == tree_digital_io)    return PAGE_MENU_Digital_IO;else
    if(tree_ui.uiNode == tree_preference)    return PAGE_MENU_Preference;else
    if(tree_ui.uiNode == tree_log)           return PAGE_MENU_Log;else
    if(tree_ui.uiNode == tree_admin)         return PAGE_MENU_Admin;else
    if(tree_ui.uiNode == tree_communication) return PAGE_MENU_Communication;else
    if(tree_ui.uiNode == tree_info)          return PAGE_MENU_Info;else
    if(tree_ui.uiNode == tree_energy)        return PAGE_MENU_Energy;else
    if(tree_ui.uiNode == tree_date)          return PAGE_MENU_Date; else   
    // ... 其他页面判断 ...
    return PAGE_NULL;
}



/**
 * @brief  切换 UI 页面
 */
void UI_Switch_Page(uint8_t page)
{
    if((page < PAGE_MIN) || (PAGE_MAX < page)) return;
    __curPage = __Get_CurrentPage();
    if(__curPage != page) {
        __curPage = page;
    // 这里根据 Page 枚举执行跳转，最终调用 Tree_UI_Sel_Enter
    switch(page) {
            case PAGE_HOME:          Tree_UI_Sel_Enter(tree_home, 0); break;
            case PAGE_MENU:          Tree_UI_Sel_Enter(tree_menu, 0); break;
            case PAGE_MENU_Config:   Tree_UI_Sel_Enter(tree_config, 0); break;
            case PAGE_MENU_Protect:  Tree_UI_Sel_Enter(tree_protect, 0); break;
            case PAGE_MENU_Measure:  Tree_UI_Sel_Enter(tree_measure, 0); break;
            case PAGE_MENU_Trigger:  Tree_UI_Sel_Enter(tree_trigger, 0); break;
            case PAGE_MENU_Recall:   Tree_UI_Sel_Enter(tree_recall, 0); break;
            case PAGE_MENU_Save:     Tree_UI_Sel_Enter(tree_save, 0); break;
            case PAGE_MENU_Meter:    Tree_UI_Sel_Enter(tree_meter, 0); break;
            case PAGE_MENU_Recorder: Tree_UI_Sel_Enter(tree_recorder, 0); break;
            case PAGE_MENU_Function:      Tree_UI_Sel_Enter(tree_function, 0); break;
            case PAGE_MENU_Delays:        Tree_UI_Sel_Enter(tree_delays, 0); break;
            case PAGE_MENU_Coupling:      Tree_UI_Sel_Enter(tree_coupling, 0); break;
            case PAGE_MENU_Group:         Tree_UI_Sel_Enter(tree_group, 0); break;
            case PAGE_MENU_General:       Tree_UI_Sel_Enter(tree_general, 0); break;
            case PAGE_MENU_Digital_IO:    Tree_UI_Sel_Enter(tree_digital_io, 0); break;
            case PAGE_MENU_Preference:    Tree_UI_Sel_Enter(tree_preference, 0); break;
            case PAGE_MENU_Log:           Tree_UI_Sel_Enter(tree_log, 0); break;
            case PAGE_MENU_Admin:         Tree_UI_Sel_Enter(tree_admin, 0); break;
            case PAGE_MENU_Communication: Tree_UI_Sel_Enter(tree_communication, 0); break;
            case PAGE_MENU_Info:          Tree_UI_Sel_Enter(tree_info, 0); break;
            case PAGE_MENU_Energy:        Tree_UI_Sel_Enter(tree_energy, 0); break;
            case PAGE_MENU_Date:          Tree_UI_Sel_Enter(tree_date, 0); break;
        }
    }
}

/**
 * @brief  通过对象反向查找节点 (用于触摸联动)
 */
Tree_Def *Tree_UI_GetNode_ByObj(Tree_Def *tree, lv_obj_t *obj)
{
    if(obj == NULL || tree == NULL) return NULL;

    Tree_Def *node = NULL;
    
    // 检查当前节点
    if(tree->pdata != NULL && tree->pdata->obj != NULL && *tree->pdata->obj == obj) {
        return tree;
    }
    
    // 递归查找子节点
    if(tree->child != NULL) {
        node = Tree_UI_GetNode_ByObj(tree->child, obj);
        if(node != NULL) return node;
    }
    
    // 递归查找后续兄弟节点
    if(tree->next != NULL) {
        node = Tree_UI_GetNode_ByObj(tree->next, obj);
        if(node != NULL) return node;
    }
    
    return NULL;
}

/* ----------------------------------------------------------------            
    5. 按键事件分发 (Bridge)
   ---------------------------------------------------------------- */

/**
 * @brief  按键树总事件处理器 (由 LVGL 回调或 System_Key_Process 转发)
 */
void btnTree_event_handler(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    
    if(event != LV_EVENT_KEY) return;
    
//    /* 1. 获取原始键值 (可能是 17，也可能是 57362) */
//    uint32_t raw_key = lv_event_get_key(e);

//    /* 2. 核心修复：强制标准化处理 */
//    // 无论 LVGL 给不给偏移量，我们只取低 8 位。
//    // 57362 (0xE012) & 0xFF = 18 (标准 LV_KEY_DOWN)
//    // 17 (0x11) & 0xFF = 17 (标准 LV_KEY_UP)
//    lv_key_t key = (lv_key_t)(raw_key & 0x00FF);

    
    lv_key_t key = lv_event_get_key(e);
    
    printf("Tree received key: %d\n", key);
    // 1. 处理退出逻辑 (ESC/返回)
    if(key == LV_KEY_ESC || key == LV_KEY_RETURN) {
        Tree_UI_Sel_Exit();
        return;
    }

    // 2. 拦截系统全局按键 (如电源键、菜单键)
    if(System_Key_Process(key) != 0) {
        return; // 被系统逻辑消耗
    }

    // 3. 按键转发：如果当前有“选中对象”，将按键发给它处理
    if(tree_ui.selNode != NULL) 
    {
        const struct BtnInfo_Def *pdata = tree_ui.selNode->pdata;
        if(pdata->obj != NULL && *pdata->obj != NULL) {
            // 确保回调已挂载
            if(pdata->evencb != NULL) {
                lv_obj_remove_event_cb(*pdata->obj, pdata->evencb);
                lv_obj_add_event_cb(*pdata->obj, pdata->evencb, LV_EVENT_ALL, NULL);
            }
            // 转发按键
            lv_event_send(*pdata->obj, LV_EVENT_KEY, &key);
        }
    } 
    // 4. 如果没有选中对象，则发给当前页面根对象 (Page 级别的处理)
    else if(tree_ui.uiNode != NULL)
    {
        const struct BtnInfo_Def *updata = tree_ui.uiNode->pdata;
        if(updata->obj != NULL && *updata->obj != NULL) {
            lv_event_send(*updata->obj, LV_EVENT_KEY, &key);
        }
    }
}

//递归遍历整棵树，把每一个节点定义的“业务函数”真正挂载到 LVGL 的对象上
/**
 * @brief 递归布线：将树节点定义的 evencb 挂载到实际的 LVGL 对象上
 */
void Tree_UI_Set_EventCb(Tree_Def *tree)
{
    if(tree == NULL) return;

    if(tree->pdata != NULL) {
        const struct BtnInfo_Def *pdata = tree->pdata;
        
        // 如果节点有对象地址，且对象不为空，且定义了回调函数
        if(pdata->obj != NULL && *pdata->obj != NULL && pdata->evencb != NULL) {
            // 先移除旧的回调（防止重复挂载导致的多次触发）
            lv_obj_remove_event_cb(*pdata->obj, pdata->evencb);
            // 挂载新的回调，监听所有事件（LV_EVENT_ALL）
            lv_obj_add_event_cb(*pdata->obj, pdata->evencb, LV_EVENT_ALL, NULL);
        }
    }

    // 递归处理子节点和兄弟节点
    if(tree->child != NULL) Tree_UI_Set_EventCb(tree->child);
    if(tree->next != NULL)  Tree_UI_Set_EventCb(tree->next);
}

void UI_Force_Back_To_Home(void)
{
    // 1. 如果有选中的控件，先退编辑
    if(tree_ui.selNode != NULL) Tree_UI_Sel_Exit();

    // 2. 逐级向上寻找并执行 Exit，直到遇见 tree_home
    while(tree_ui.uiNode != NULL && tree_ui.uiNode != tree_home)
    {
        if(tree_ui.uiNode->pdata->ui_exit) {
            tree_ui.uiNode->pdata->ui_exit(); // 直接调函数，不发事件
        }
        tree_ui.uiNode = tree_ui.uiNode->parent; // 顺着父节点爬回去
    }
    
    // 3. 最后进入主页
    Tree_UI_Sel_Enter(tree_home, 0);
}

/**
 * @brief  系统级按键处理 (物理按键 -> 功能直达)
 */
uint8_t System_Key_Process(lv_key_t key)
{
    uint8_t used = 0;
    switch(key) {
        // F1 键直达电压设置
        case LV_KEY_F1: 
            if(tree_ISet != NULL) {
                Tree_UI_Sel_Enter(tree_ISet, 0);
                used = 1;
            }
            break;

        case LV_KEY_OUTPUT:

            used = 1;
            break;

        case LV_KEY_MENU: {
            {
                UI_Switch_Page(PAGE_MENU);
            }
            used = 1;           
        }
        break;
        case LV_KEY_HOME:
            {
                UI_Force_Back_To_Home();
              //  UI_Switch_Page(PAGE_HOME);
            }
            used = 1;
            break;
        
        default: break;
    }
    return used;
}

/* ----------------------------------------------------------------            
    6. 初始化
   ---------------------------------------------------------------- */
/* ----------------------------------------------------------------            
    1. 全局节点指针定义 (分配内存空间)
   ---------------------------------------------------------------- */
#include "Gui_Task.h"
Tree_Def *tree_home = NULL;
Tree_Def *tree_VSet = NULL;
Tree_Def *tree_ISet = NULL;
Tree_Def *tree_ISet_neg = NULL;


Tree_Def *tree_menu              = NULL;
Tree_Def *tree_config            = NULL;
Tree_Def *tree_protect           = NULL;
Tree_Def *tree_measure           = NULL;
Tree_Def *tree_trigger           = NULL;
Tree_Def *tree_recall            = NULL;
Tree_Def *tree_save              = NULL;
Tree_Def *tree_meter             = NULL;
Tree_Def *tree_recorder          = NULL;
Tree_Def *tree_function          = NULL;
Tree_Def *tree_delays            = NULL;
Tree_Def *tree_coupling          = NULL;
Tree_Def *tree_group             = NULL;
Tree_Def *tree_general           = NULL;
Tree_Def *tree_digital_io        = NULL;
Tree_Def *tree_preference        = NULL;
Tree_Def *tree_log               = NULL;
Tree_Def *tree_admin             = NULL;
Tree_Def *tree_communication     = NULL;
Tree_Def *tree_info              = NULL;
Tree_Def *tree_energy            = NULL;
Tree_Def *tree_date              = NULL;
/* ----------------------------------------------------------------            
    2. 节点元数据定义 (Metadata)
   ---------------------------------------------------------------- */

// 主页节点数据
static const struct BtnInfo_Def btn_home = {
    .type = BTN_TYPE_UI,            // 页面类型
    .obj = &ui.HOME_PAGE_cont_Set,   // 关联的主页面容器地址
};


// 电压设置节点数据 (示例)
const struct BtnInfo_Def btn_VSet = {  
    .type = BTN_TYPE_SEL,           // 选中/编辑类型
    .obj = &ui.HOME_PAGE_edit_Vset, // 具体的电压输入框对象
    .evencb = volSet_handler        // 你的电压调节函数
};
const struct BtnInfo_Def btn_ISet = {  
    .type = BTN_TYPE_SEL,           // 选中/编辑类型
    .obj = &ui.HOME_PAGE_edit_Iset_pos, // 具体的电压输入框对象
    .evencb = ampSet_handler        // 你的电压调节函数
};
const struct BtnInfo_Def btn_ISet_neg = {  
    .type = BTN_TYPE_SEL,           // 选中/编辑类型
    .obj = &ui.HOME_PAGE_edit_Iset_neg, // 具体的电压输入框对象
    .evencb = ampSet_handler_neg        // 你的电压调节函数
};
//菜单节点数据
static const struct BtnInfo_Def btn_Menu = {
    .type = BTN_TYPE_UI,
    .ui_enter = Home_Menu_Enter,
    .ui_exit = Home_Menu_Exit,
    .obj = &ui.HOME_MENU_cont_menu_set, 
    .evencb = nav_process_key,
    .multStr = &mStr_Menu,
};

// 1. Config 页面
const struct BtnInfo_Def btn_config = {  
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Config_Enter,
    .ui_exit = Menu_Config_Exit,   
    .obj = &ui.HOME_MENU_btn_menu_config, 
    .multStr = &mStr_Menu_Config,
    .icon_src = &_config_alone_alpha_70x70,
};

// 2. Protect 页面
const struct BtnInfo_Def btn_protect = {  
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Protect_Enter,
    .ui_exit = Menu_Protect_Exit,     
    .obj = &ui.HOME_MENU_btn_menu_protect,
    .multStr = &mStr_Menu_Protect,
   .icon_src = &_protect_alone_alpha_70x70, 
};

// 3. Measure 页面
const struct BtnInfo_Def btn_measure = {  
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Measure_Enter,
    .ui_exit = Menu_Measure_Exit,     
    .obj = &ui.HOME_MENU_btn_menu_measure,
    .multStr = &mStr_Menu_Measure,
    .icon_src = &_measure_alone_alpha_70x70,
    
};

// 4. Trigger 页面
const struct BtnInfo_Def btn_trigger = {  
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Trigger_Enter,
    .ui_exit = Menu_Trigger_Exit,     
    .obj = &ui.HOME_MENU_btn_menu_trigger,
    .multStr = &mStr_Menu_Trigger,
    .icon_src = &_trigger_alone_2_alpha_70x70,
};

// 5. Recall 页面
const struct BtnInfo_Def btn_recall = {  
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Recall_Enter,
    .ui_exit = Menu_Recall_Exit,     
    .obj = &ui.HOME_MENU_btn_menu_recall,
    .multStr = &mStr_Menu_Recall,
    .icon_src = &_recall_alone_alpha_70x70,
};

// 6. Save 页面
const struct BtnInfo_Def btn_save = {  
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Save_Enter,
    .ui_exit = Menu_Save_Exit,     
    .obj = &ui.HOME_MENU_btn_menu_save,
    .multStr = &mStr_Menu_Save,
    .icon_src = &_save_alone_alpha_70x70,
};

// 7. Meter 页面
const struct BtnInfo_Def btn_meter = {  
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Meter_Enter,
    .ui_exit = Menu_Meter_Exit,     
    .obj = &ui.HOME_MENU_btn_menu_meter,
    .multStr = &mStr_Menu_Meter,
    .icon_src = &_meter2_alpha_70x70,
    
};
// 8. Recorder 页面
const struct BtnInfo_Def btn_recorder = {  
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Recorder_Enter,
    .ui_exit = Menu_Recorder_Exit,     
    .obj = &ui.HOME_MENU_btn_menu_recorder,
    .multStr = &mStr_Menu_Recorder,
    .icon_src = &_recoder_alone_alpha_70x70,
};
// 9. Function 页面
const struct BtnInfo_Def btn_function = {
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Function_Enter,
    .ui_exit = Menu_Function_Exit,
    .obj = &ui.HOME_MENU_btn_menu_function,
    .multStr = &mStr_Menu_Function,
    .icon_src = &_Function_alone_alpha_70x70,
};

// 10. Delays 页面
const struct BtnInfo_Def btn_delays = {
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Delays_Enter,
    .ui_exit = Menu_Delays_Exit,
    .obj = &ui.HOME_MENU_btn_menua_delays,
    .multStr = &mStr_Menu_Delays,
    .icon_src = &_delays_alone_alpha_70x70,
};

// 11. Coupling 页面
const struct BtnInfo_Def btn_coupling = {
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Coupling_Enter,
    .ui_exit = Menu_Coupling_Exit,
    .obj = &ui.HOME_MENU_btn_menu_coupling,
    .multStr = &mStr_Menu_Coupling,
    .icon_src = &_coupling_alone_alpha_70x70,
};

// 12. Group 页面
const struct BtnInfo_Def btn_group = {
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Group_Enter,
    .ui_exit = Menu_Group_Exit,
    .obj = &ui.HOME_MENU_btn_menu_group,
    .multStr = &mStr_Menu_Group,
    .icon_src = &_group_alone_alpha_70x70,
};

// 13. General 页面
const struct BtnInfo_Def btn_general = {
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_General_Enter,
    .ui_exit = Menu_General_Exit,
    .obj = &ui.HOME_MENU_btn_menu_general,
    .multStr = &mStr_Menu_General,
    .icon_src = &_general_alone_alpha_70x70,
};

// 14. Digital_IO 页面
const struct BtnInfo_Def btn_digital_io = {
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Digital_IO_Enter,
    .ui_exit = Menu_Digital_IO_Exit,
    .obj = &ui.HOME_MENU_btn_menu_digital_io,
    .multStr = &mStr_Menu_Digital_IO,
    .icon_src = &_Digital_io_alone_alpha_70x70,
};

// 15. Preference 页面
const struct BtnInfo_Def btn_preference = {
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Preference_Enter,
    .ui_exit = Menu_Preference_Exit,
    .obj = &ui.HOME_MENU_btn_menu_preference,
    .multStr = &mStr_Menu_Preference,
    .icon_src = &_perfect_alone_alpha_70x70,
};

// 16. Log 页面
const struct BtnInfo_Def btn_log = {
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Log_Enter,
    .ui_exit = Menu_Log_Exit,
    .obj = &ui.HOME_MENU_btn_menu_log,
    .multStr = &mStr_Menu_Log,
    .icon_src = &_log_alone_alpha_70x70,
};

// 17. Admin 页面
const struct BtnInfo_Def btn_admin = {
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Admin_Enter,
    .ui_exit = Menu_Admin_Exit,
    .obj = &ui.HOME_MENU_btn_menu_admin,
    .multStr = &mStr_Menu_Admin,
    .icon_src = &_admin_alone_alpha_70x70,
};

// 18. Communication 页面
const struct BtnInfo_Def btn_communication = {
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Communication_Enter,
    .ui_exit = Menu_Communication_Exit,
    .obj = &ui.HOME_MENU_btn_menu_communication,
    .multStr = &mStr_Menu_Communication,
    .icon_src = &_communication_alone_alpha_70x70,
};

// 19. Info 页面
const struct BtnInfo_Def btn_info = {
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Info_Enter,
    .ui_exit = Menu_Info_Exit,
    .obj = &ui.HOME_MENU_btn_menu_info,
    .multStr = &mStr_Menu_Info,
    .icon_src = &_info_alone_alpha_70x70,
};

// 20. Energy 页面
const struct BtnInfo_Def btn_energy = {
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Energy_Enter,
    .ui_exit = Menu_Energy_Exit,
    .obj = &ui.HOME_MENU_btn_menu_energy,
    .multStr = &mStr_Menu_Energy,
    .icon_src = &_energy_alone_alpha_70x70,
};

// 21. Date 页面
const struct BtnInfo_Def btn_date = {
    .type = BTN_TYPE_UI,
    .ui_enter = Menu_Date_Enter,
    .ui_exit = Menu_Date_Exit,
    .obj = &ui.HOME_MENU_btn_menu_date,
    .multStr = &mStr_Menu_Date,
    .icon_src = &_date_alone_alpha_70x70,
};


Tree_Def *UI_Tree_Init(void)
{
// 1. 创建根
    tree_home = Tree_CreateNode(&btn_home);
    {   
        tree_VSet = Tree_AddNode(tree_home, &btn_VSet);
        tree_ISet = Tree_AddNode(tree_home, &btn_ISet); 
        tree_ISet_neg = Tree_AddNode(tree_home, &btn_ISet_neg); 
        
    }     

    // 2. 挂载主菜单
    tree_menu = Tree_AddNode(tree_home, &btn_Menu); 
    {
        // 将所有子页面挂载到菜单下
        tree_config   = Tree_AddNode(tree_menu, &btn_config); 
        tree_protect  = Tree_AddNode(tree_menu, &btn_protect);
        tree_measure  = Tree_AddNode(tree_menu, &btn_measure);
        tree_trigger  = Tree_AddNode(tree_menu, &btn_trigger);
        tree_recall   = Tree_AddNode(tree_menu, &btn_recall);
        tree_save     = Tree_AddNode(tree_menu, &btn_save);
        tree_meter    = Tree_AddNode(tree_menu, &btn_meter);
        tree_recorder = Tree_AddNode(tree_menu, &btn_recorder);
        tree_function      = Tree_AddNode(tree_menu, &btn_function);
        tree_delays        = Tree_AddNode(tree_menu, &btn_delays);
        tree_coupling      = Tree_AddNode(tree_menu, &btn_coupling);
        tree_group         = Tree_AddNode(tree_menu, &btn_group);
        tree_general       = Tree_AddNode(tree_menu, &btn_general);
        tree_digital_io    = Tree_AddNode(tree_menu, &btn_digital_io);
        tree_preference    = Tree_AddNode(tree_menu, &btn_preference);
        tree_log           = Tree_AddNode(tree_menu, &btn_log);
        tree_admin         = Tree_AddNode(tree_menu, &btn_admin);
        tree_communication = Tree_AddNode(tree_menu, &btn_communication);
        tree_info          = Tree_AddNode(tree_menu, &btn_info);
        tree_energy        = Tree_AddNode(tree_menu, &btn_energy);
        tree_date          = Tree_AddNode(tree_menu, &btn_date);
    }
    
    // 3. 递归布线：自动给所有 obj 挂载 evencb
    Tree_UI_Set_EventCb(tree_home);
    // 4. 初始进入主页
    Tree_UI_Sel_Enter(tree_home, 0);
    // 打印树结构以供确认
    Tree_Print(tree_home, 0);
    
    return tree_home;
}

