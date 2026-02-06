# 🚀 STM32H750 + LVGL v8.3 高性能移植与显存架构优化指南

本项目基于 **STM32H750XBH6 (北极星开发板)**，深入探讨了 LVGL v8.3 在 800x480 分辨率下的极致性能优化方案。重点对比了 **DMA2D 硬件加速** 与 **LTDC 零拷贝 (Zero-copy)** 架构对系统资源的占用情况。
> **参考资料**：[LVGL v8.3 移植参考官方文档](https://www.cnblogs.com/lesterbor/p/17953045)
---

> **核心结论**：在 160 个动态方块压力测试下，**零拷贝模式**将 CPU 占用从 **75%** 降低至 **25%**，为 后续CPU处理留出了巨大的算力空间。

---

## 🛠️ 一、 核心环境配置 (lv_conf.h)

### 1. 时钟心跳 (Tick)
**心跳是动画的灵魂。** 必须开启硬件心跳并挂载到 FreeRTOS 的系统 Tick 上，否则将不会呈现动画效果。

```c
#define LV_TICK_CUSTOM 1
#if LV_TICK_CUSTOM
    #define LV_TICK_CUSTOM_INCLUDE "FreeRTOS.h"
    #define LV_TICK_CUSTOM_SYS_TIME_EXPR (xTaskGetTickCount()) 
#endif
```

### 2. 内存布局 (SDRAM 优先)
由于 H750 内部 AXI SRAM 空间有限，建议将 LVGL 内存池设在外部 SDRAM。

```c
#define LV_MEM_SIZE (1024U * 1024U)          /* 1MB 内存池 */
#define LV_MEM_ADR  0xC0800000               /* 挂载到 SDRAM 偏移 8MB 处，避开显存 */
```

### 3. 硬件加速 (GPU/DMA2D)
开启 DMA2D 引擎，让硬件接管像素运算。

```c
#define LV_USE_GPU_STM32_DMA2D    1
#define LV_GPU_DMA2D_CMSIS_INCLUDE "stm32h7xx.h"
```

---

## 🏗️ 二、 两种显示架构深度对比

| 维度 | 模式一：BUF_1_2 (经典搬运型) | 模式二：FB_ADD_1_2 (零拷贝切换型) |
| :--- | :--- | :--- |
| **底层核心** | MemCPY (通过 DMA2D 搬运) | Pointer Swap (仅切换 LTDC 指针) |
| **数据流向** | 缓冲区 $\xrightarrow{DMA2D}$ 物理显存 | 缓冲区 $\equiv$ 物理显存 (原地绘图) |
| **CPU 占用** | **约 75%** (满屏动态方块测试) | **约 25%** (满屏动态方块测试) |
| **优势** | 兼容性极强（支持 SPI/8080 屏） | 极致性能，无总线带宽浪费 |

### 🔄 为什么 BUF_1_2 会“绕路”？
在搬运模式下，数据经历了：`CPU 绘图 -> 缓冲区 -> DMA2D 读取 -> SDRAM 写入 -> 物理显存`。
即便缓冲区和显存都在 SDRAM，DMA2D 依然需要占用 FMC 总线进行**一读一写**。这就像把钱从左口袋掏出来，交给跑腿公司，再放进右口袋，白白浪费了路上的开销。

### 🚀 为什么 FB_ADD_1_2 如此“直接”？
零拷贝的精髓在于：**缓冲区本身就是显存的一部分。**
刷新动作仅仅是修改 LTDC 硬件的一个寄存器地址。数据“原地不动”，CPU 算力被彻底释放。

---

## 💻 三、 核心驱动代码实现

### 1. 搬运模式实现 (ltdc_color_fill)
> **避坑提醒**：源地址 `VOL_BUF_1 (0xC0200000)` 严禁与目标地址 `0xC0000000` 重叠，否则会导致 FMC 总线冲突引起白屏闪烁。

```c
void ltdc_color_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color) {
    if (osMutexAcquire(dma2dMutexHandle, osWaitForever) != osOK) return;

    uint32_t width  = ex - sx + 1;
    uint32_t height = ey - sy + 1;
    uint32_t addr   = 0xC0000000 + 2 * (800 * sy + sx); // 物理显存基址

    /* Cache 管理：确保硬件读到的是最新 CPU 写入的数据 */
    SCB_CleanDCache_by_Addr((uint32_t*)color, width * height * 2);

    DMA2D->CR      = DMA2D_M2M;                 // 存储器到存储器模式
    DMA2D->FGMAR   = (uint32_t)color;           // 源：LVGL 缓冲区
    DMA2D->OMAR    = addr;                      // 目：物理显存
    DMA2D->OOR     = 800 - width;               // 目标偏移
    DMA2D->NLR     = (height) | (width << 16);  // 宽高

    DMA2D->IFCR |= DMA2D_IFCR_CTCIF;            // 清标志位
    DMA2D->CR   |= DMA2D_CR_TCIE | DMA2D_CR_START;
    
    /* 阻塞当前任务，等待搬运完成释放总线 */
    osThreadFlagsWait(SIGNAL_DMA2D_TC, osFlagsWaitAll, osWaitForever);
    osMutexRelease(dma2dMutexHandle);
}
```

### 2. 零拷贝模式刷新回调 (disp_flush)
在此模式下，`color_p` 已经是指向物理显存地址的指针。

```c
static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p) {
    #if FB_ADD_1_2  
    /* 1. Cache 管理：将 Cache 中的像素数据强刷回 SDRAM */
    SCB_CleanDCache_by_Addr((uint32_t*)color_p, 800 * 480 * 2);

    /* 2. 瞬间切换显存读取地址 */
    HAL_LTDC_SetAddress(&hltdc, (uint32_t)color_p, 0);
    #endif

    lv_disp_flush_ready(disp_drv);
}
```

---

## 📈 四、 压力测试方案 (Staggered Boxes)

为了验证极限性能，我们设计了满屏（约 160 个）错位移动方块的测试 Demo。

```c
void lv_demo_staggered_boxes(void) {
    int cols = 800 / 40 + 1;
    int rows = 480 / 40 + 1;
    for(int y = 0; y < rows; y++) {
        for(int x = 0; x < cols; x++) {
            lv_obj_t * box = lv_obj_create(lv_scr_act());
            lv_obj_set_size(box, 40, 40);
            lv_obj_set_pos(box, x * 40, y * 40);
            
            /* 设置炫彩动画与错位延迟 */
            uint32_t delay = (x * 50) + (y * 100);
            lv_anim_t a;
            lv_anim_init(&a);
            lv_anim_set_var(&a, box);
            lv_anim_set_values(&a, y * 40, y * 40 + 30);
            lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_y);
            lv_anim_set_time(&a, 1000);
            lv_anim_set_playback_time(&a, 1000);
            lv_anim_set_delay(&a, delay);
            lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
            lv_anim_start(&a);
        }
    }
}
```

---

## 💡 五、 总结与避坑指南

1. **DMA2D 的双重身份**：
   - 在搬运模式中，它是**“搬运工”**。
   - 在内部渲染中，它是**“画师”**（负责混色、填充）。
   - **优化点**：使用零拷贝后，搬运工可以下岗，让 DMA2D 全力投入画师工作。

2. **OS 延时的陷阱**：
   - `lv_timer_handler()` 后的 `osDelay()` 建议设为 **5ms~10ms**。设为 50ms 会强行将 H750 的帧率锁死在 20FPS，白白浪费硬件性能。

3. **MPU 保护是先决条件**：
   - SDRAM 区域必须配置为 **Cacheable** 且 **Bufferable**，并建议开启 **Write-back**。否则，CPU 访问显存的速度会下降 10 倍以上。

4. **显存计算公式**：
   - 800x480 RGB565 每一帧占用空间：$$800 \times 480 \times 2 = 768,000 \text{ 字节}$$。确保 FB0 和 FB1 地址之间留足该空间。
