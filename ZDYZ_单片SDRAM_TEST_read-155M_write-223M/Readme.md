# 🚀 STM32H7 FMC 驱动 W9825G6KH-6 SDRAM 移植实战与深度解析

本仓库记录了在 **STM32H7** 系列高性能 MCU 上，利用 FMC（Flexible Memory Controller）外设驱动 Winbond **W9825G6KH-6** SDRAM（32MB）的全过程。这份文档整合了实战中的“坑位”经验与底层原理，旨在为后续开发者提供一份准确、易读的参考手册。

---

## 📑 1. 硬件规格与核心参数
* **芯片型号**：Winbond W9825G6KH-6
* **物理容量**：256Mbit (32MB)
* **组织结构**：4M words × 4 banks × 16 bits
* **速度等级**：-6 档位，在 CAS Latency = 3 时最高支持 166MHz
* **刷新要求**：8K次刷新周期 / 64ms

---

## 🧠 2. 核心知识点：深入理解 SDRAM

### 🔍 逻辑结构：Bank、行(Row)与列(Column)
SDRAM 内部并非一个连续的大数组，而是一个多层级的表格结构：
* **L-Bank**：逻辑 Bank。该芯片拥有 4 个独立的 Bank。切换 Bank 需要时间，但交替访问不同 Bank 可以隐藏预充电时间，从而显著提高数据带宽。
* **行(Row)与列(Column)**：通过行地址（A0-A12）定位到某一行，再通过列地址（A0-A8）定位到具体的存储单元。
* **💡 移植心得**：由于地址线是复用的，FMC 中的 `ColumnBitsNumber` 和 `RowBitsNumber` 必须与手册严格对应（本例为 9 位列地址和 13 位行地址），否则会导致寻址空间错位。

### ⏱️ 关键时序参数的物理意义
* **$t_{RCD}$ (RAS to CAS Delay)**：行激活到列读写命令之间的延迟。它是给电容充电和感测放大器稳定的“准备时间”。
* **$t_{RP}$ (Row Precharge Delay)**：行预充电时间。即关闭当前行并准备激活下一行所需的“重置时间”。
* **CAS Latency (CL)**：列地址选通脉冲潜伏期。即从发出读命令到数据线上出现第一个有效数据所需的“等待周期”。
* **💡 实战技巧**：在 120MHz（HCLK3 240MHz 二分频）下，-6 等级的 $t_{RCD}$ 最小要求为 18ns。换算后（$18ns / 8.33ns \approx 2.16$）理论上必须配置为 **3** 个周期。
    > **注意**：移植正点原子案例时其配置值为 2。虽然在常温下可能跑通，但若追求极限稳定性，建议严格遵循手册配置为 3。

---

## 🛠️ 3. 移植避坑指南与细节汇总

### ⚡ ① 信号完整性：引脚必须上拉
* **操作**：在 CubeMX 配置中，FMC 所有的地址线、数据线及控制线必须全部配置为 **上拉 (Pull-up)**。
* **原理**：120MHz 属于极高频率，引脚上的寄生电容会导致电平跳变迟缓。开启上拉能加快信号上升沿速度，有效抑制信号浮空带来的高频噪声。

### 🔗 ② 全局句柄统一性 (`hsdram1`)
* **操作**：在移植驱动代码（如初始化序列）时，务必将句柄统一为 CubeMX 自动生成的 **`hsdram1`**。
* **教训**：作者在初次移植时沿用了正点原子代码中的 `g_sdram_handle`，而没有与工程全局句柄统一，导致底层 FMC 寄存器未被正确操作，程序无法运行。
* **对策**：全局搜索并确保 `HAL_SDRAM_SendCommand` 调用的第一个参数始终是 `&hsdram1`。

### 📏 ③ 存储容量的单片匹配
* **配置修改**：本例使用的是**单片** 16-bit SDRAM（32MB）。
* **坑点**：部分案例基于双片 SDRAM（64MB）设计。若直接使用 64MB 的测试逻辑：
    ```c
    for (i=0; i<(32*1024*1024); i+=(16*1024)) // 必须从 64MB 改为 32MB
    ```
* **后果**：由于地址线物理限制，超出 32MB 的写入会发生**回环（Wrap-around）**，新数据会覆盖低地址数据，导致校验报错并可能导致程序卡死。

### 🚀 ④ 开启 D-Cache 的性能飞跃
* **关键点**：在 STM32H7 上，**必须开启 D-Cache**！
* **实测**：若不开启缓存，CPU 每次访问 SDRAM 都需要等待 FMC 总线周期，性能会下降 10 倍以上。开启后，读写带宽才能真正匹配 120MHz 的理论性能。

---

## 💻 4. 核心 FMC 配置参考 (`FMC.c`)

以下为基于本工程实测的 `MX_FMC_Init` 参数设置：

```c
/* 控制器初始化配置 */
hsdram1.Init.SDBank             = FMC_SDRAM_BANK1;
hsdram1.Init.ColumnBitsNumber   = FMC_SDRAM_COLUMN_BITS_NUM_9;
hsdram1.Init.RowBitsNumber      = FMC_SDRAM_ROW_BITS_NUM_13;
hsdram1.Init.MemoryDataWidth    = FMC_SDRAM_MEM_BUS_WIDTH_16;
hsdram1.Init.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4;
hsdram1.Init.CASLatency         = FMC_SDRAM_CAS_LATENCY_2; // 需与模式寄存器一致
hsdram1.Init.SDClockPeriod      = FMC_SDRAM_CLOCK_PERIOD_2; // 240MHz/2 = 120MHz
hsdram1.Init.ReadBurst          = FMC_SDRAM_RBURST_ENABLE;
hsdram1.Init.ReadPipeDelay      = FMC_SDRAM_RPIPE_DELAY_0;

/* 时序参数配置 (针对 W9825G6KH-6) */
SdramTiming.LoadToActiveDelay    = 2;
SdramTiming.ExitSelfRefreshDelay = 8;
SdramTiming.SelfRefreshTime      = 7;
SdramTiming.RowCycleDelay        = 7;
SdramTiming.WriteRecoveryTime    = 2; // 代码生成后可手动微调
SdramTiming.RPDelay              = 2;
SdramTiming.RCDDelay             = 2;
