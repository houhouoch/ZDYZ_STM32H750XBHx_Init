# 🚀 STM32H750 + LVGL v8.3

本项目基于 **STM32H750XBHx** 开发

---

## 🛠️ 一、 核心功能模块

### 1. 动态启动与资源管理
在系统启动阶段，通过解耦图片资源与显示逻辑，实现了灵活的 Logo 切换机制。

#### **技术实现：`__Boot_Display_Logo`**
```c
static void __Boot_Display_Logo(void)
{
    // 声明外部图片资源（存储于外部 QSPI Flash）
    LV_IMG_DECLARE(_Logo_alpha_569x159);    
    LV_IMG_DECLARE(_HY_LOGO_alpha_639x178);  

    // 使用指针 imgSrc 实现资源与逻辑的解耦，方便后期一键更换素材
    const lv_img_dsc_t *imgSrc = &_Logo_alpha_569x159; 

    // 设置图片源并自适应容器大小
    lv_img_set_src(ui.Back_img_Logo, imgSrc);
    lv_obj_set_size(ui.Back_img_Logo, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui.Back_img_Logo, LV_ALIGN_CENTER, 0, 0);

    // 硬件同步：背光渐亮逻辑
    for(uint8_t i = 0; i <= 100; i++) {
        osDelay(20);  
        lv_task_handler(); // 确保在背光亮起前，显存中已完成第一帧渲染
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, i * 2); // PWM 控制背光
    }

    // 资源释放：Logo 任务完成后彻底删除对象，释放 RAM
    lv_obj_del(ui.Back_img_Logo);
    ui.Back_img_Logo = NULL;
}
```

> **📚 关键细节：为什么 `lv_scr_load` 只能加载屏幕（Screen）？**
> * **根节点属性**：在 LVGL 中，屏幕是显示树的顶层根节点。`lv_scr_load` 的本质是切换渲染上下文的基地址。
> * **崩溃预防**：容器（Container）必须依附于屏幕。若误将容器地址传给加载函数，系统会因找不到父级索引而触发 **HardFault**。

---

## 💡 二、 运行状态指示系统 (UX Design)

为了实时监控 UI 任务状态，设计了呼吸灯模式指示器。

### ⚙️ 模块化封装
```c
#define UI_LED_BREATH_IN_MS   300   // 快吸：展现系统敏捷度
#define UI_LED_BREATH_OUT_MS  1000  // 慢呼：展现运行平稳感

void ui_led_start_asymmetric_breathing(lv_obj_t *led_obj) {
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, led_obj);
    lv_anim_set_values(&a, 50, 255);
    lv_anim_set_time(&a, UI_LED_BREATH_IN_MS);
    lv_anim_set_playback_time(&a, UI_LED_BREATH_OUT_MS);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out); // S型曲线，视觉更丝滑
    lv_anim_set_exec_cb(&a, (void (*)(void *, int32_t))lv_led_set_brightness);
    lv_anim_start(&a);
}
```

---

## 🎨 三、 图标设计工作流：AI 辅助工程

通过矢量图标开发流程，将传统的 UI 设计工作时间缩短了 **80%**。

1.  **AI 生成**：通过大模型生成符合工业风格的 SVG 矢量代码。
2.  **代码转换**：将代码保存为 `.svg` 文件。
3.  **格式提纯**：利用在线工具将矢量图转换为高清 PNG。
    * [CloudConvert (SVG to PNG)](https://cloudconvert.com/svg-to-png)
    * [SVGtoPNG Official](https://svgtopng.com/zh/)
4.  **导入工程**：通过 **GUI Guider** 将 PNG 转化为 LVGL C 数组，利用 H7 的 **DMA2D (Chrom-Art)** 硬件加速实现透明边缘渲染。
