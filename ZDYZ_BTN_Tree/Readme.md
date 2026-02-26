# 🧠 LVGL 逻辑树 UI 框架：从“UI 驱动”到“逻辑驱动”的演进

本仓库实现了一套基于 **LVGL v8.3** 的嵌入式 UI 框架。通过之前项目的底部虚拟按键（Virtual Button Bar），引入多层级逻辑树，实现了硬件按键与 UI 逻辑的深度解耦。

---

## 🎯 核心设计思想：逻辑驱动 (Logic Driven)

传统的 UI 设计往往是“看到什么点什么”。但在嵌入式领域，屏幕空间有限且多依赖物理按键。
我们的核心逻辑是：**物理按键 -> 逻辑状态机 (Tree) -> UI 部件 (LVGL Object)**。



---

## 📚 关键知识点解析

### 1. 按键状态机的解耦 (Key Mapping Table)
**为什么要用映射表？**
避免在按键驱动中硬编码业务逻辑（如 `if(key==ID_KEY2) voltage--`）。通过“查表法”，我们将物理动作转化为标准的 LVGL 逻辑键值。

#### **核心代码实现**
```c
// 映射表：将硬件物理 ID 与 UI 逻辑功能解耦
static const Button_KeyTable_Def Btn_KeyTable[] = {
    // 物理ID      | 短按(弹起触发) | 长按(1.5s触发)      | 按住(50ms拦截)
    {ID_KEY2,      LV_KEY_DOWN,   LV_KEY_DOWN,         LV_KEY_DEFAULT}, 
    {ID_WKUP,      LV_KEY_UP,     LV_KEY_UP,           LV_KEY_DEFAULT},
};

// 状态过滤逻辑：解决“快按触发两次”的痛点
lv_key_t Button_toKey(uint8_t buttonNum, uint8_t flag) {
    // ... 内部查表逻辑 ...
                switch(flag)
                {
                    case KEY_STATE_HOLD:
                        key = Btn_KeyTable[i].key_hold;
                        break;
                    case KEY_STATE_CLICKED:
                        key = Btn_KeyTable[i].key_short;
                        break;
                    case KEY_STATE_LONGGP:
                        key = Btn_KeyTable[i].key_long;
                        break;
                    default:
                        key = LV_KEY_DEFAULT;
                        break;
                }
}
```

---

### 2. 树状状态机 (Tree State Machine)
我们将每一个页面、每一个可编辑的输入框都看作树的一个“节点”。

* **uiNode (页面节点)**：控制当前的图层切换。
* **selNode (聚焦节点)**：控制按键流向哪一个具体的 UI 部件（如：电压输入框）。



#### **节点进入逻辑**
```c
void Tree_UI_Sel_Enter(Tree_Def *node, uint8_t longFlag) {
    const struct BtnInfo_Def *pdata = node->pdata;
    
    if(pdata->type == BTN_TYPE_SEL) {  // 如果是对象编辑类型
        tree_ui.selNode = node;         // 记录当前选中的节点
        lv_obj_add_state(*pdata->obj, LV_STATE_FOCUSED); // 让部件进入高亮状态
        lv_event_send(*pdata->obj, LV_EVENT_FOCUSED, NULL); // 触发业务层初始化
    }
}
```

---

### 3. LVGL 键值偏移与类型截断 (Type Truncation)
**⚠️ 避坑指南**：在 LVGL v8.3 中，`lv_event_get_key(e)` 有时会返回带有 `0xE000` 偏移的 32 位键值（例如 `LV_KEY_DOWN` 变成 `57362`）。

**解决方案**：利用 C 语言的**类型截断**特性。将 `uint32_t` 赋值给 `uint8_t` (即 `lv_key_t`)，会自动丢弃高位的偏移，只保留低 8 位的标准枚举值。

```c
// 业务层处理：干净、直接
case LV_EVENT_KEY: {
    lv_key_t key = (lv_key_t)lv_event_get_key(e); // 自动将 57362 截断为 18
    if(key == LV_KEY_DOWN) {
        current_v -= step; // 完美匹配标准枚举值
    }
}
```

---

### 4. 递归事件分发 (Recursive Event Sending)
当底层参数（如电源输出状态）变化时，需要同步刷新界面上所有相关的图标和文字。

```c
void lv_event_send_recursive(lv_obj_t * obj, lv_event_code_t code, void * param) {
    lv_event_send(obj, code, param); // 先发给自己
    
    // 遍历所有子对象，实现“牵一发而动全身”的同步刷新
    uint32_t child_cnt = lv_obj_get_child_cnt(obj);
    for(uint32_t i = 0; i < child_cnt; i++) {
        lv_event_send_recursive(lv_obj_get_child(obj, i), code, param);
    }
}
```

---

## 🛠️ 如何在此框架下开发新功能？

1.  **定义节点元数据**：在 `BtnTree.c` 中创建一个 `struct BtnInfo_Def`，填入 UI 对象地址和回调函数。
2.  **挂载树节点**：使用 `Tree_AddNode` 将新节点挂载到 `tree_home` 下。
3.  **编写 Handler**：在业务逻辑文件中通过 `switch(code)` 处理 `LV_EVENT_KEY`。
4.  **物理按键绑定**：在 `System_Key_Process` 中通过物理按键 ID 调用 `Tree_UI_Sel_Enter`。

---

## 🌟 总结

这套框架最大的优势在于**“逻辑的一致性”**。无论 UI 视觉如何翻新，底层的按键映射和树状导航逻辑依然稳固。这种结构极度适合**精密电源、示波器、工业控制仪表**等需要高频数值调节和多级菜单切换的专业设备。
