# STM32H7 FMC 驱动 W9825G6KH-6 SDRAM 移植实战指南

本项目记录了在 STM32H7 系列单片机（HCLK 480MHz, FMC 时钟源为 D1HCLK 240MHz）上移植 Winbond **W9825G6KH-6** SDRAM 的全过程。文档汇总了时序配置、硬件细节、软件坑位以及性能优化建议。

## 1. 硬件规格概览 (W9825G6KH-6)
* [cite_start]**物理容量**：256Mbit (32MB) [cite: 3, 18]。
* [cite_start]**组织结构**：4M words × 4 banks × 16 bits [cite: 3, 18, 33]。
* [cite_start]**最高频率**：166MHz (CAS Latency = 3 模式下) [cite: 21, 45]。
* [cite_start]**刷新要求**：8K次刷新周期 / 64ms [cite: 41, 438]。
* [cite_start]**主要引脚**：A0-A12 (行地址), A0-A8 (列地址), BA0-BA1 (Bank选择), DQ0-DQ15 (数据线) [cite: 167]。

## 2. 核心时序配置 (120MHz 环境)
当 HCLK3 为 240MHz 且 FMC 分频设为 2 时，SDRAM 的工作频率为 **120MHz** ($t_{CK} \approx 8.33ns$)。

### CubeMX 定时参数建议值
为了满足 W9825G6KH-6 的 AC 特性并规避 CubeMX 的逻辑校验限制，建议配置如下：

| CubeMX 配置项 | 建议值 (Cycles) | 理由 (基于 -6 速度档) |
| :--- | :--- | :--- |
| **Load To Active Delay** | 2 | [cite_start]$t_{RSC}$ 至少需 2 周期 [cite: 438]。 |
| **Exit Self Refresh Delay** | 9 | [cite_start]$t_{XSR}$ 最小 72ns，换算约为 8.64 周期 [cite: 438]。 |
| **Self Refresh Time** | 6 | [cite_start]$t_{RAS}$ 最小 42ns，换算约为 5.04 周期 [cite: 438]。 |
| **Row Cycle Delay** | 9 | [cite_start]$t_{RC}$ 最小 60ns [cite: 438]，且需满足 $\ge t_{RAS} + t_{RP}$。 |
| **Write Recovery Time** | 2 | [cite_start]手册最小值 [cite: 438]。注：若 CubeMX 报错，需优先满足 $t_{WR} \ge t_{RAS} - t_{RCD}$ 约束。 |
| **RP Delay** | 2 | [cite_start]$t_{RP}$ 最小 15ns [cite: 438]。 |
| **RCD Delay** | 3 | [cite_start]$t_{RCD}$ 针对 -6 等级为 18ns，需 3 周期 [cite: 438]。 |

## 3. 关键移植细节 (避坑总结)

### ① GPIO 强制上拉
* **操作**：在 CubeMX 的引脚配置中，务必将所有 FMC 相关的引脚（地址、数据、控制线）配置为 **上拉 (Pull-up)**。
* **原因**：高速同步器件对信号稳定性要求极高，上拉可防止信号在切换瞬间浮空导致的逻辑误判。

### ② 全局句柄统一 (`hsdram1`)
* **操作**：在编写 `sdram_initialization_sequence` 初始化序列时，确保将所有对 `HAL_SDRAM_SendCommand` 的调用句柄统一为 CubeMX 自动生成的全局句柄 **`hsdram1`**。
* **原因**：避免因句柄不统一（如混用 `g_sdram_handle`）导致的硬件状态不同步或寄存器访问冲突。

### ③ CAS Latency (CL) 必须匹配
* **配置**：FMC 控制器的 `CASLatency` 必须与发送给芯片模式寄存器的指令完全一致。
* [cite_start]**操作**：若控制器设为 CL3，则初始化序列中 `ModeRegisterDefinition` 的位 4-6 必须设为 `011` [cite: 684, 710]。
* **风险**：时序错位会导致数据读写异常或总线挂起（卡死）。

### ④ 存储容量校正
* [cite_start]**规格**：单片 W9825G6KH-6 容量为 32MB [cite: 18]。
* **代码修改**：测试函数（如 `sdram_test`）的地址循环上限必须设为 `32*1024*1024`，防止地址回环覆盖低端内存或触发非法访问。

### ⑤ 必须开启 D-Cache
* **操作**：在 CPU 初始化后调用 `SCB_EnableDCache()`。
* **结论**：STM32H7 访问外部 SDRAM 若不开启数据缓存，读写速度将慢 10 倍以上。开启后方可发挥 120MHz FMC 的真实带宽。

## 4. 读写速度测试建议
建议采用 32 位指针访问并配合循环展开，以压榨最大带宽。

```c
/**
 * @brief SDRAM 读取速度测试示例 (32MB)
 */
void ReadSpeedTest(void) {
    uint32_t cnt;
    volatile uint32_t *pBuf = (uint32_t *)SDRAM_BANK_ADDR;
    volatile uint32_t temp;
    
    Get_System_Time(1);
    for (uint32_t i = 0; i < (1024 * 1024 * 32 / 4); i += 8) {
        temp = *pBuf++; temp = *pBuf++; temp = *pBuf++; temp = *pBuf++;
        temp = *pBuf++; temp = *pBuf++; temp = *pBuf++; temp = *pBuf++;
    }
    cnt = Get_System_Time(2);
    printf("Read Rate: %d MB/s\r\n", 32 * 1000000 / cnt);
}