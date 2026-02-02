# 🚀 STM32H7 FMC 驱动 W9825G6KH-6 SDRAM 移植实战与深度解析

本仓库记录了在 **STM32H7** 系列高性能 MCU 上，利用 FMC（Flexible Memory Controller）外设驱动 Winbond **W9825G6KH-6** SDRAM（32MB）的全过程。这份文档整合了实战中的参数配平经验、时序压榨逻辑以及底层硬件原理，旨在为后续开发者提供一份准确且硬核的参考手册。

---

## 📑 1. 硬件规格与核心参数

* **芯片型号**：Winbond W9825G6KH-6
* **物理容量**：256Mbit (32MB)
* **组织结构**：4M words × 4 banks × 16 bits
* **速度等级**：-6 档位，在 $CAS\ Latency = 3$ 时最高支持 $166\text{MHz}$
* **刷新要求**：8K 次刷新周期 / $64\text{ms}$

---

## 🧠 2. 核心知识点：深入理解 SDRAM

### 🔍 逻辑结构：Bank、行 (Row) 与列 (Column)
SDRAM 内部并非一个连续的大数组，而是一个多层级的表格结构：
* **L-Bank**：逻辑 Bank。该芯片拥有 4 个独立的 Bank。切换 Bank 需要时间，但交替访问不同 Bank 可以隐藏预充电时间，从而显著提高数据带宽。
* **行 (Row) 与列 (Column)**：通过行地址（A0-A12）定位到某一行，再通过列地址（A0-A8）定位到具体的存储单元。
* **✨ 移植心得**：由于地址线是复用的，FMC 中的 `ColumnBitsNumber` 和 `RowBitsNumber` 必须与手册严格对应（本例为 **9 位列地址** 和 **13 位行地址**），否则会导致寻址空间错位。

### ⏱️ 关键时序参数的物理意义
* **$t_{RCD}$ (RAS to CAS Delay)**：行激活到列读写命令之间的延迟。对应代码中的 `SdramTiming.RCDDelay`。它是给电容充电和感测放大器稳定的“准备时间”。
* **$t_{RP}$ (Row Precharge Delay)**：行预充电时间。对应代码中的 `SdramTiming.RPDelay`。关闭当前行并准备激活下一行所需的“重置时间”。
* **CAS Latency (CL)**：列地址选通脉冲潜伏期。即从发出读命令到数据线上出现第一个有效数据所需的“等待周期”。

---

## 🛠️ 3. 移植避坑指南与细节汇总

### ⚡ ① 信号完整性：引脚必须上拉
* **操作**：在 CubeMX 配置中，FMC 所有的地址线、数据线及控制线必须全部配置为 **上拉 (Pull-up)**。
* **原理**：$120\text{MHz}$ 属于极高频率，引脚上的寄生电容会导致电平跳变迟缓。开启上拉能加快信号上升速度，有效抑制信号浮空带来的高频噪声。

### 🔗 ② 全局句柄统一性 (`hsdram1`)
* **操作**：在编写初始化序列时，务必将句柄统一为 CubeMX 生成的 **`hsdram1`**。
* **教训**：移植第三方代码（如正点原子）时，若沿用其默认的 `g_sdram_handle` 且未在全局统一，会导致底层寄存器未被正确驱动，程序直接卡死。

### 📏 ③ 存储容量的单片匹配 (32MB)
* **配置修改**：本例使用的是 **单片** 16-bit SDRAM。
* **坑点**：部分案例基于双片设计（64MB）。若直接使用 $64\text{MB}$ 的测试逻辑，会触发 **地址回环 (Wrap-around)**，新数据会覆盖低地址数据。测试循环上限必须锁定在 **$32\text{MB}$**。

### 🚀 ④ 开启 D-Cache 的决定性影响
* **结论**：STM32H7 访问外部 SDRAM 若不开启 **D-Cache**，性能将下降 10 倍以上！开启后，读写带宽才能真正压榨出 $120\text{MHz}$ 的理论性能。

---

## 💻 4. 核心 FMC 配置参考 (`FMC.c`)

以下为基于 $120\text{MHz}$ 时钟（HCLK3 = 240MHz, 2 分频）的 **标准稳健型** 参数设置：

```c
/* 控制器初始化配置 */
hsdram1.Init.SDBank             = FMC_SDRAM_BANK1;
hsdram1.Init.ColumnBitsNumber   = FMC_SDRAM_COLUMN_BITS_NUM_9;
hsdram1.Init.RowBitsNumber      = FMC_SDRAM_ROW_BITS_NUM_13;
hsdram1.Init.MemoryDataWidth    = FMC_SDRAM_MEM_BUS_WIDTH_16;
hsdram1.Init.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4;
hsdram1.Init.CASLatency         = FMC_SDRAM_CAS_LATENCY_2; 
hsdram1.Init.SDClockPeriod      = FMC_SDRAM_CLOCK_PERIOD_2; // 120MHz
hsdram1.Init.ReadBurst          = FMC_SDRAM_RBURST_ENABLE;
hsdram1.Init.ReadPipeDelay      = FMC_SDRAM_RPIPE_DELAY_0;

/* 核心时序参数配置 (修正版) */
SdramTiming.LoadToActiveDelay    = 2; // tRSC: 2ck
SdramTiming.ExitSelfRefreshDelay = 9; // tXSR: 72ns/8.33ns -> 9 (必须满足)
SdramTiming.SelfRefreshTime      = 6; // tRAS: 42ns/8.33ns -> 6 (手册最小值)
SdramTiming.RowCycleDelay        = 8; // tRC: 必须 >= tRAS + tRP (6+2=8)
SdramTiming.WriteRecoveryTime    = 2; // tWR: 2ck
SdramTiming.RPDelay              = 2; // tRP: 15ns/8.33ns -> 2
SdramTiming.RCDDelay             = 3; // tRCD: 18ns/8.33ns -> 3 (稳妥值)
```

> [!CAUTION]
> **特别注意 (性能关键点)**：
> 在 STM32CubeMX 的图形界面中，由于内部逻辑校验限制（通常要求 $WriteRecoveryTime \ge SelfRefreshTime - RCDDelay$），界面往往不允许将 `WriteRecoveryTime` 设置为 2，最少只能设为 5。
> 为了发挥极致性能，我们必须在代码生成后，**手动在 FMC.c 中将该值改为 2**。

### 📋 刷新率计算与初始化
刷新计数器配置如下：

```c
/* 设置刷新率：在 120MHz 下配置为 918 以满足 64ms 刷新需求 */
HAL_SDRAM_ProgramRefreshRate(&hsdram1, 918);
```

**刷新率公式解析：**
$$COUNT = (\frac{64\text{ms}}{8192}) \times 120\text{MHz} - 20 \approx \mathbf{918}$$

---

## 📊 5. 性能实测结果

基于上述修正后的时序参数，在开启 **D-Cache** 的环境下，实测数据如下（测试环境：HCLK 480MHz, FMC 120MHz）：

| 操作类型 | 实测速度 (MB/s) | 耗时 (s) |
| :--- | :--- | :--- |
| **写入速度 (Write Speed)** | **222.22 MB/s** | 0.018 s |
| **读取速度 (Read Speed)** | **153.85 MB/s** | 0.026 s |

> [!NOTE]
> 写入速度已接近 $120\text{MHz} \times 2\text{Bytes} = 240\text{MB/s}$ 的理论上限，表现极佳。

---
/********************************** END **********************************/
