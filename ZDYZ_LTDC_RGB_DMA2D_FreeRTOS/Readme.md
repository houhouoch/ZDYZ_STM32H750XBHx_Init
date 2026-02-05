# 🚀 STM32H750 高性能 GUI 加速：DMA2D + FreeRTOS 深度实战

本项目旨在解决 STM32H7 系列在 RTOS 环境下执行图形加速时的三大痛点：**多任务竞态冲突**、**实时性保障（优先级翻转）** 以及 **CPU 效率最大化**。

---

## 🔗 1. 参考资源与配置

在进行 RTOS 配置时，建议参考以下保姆级教程，确保内核参数（如时钟源、内存管理）设置正确：
* **[CubeMX 配置 RTOS 详解]** [https://developer.aliyun.com/article/992044](https://developer.aliyun.com/article/992044)

---

## 🧠 2. 核心设计：DMA2D 自动识别任务 ID

在复杂的应用中，波形任务、菜单任务、LVGL 任务都会竞争 DMA2D。我们通过“识别任务 ID”实现了硬件的精准调度。

### 2.1 任务身份登记逻辑
为了让中断服务函数（ISR）知道该唤醒哪一个“正在睡觉”的任务，我们在启动硬件前通过 `osThreadGetId()` 登记任务身份。

```c
/* 记录当前正在调用 DMA2D 的任务 ID */
osThreadId_t drawingTaskHandle = NULL;
osMutexId_t dma2dMutexHandle;

/**
 * @brief DMA2D 存储器到存储器搬运 (M2M) - 多任务安全版
 */
void ltdc_color_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color)
{
    // 1. 获取互斥锁：确保同一时间只有一个任务在修改硬件寄存器
    if (osMutexAcquire(dma2dMutexHandle, osWaitForever) != osOK) return;

    uint32_t width  = ex - sx + 1;
    uint32_t height = ey - sy + 1;
    /* 显存偏移地址计算 (代入 800 宽度) */
    uint32_t addr   = 0xC0000000 + 2 * (800 * sy + sx); 

    /* 2. Cache 管理：H7 必须手动清理数据缓存，确保 DMA2D 搬运的是最新数据 */
    SCB_CleanDCache_by_Addr((uint32_t*)color, width * height * 2);

    /* 3. 等待硬件就绪并配置参数 */
    while (DMA2D->CR & DMA2D_CR_START);

    DMA2D->CR      = DMA2D_M2M; 
    DMA2D->FGMAR   = (uint32_t)color; 
    DMA2D->OMAR    = addr;
    DMA2D->OOR     = 800 - width;
    DMA2D->FGPFCCR = LTDC_PIXEL_FORMAT_RGB565;
    DMA2D->OPFCCR  = LTDC_PIXEL_FORMAT_RGB565;
    DMA2D->NLR     = (height) | (width << 16);
    
    /* 【核心】记录当前任务 ID 号 */
    drawingTaskHandle = osThreadGetId();
    
    /* 4. 清除标志位、使能 TCIE 中断并启动 */
    DMA2D->IFCR |= DMA2D_IFCR_CTCIF; 
    DMA2D->CR   |= DMA2D_CR_TCIE;
    DMA2D->CR   |= DMA2D_CR_START;

    /* 5. 阻塞当前任务：让出 CPU，进入阻塞态等待中断信号 */
    osThreadFlagsWait(SIGNAL_DMA2D_TC, osFlagsWaitAll, osWaitForever);

    // 释放互斥锁
    osMutexRelease(dma2dMutexHandle);
}
```

### 2.2 中断服务函数 (ISR)
ISR 负责将“完工信号”精准投递给发起任务，实现“硬件干活，CPU 歇着”。

```c
void DMA2D_IRQHandler(void)
{
    extern osThreadId_t drawingTaskHandle;
    if (DMA2D->ISR & DMA2D_ISR_TCIF) 
    {
        DMA2D->IFCR |= DMA2D_IFCR_CTCIF; // 清除传输完成标志
        if (drawingTaskHandle != NULL) {
            /* 精准发送信号唤醒对应的任务 */
            osThreadFlagsSet(drawingTaskHandle, SIGNAL_DMA2D_TC); 
        }
    }
    HAL_DMA2D_IRQHandler(&hdma2d);
}
```

---

## ⚡ 3. 实时性保障：优先级继承的应用

在 RTOS 环境下，如果一个低优先级任务持有 DMA2D 锁，而高优先级波形任务请求锁，会发生**优先级翻转**。

* **解药**：使用 `osMutexPrioInherit` 特性。
* **效果**：当高优先级任务申请已被占用的锁时，内核临时将持锁任务的优先级提升至最高，确保其尽快放锁，从而保障系统的硬实时响应。

> [!WARNING]
> **运行检查**：千万别忘了在启动内核（`osKernelStart`）之前调用 `DMA2D_Mutex_Init()` 进行锁的初始化。

---

## 🗺️ 4. 架构设计：什么时候用锁？什么时候用消息队列？

| 设计工具 | 应用场景 | 典型示例 |
| :--- | :--- | :--- |
| **互斥锁 (Mutex)** | **独占硬件资源**。保护具有原子性的物理操作，防止寄存器配置被多任务改乱。 | **DMA2D 寄存器配置**、SPI 总线切换、全局电力参数结构体读写。 |
| **消息队列 (Queue)** | **逻辑解耦与异步通知**。跨任务传递数据，实现“生产者-消费者”模型。 | **CAN 接收任务** 收到电参数信号后放入队列，**GUI 任务** 监听队列并刷新屏幕数值。 |

---

## 🖌️ 5. DMA2D 填充模式深度对比

### 🟦 ltdc_fill (R2M 模式)
* **模式名称**：`Register-to-Memory` (R2M)。
* **数据源**：芯片内部寄存器 (`OCOLR`)。
* **工作过程**：将颜色值（如红色 `0xF800`）写进寄存器，DMA2D 直接向显存区域高速“喷射”该单色。
* **优势**：**极快**。无需读取 RAM，总线占用率最低。
* **用途**：清屏、画背景色块、画进度条底色。

### 🟩 ltdc_color_fill (M2M 模式)
* **模式名称**：`Memory-to-Memory` (M2M)。
* **数据源**：内存（SRAM/Flash）中的数组地址。
* **工作过程**：DMA2D 充当搬运工，将缓冲区像素（如图片、UI 图标）一个一个搬运到显存。
* **优势**：**灵活**。支持搬运渐变、透明叠加或 LVGL 渲染好的复杂界面。
* **用途**：显示图标、刷写图片、波形缓冲区刷新、对接 UI 库。

---

## 💡 总结
通过 `osThreadGetId` 实现硬件的身份识别，结合优先级继承机制，STM32H750 能够在保证波形显示硬实时的前提下，维持 UI 界面的极致流畅响应。

/********************************** END **********************************/
