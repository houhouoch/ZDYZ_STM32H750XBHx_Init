#include "BtnTree.h"
#include <string.h>
#include <stdio.h>

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

/*!
 * @brief  退出当前选中节点 (取消编辑/取消高亮)
 */
void Tree_UI_Sel_Exit(void)
{
    Tree_Def *temp_selNode = tree_ui.selNode;
    
    if(temp_selNode != NULL)
    {
        const struct BtnInfo_Def *pdata = temp_selNode->pdata;
        
        // 确保对象有效
        if(pdata != NULL && pdata->obj != NULL && *pdata->obj != NULL)
        {
            lv_obj_t * obj = *pdata->obj;
            
            // 1. 清除 LVGL 内部状态
            lv_obj_clear_state(obj, LV_STATE_FOCUSED | LV_STATE_EDITED | LV_STATE_CHECKED);
            
            // 2. 发送失去焦点和刷新信号
            lv_event_send(obj, LV_EVENT_DEFOCUSED, NULL);
            lv_event_send(obj, LV_EVENT_REFRESH, NULL);
            
            // 3. 强制重绘
            lv_obj_invalidate(obj);
        }
        
        // 清空当前选中记录
        tree_ui.selNode = NULL;
        
        // 4. 如果退出的是个叶子节点，尝试刷新整个 UI 容器
        if(temp_selNode->child == NULL && tree_ui.uiNode != NULL) {
            const struct BtnInfo_Def *ui_pdata = tree_ui.uiNode->pdata;
            if(ui_pdata->obj != NULL && *ui_pdata->obj != NULL) {
                lv_event_send_recursive(*ui_pdata->obj, LV_EVENT_REFRESH, NULL);
            }
        }
    }
}

/*!
 * @brief  进入节点逻辑 (核心)
 */
void Tree_UI_Sel_Enter(Tree_Def *node, uint8_t longFlag)
{
    if(node == NULL || node->pdata == NULL) return;

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
        case BTN_TYPE_UI: 
        {
            if(tree_ui.uiNode != node) 
            {
                // 如果不是子节点且当前有页面，执行旧页面的 Exit
                if(tree_ui.uiNode != NULL && Tree_IsChild(tree_ui.uiNode, node) == 0)
                {
                    if(tree_ui.uiNode->pdata->ui_exit != NULL) {
                        tree_ui.uiNode->pdata->ui_exit();
                    }
                }
                
                // 执行新页面的 Enter
                if(pdata->ui_enter != NULL) {
                    pdata->ui_enter();
                }
                tree_ui.uiNode = node;
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

/**
 * @brief  获取当前页面 ID
 */
uint8_t __Get_CurrentPage(void)
{
    extern Tree_Def *tree_home;
    if(tree_ui.uiNode == tree_home) return PAGE_HOME;
    // ... 其他页面判断 ...
    return PAGE_NULL;
}

/**
 * @brief  切换 UI 页面
 */
void UI_Switch_Page(uint8_t page)
{
    extern Tree_Def *tree_home;
    // 这里根据 Page 枚举执行跳转，最终调用 Tree_UI_Sel_Enter
    switch(page) {
        case PAGE_HOME: 
            Tree_UI_Sel_Enter(tree_home, 0); 
            break;
        // ...
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
/* ----------------------------------------------------------------            
    2. 节点元数据定义 (Metadata)
   ---------------------------------------------------------------- */

// 主页节点数据
static const struct BtnInfo_Def btn_home = {
    .type = BTN_TYPE_UI,            // 页面类型
    .obj = &ui.HOME_PAGE_cont_1,   // 关联的主页面容器地址
};

#include "HomePage.h"
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
Tree_Def *UI_Tree_Init(void)
{
    // 1. 创建根
    tree_home = Tree_CreateNode(&btn_home);

    // 2. 挂载各个业务节点 (tree_VSet, tree_ISet 等在此处 AddNode)
    tree_VSet = Tree_AddNode(tree_home, &btn_VSet);
    tree_ISet = Tree_AddNode(tree_home, &btn_ISet);    
    // 3. 初始进入主页页面
    Tree_UI_Sel_Enter(tree_home, 0);

    // 打印树结构以供确认
   // Tree_Print(tree_home, 0);
    
    return tree_home;
}
