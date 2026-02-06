# 🚀 STM32H750 + LVGL v8.3 高性能移植与双架构优化全纪录

本项目基于 **STM32H750XBH6 (北极星开发板)**，旨在实现 800x480 分辨率下的极致 UI 性能。本文档完整记录了从基础移植到利用 **DMA2D** 与 **LTDC 零拷贝 (Zero-copy)** 技术压榨 H750 性能的全过程。

> **参考资料**：[LVGL v8.3 移植参考官方文档](https://www.cnblogs.com/lesterbor/p/17953045)

---

## 🛠️ 一、 核心环境配置 (lv_conf.h)

### 1. 时钟心跳 (Tick)
**必须打开 LVGL 的时钟配置，否则动画无法运行。** 建议将心跳直接挂载到 FreeRTOS 的系统 Tick 上，确保 UI 逻辑与系统任务高度同步。

```c
#define LV_TICK_CUSTOM 1
#if LV_TICK_CUSTOM
    #define LV_TICK_CUSTOM_INCLUDE "FreeRTOS.h"    /* 使用 FreeRTOS 的系统 Tick 作为心跳源 */
    #define LV_TICK_CUSTOM_SYS_TIME_EXPR (xTaskGetTickCount()) 
#endif
```

### 2. 内存池分配 (SDRAM vs 内部 RAM)
针对大规模 GUI 应用，内部 AXI SRAM (512KB) 往往无法支撑复杂的 UI 结构体。

* **配置方案**：将内存池设在外部 SDRAM。
* **优点**：空间充裕（本例设为 1MB），支持成百上千个复杂的 UI 对象同时存在。
* **注意**：由于 SDRAM 挂在 FMC 总线上，访问速度略慢于内部 AXI 总线。

```c
/* 内存池大小：1MB */
#define LV_MEM_SIZE (1024U * 1024U)          
/* 内存池首地址：挂载到外部 SDRAM 偏移 8MB 处 (避开显存区) */
#define LV_MEM_ADR  0xC0800000               
```

### 3. 硬件加速 (GPU/DMA2D)
开启 STM32 特有的 DMA2D 加速引擎，接管色块填充、透明度混合等任务，释放 CPU 算力。

```c
#define LV_USE_GPU_STM32_DMA2D    1
#define LV_GPU_DMA2D_CMSIS_INCLUDE "stm32h7xx.h"
```

---

## 🏗️ 二、 两种显示驱动架构深度对比

| 维度 | 模式一：BUF_1_2 (经典搬运型) | 模式二：FB_ADD_1_2 (零拷贝切换型) |
| :--- | :--- | :--- |
| **底层核心** | MemCPY (内存拷贝) | Pointer Swap (指针切换) |
| **刷新函数** | `ltdc_color_fill` (DMA2D 搬运) | `HAL_LTDC_SetAddress` (修改显存指针) |
| **数据流向** | 绘制缓冲 $\xrightarrow{DMA2D}$ 物理显存 | 绘制缓冲 $\equiv$ 物理显存 (原地绘制) |
| **性能开销** | **高**：CPU 占用约 75% | **极低**：CPU 占用约 25% |
| **硬件要求** | SPI / 8080 / LTDC 屏通用 | 必须是支持显存映射的 LTDC 屏 |

---

## 💻 三、 核心驱动代码实现

### 1. 搬运模式实现 (ltdc_color_fill)
> **注意**：源地址（如 0xC0200000）严禁与目标地址重合，否则会导致总线死锁引起白屏。

```c
void ltdc_color_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color){    
    if (osMutexAcquire(dma2dMutexHandle, osWaitForever) != osOK) return;
    
    uint32_t width  = ex - sx + 1;
    uint32_t height = ey - sy + 1;
    /* 目标地址硬编码：物理显存基地址 0xC0000000 */
    uint32_t addr   = 0xC0000000 + 2 * (800 * sy + sx); 

    SCB_CleanDCache_by_Addr((uint32_t*)color, width * height * 2);

    DMA2D->CR      = DMA2D_M2M;  
    DMA2D->FGMAR   = (uint32_t)color;  // 源
    DMA2D->OMAR    = addr;             // 目
    DMA2D->OOR     = 800 - width;      
    DMA2D->NLR     = (height) | (width << 16);    

    DMA2D->IFCR |= DMA2D_IFCR_CTCIF;
    DMA2D->CR   |= DMA2D_CR_TCIE | DMA2D_CR_START;
    
    osThreadFlagsWait(SIGNAL_DMA2D_TC, osFlagsWaitAll, osWaitForever); 
    osMutexRelease(dma2dMutexHandle);
}
```

### 2. 零拷贝模式刷新回调 (disp_flush)
在该模式下，`color_p` 传递的地址本身就是物理显存地址（FB0/FB1）。

```c
static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p){
    #if FB_ADD_1_2  
    /* 1. Cache 管理：确保像素数据刷入物理 SDRAM，防止花屏 */
    SCB_CleanDCache_by_Addr((uint32_t*)color_p, 800 * 480 * 2);

    /* 2. 切换显存地址：color_p 会在 FB0/FB1 间自动切换 */
    HAL_LTDC_SetAddress(&hltdc, (uint32_t)color_p, 0);
    
    #endif

    lv_disp_flush_ready(disp_drv);
}
```

---

## 📈 四、 实验结论 (160 个错位动画方块测试)
* **BUF_1_2 模式**：存在 DMA2D 二次搬运负载，CPU 占用约 **75%**。
* **FB_ADD_1_2 模式**：消除搬运开销，CPU 占用直线下降至 **25%**。
* **总结**：零拷贝方案不仅解决了高频刷新下的白屏闪烁问题，还释放了 50% 的 CPU 算力给 CAN 通信及传感器采样任务。

---

## 💡 五、 避坑指南总结
1.  **时钟配置**：必须在 `lv_conf.h` 中正确配置 `LV_TICK_CUSTOM`，否则动画将呈静态。
2.  **白屏原因**：通常是因为 `ltdc_color_fill` 中源地址与目标地址重叠，导致 FMC 总线冲突。
3.  **MPU 保护**：SDRAM 区域必须在 MPU 设置中配置为 **Cacheable** 且 **Bufferable**，否则读写效率极低。
4.  **显存空间**：确保 LCD_FB0 (0xC0000000) 与 LCD_FB1 (0xC00B8800) 之间预留足够的物理空间。
    * 计算公式：$$800 \times 480 \times 2 = 768,000 \text{ 字节}$$
