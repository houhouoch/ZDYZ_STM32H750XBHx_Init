# 🚀 GT1158/GT1151 多点触摸测试说明 (v2.0 更新)

本更新增加了对 **5 点触摸** 的底层支持。虽然在标准的 GUI 交互（如 LVGL）中通常只处理单点信号，但底层驱动的升级能够更准确地反馈硬件性能，并为后续的手势识别提供基础。

---

## 1. LVGL 输入设备限制说明

在 LVGL 的输入设备驱动（indev）中，类型为 `LV_INDEV_TYPE_POINTER` 的设备在处理标准控件（按钮、滑块等）时，默认只会消耗 **第 1 个触摸点**。

* **单点交互**：LVGL 核心逻辑仅消耗 `tp[0]` 的坐标。
* **多点调试**：为了验证硬件可靠性，驱动层会读取全部 5 个点并通过串口打印。这有助于判断电容屏在多指点击时的灵敏度及是否存在坐标跳变。



---

## 2. 寄存器定义更新

GT115x 系列芯片每组触摸点数据占用 **8 字节** 空间。为了支持 5 点触摸，新增了以下寄存器基地址定义：

```c
/* 触摸点寄存器基地址定义 */
#define CT_REG_TP1           0x8150  // 触摸点 1 基地址
#define CT_REG_TP2           0x8158  // 触摸点 2 基地址
#define CT_REG_TP3           0x8160  // 触摸点 3 基地址
#define CT_REG_TP4           0x8168  // 触摸点 4 基地址
#define CT_REG_TP5           0x8170  // 触摸点 5 基地址
```

---

## 3. 驱动核心代码修改

### 3.1 扫描函数 `touch_scan` 优化
更新后的 `touch_scan` 支持传入一个数组地址。它会根据芯片上报的实际点数（`tp_info & 0x0F`），自动循环读取对应的寄存器组。

### 3.2 LVGL 适配层 `touchpad_read`
**⚠️ 内存安全提醒**：为了防止多点触摸时上报点数超出预期导致 **HardFault**，必须在函数内部定义足够大的数组。

```c
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    /* 1. 定义 5 点数组空间，防止多指按下时踩掉栈内存 */
    touch_point_t tp[5];
    uint8_t touch_cnt;

    /* 2. 扫描硬件，获取当前所有触点数据 */
    touch_cnt = touch_scan(tp, 5);

    if(touch_cnt > 0) {
        data->state = LV_INDEV_STATE_PR; // 设置为按下状态
        
        /* 3. 坐标转换与反馈（仅将第一个点 tp[0] 反馈给 LVGL） */
        /* 根据 800x480 屏幕安装方向进行镜像处理 */
        data->point.x = 800 - tp[0].x;
        data->point.y = 480 - tp[0].y;
        
        /* 4. 调试输出：串口打印所有触点坐标，用于硬件性能评估 */
        printf("Detected Points: %d\n", touch_cnt);
        for(uint8_t i = 0; i < touch_cnt; i++) {
            printf("  Point[%d]: X=%d, Y=%d\n", i, tp[i].x, tp[i].y);
        }
    }
    else {
        data->state = LV_INDEV_STATE_REL; // 设置为松开状态
    }
}
```

---

## 💡 4. 调试要点与注意事项

### 🔴 内存安全 (Memory Safety)
切勿将 `touch_scan` 的 `max_points` 参数设为大于接收数组长度的值。如果硬件上报了 5 个点，但你的数组只有 1 个空间，系统会立即崩溃。

### 📏 坐标映射
如果发现触摸位置与屏幕显示相反，请检查以下逻辑：
* **水平翻转**：$x_{\text{new}} = 800 - x_{\text{raw}}$
* **垂直翻转**：$y_{\text{new}} = 480 - y_{\text{raw}}$

### 🧹 状态清除 (Status Clear)
**最易忽略的细节**：在 `touch_scan` 解析完数据后，必须向 `CT_REG_TPINFO` 写入 **0**。如果未清零，触摸芯片会认为 CPU 尚未处理完当前数据，从而停止产生下一次中断或更新寄存器。

---

### 📖 开发者寄语
本次多点支持的意义不仅在于数据量的增加，更在于**驱动健壮性**的提升。在电力测量仪这种复杂的电磁环境下，能够稳定读取多点信号是过滤噪声、防止误触的基础。
