# 🚀 STM32H750 + LVGL 触摸屏驱动移植笔记 (Goodix GT1151Q/GT1158)

本仓库记录了将 **Goodix (汇顶)** 电容触摸芯片（GT1151Q/GT1158）移植到 **STM32H750** 平台并接入 **LVGL v8.x** 的完整过程。

---

## ⚠️ 避坑指南：硬件与原理图

1.  **不要盲信丝印**：正点原子等开发板的原理图丝印标号是为了通用性设计的，**不要看原理图上的标号！**
2.  **以例程定义为准**：直接参考官方例程中的引脚定义，并在 **STM32CubeMX** 中进行手动配置。
3.  **核心引脚**：触摸 IC 只需要配置 **4 个** 关键引脚：
    * **IIC_SCL / IIC_SDA**：用于数据通信。
    * **INT (中断)**：接收触摸触发信号，同时参与上电地址选择。
    * **RST (复位)**：用于硬件复位触摸芯片。

---

## 1. 底层模拟 IIC 驱动

在 H750 这种 480MHz 的高主频芯片下，为了简单且稳定地实现 IIC 延时，采用 `volatile` 关键字防止编译器优化的简单循环。

### 延时函数实现
```c
/**
 * @brief   电容触摸屏IIC简易循环延时函数
 * @note    在 H750 @ 480MHz 下，循环 120 次产生约 1~2us 的延时
 */
static void ct_iic_delay(void)
{
    /* 使用 volatile 防止循环被编译器优化删除 */
    volatile uint32_t i = 120; 
    while(i--);
}
```

### 引脚定义示例
```c
/* 使用模拟IIC驱动触摸芯片 */
#define CT_IIC_SCL_GPIO_PORT            GPIOH
#define CT_IIC_SCL_GPIO_PIN             GPIO_PIN_6
#define CT_IIC_SCL_GPIO_CLK_ENABLE()    do { __HAL_RCC_GPIOH_CLK_ENABLE(); } while (0)

#define CT_IIC_SDA_GPIO_PORT            GPIOG
#define CT_IIC_SDA_GPIO_PIN             GPIO_PIN_7
#define CT_IIC_SDA_GPIO_CLK_ENABLE()    do { __HAL_RCC_GPIOG_CLK_ENABLE(); } while (0)
```

---

## 2. INT 引脚的“一专多能”



在初始化阶段，INT 引脚承担了决定 I2C 设备地址的重任：

1.  **输出模式**：在 RST 复位瞬间，通过输出高/低电平来选定芯片的 I2C 地址（通常选定 0x14）。
2.  **切换模式**：初始化完成后，必须将 INT 切换回**浮空输入（中断）**模式，用于接收触摸信号。

---

## 3. LVGL 接口集成 (lv_port_indev.c)

将触摸扫描函数 `touch_scan` 封装并注册到 LVGL 的输入设备管理中。

```c
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data){
    touch_point_t tp;
    uint8_t touch_cnt;

    // 扫描 1 个点即可（LVGL 基础控件通常只用单点）
    touch_cnt = touch_scan(&tp, 1);

    if(touch_cnt > 0) {
        data->state = LV_INDEV_STATE_PR; // 设置为按下状态
        
        /* 【重要】坐标转换 */
        /* GT1151Q/GT1158 的原始方向可能与 LCD 不一致，此处需进行映射 */
        data->point.x = 800 - tp.x;  // 处理左右反向
        data->point.y = 480 - tp.y;  // 处理上下反向
    }
    else {
        data->state = LV_INDEV_STATE_REL; // 设置为松开状态
    }
}

void lv_port_indev_init(void){
    static lv_indev_drv_t indev_drv;
    
    // 初始化触摸硬件（读取 PID，确保是 1151 或 1158）
    if(touch_init() != TOUCH_OK) {
        // Error Handling...
    }

    /* 注册触摸指针设备 */
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    lv_indev_touchpad = lv_indev_drv_register(&indev_drv);
}
```

---

## 4. 触摸功能测试

创建一个简单的按钮，验证整个链路（硬件 -> IIC -> 驱动 -> LVGL -> UI）是否通畅。

```c
static void test_btn_event_cb(lv_event_t * e){
    if(lv_event_get_code(e) == LV_EVENT_CLICKED) {
        static uint8_t cnt = 0;
        cnt++;
        lv_obj_t * btn = lv_event_get_target(e);

        // 颜色切换反馈
        lv_color_t colors[] = {lv_palette_main(LV_PALETTE_GREEN), 
                               lv_palette_main(LV_PALETTE_BLUE), 
                               lv_palette_main(LV_PALETTE_ORANGE)};
        lv_obj_set_style_bg_color(btn, colors[cnt % 3], 0);
    }
}

void ui_create_test_button(void){
    lv_obj_t * btn = lv_btn_create(lv_scr_act()); 
    lv_obj_set_size(btn, 200, 80);
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t * label = lv_label_create(btn);
    lv_label_set_text(label, "TOUCH TEST");
    lv_obj_center(label);

    lv_obj_add_event_cb(btn, test_btn_event_cb, LV_EVENT_ALL, NULL);
}
```

---

## 📝 坐标校准总结

由于 800x480 屏幕的安装方向各异，坐标映射是成功的最后一步。

| 现象判定 | 修正逻辑 | 示例代码 |
| :--- | :--- | :--- |
| **点击正常** | 无需修改 | `data->point.x = tp.x;` |
| **左右反向** | X 轴反向 | `data->point.x = 800 - tp.x;` |
| **上下反向** | Y 轴反向 | `data->point.y = 480 - tp.y;` |
| **横竖屏错乱** | X/Y 轴互换 | `data->point.x = tp.y; data->point.y = tp.x;` |

> **作者注**：在本工程中，触摸 IC 坐标与 UI 坐标上下左右均相反，已在 `touchpad_read` 中完成修正。