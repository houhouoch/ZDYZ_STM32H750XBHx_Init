# 🚀 STM32H7 FMC 驱动 W9825G6KH-6 SDRAM 移植实战与深度解析

本仓库记录了在 **STM32H7** 系列高性能 MCU 上，利用 FMC 外设驱动 Winbond **W9825G6KH-6** SDRAM（32MB）的全过程。这份文档整合了参数配平经验、时序压榨逻辑以及底层硬件原理，旨在为后续开发者提供一份准确且硬核的参考手册。

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
* **$t_{RCD}$ (RAS to CAS Delay)**：行激活到列读写命令之间的延迟。对应代码中的 `SdramTiming.RCDDelay`。
* **$t_{RP}$ (Row Precharge Delay)**：行预充电时间。对应代码中的 `SdramTiming.RPDelay`。
* **CAS Latency (CL)**：列地址选通脉冲潜伏期。即从发出读命令到数据线上出现第一个有效数据所需的“等待周期”。

---

## 🛠️ 3. 移植避坑指南与细节汇总

### ⚡ ① 信号完整性：引脚必须上拉
* **操作**：在 CubeMX 配置中，FMC 所有的地址、数据及控制线必须全部配置为 **上拉 (Pull-up)**。
* **原理**：$120\text{MHz}$ 下引脚寄生电容会导致电平跳变迟缓。开启上拉能加快信号上升速度，抑制高频噪声。

### 🔗 ② 全局句柄统一性 (`hsdram1`)
* **教训**：移植正点原子等第三方代码时，务必将代码中的 `g_sdram_handle` 全局替换为 CubeMX 生成的 **`hsdram1`**，否则底层寄存器无法被正确驱动。

### 📏 ③ 存储容量的单片匹配 (32MB)
* **配置修改**：本例使用的是 **单片** 16-bit SDRAM (32MB)。
* **坑点警示**：正点原子（Alientek）等主流案例通常基于 **双片叠加** 设计（64MB）。若直接沿用其 $64\text{MB}$ 的测试逻辑，在 32MB 的硬件上会触发 **地址回环 (Wrap-around)** —— 即当寻址超过 32MB 时，高位地址线失效，数据会重新从 `0x00` 地址开始覆盖。
* **容量校验代码**：通过以下函数，可以实测出硬件的真实容量。如果发生回环，循环将自动跳出并打印出实际物理边界。

```c
/* SDRAM 容量自动扫描与校验测试 */
void sdram_test(void)
{
    uint32_t i;
    uint32_t temp = 0;
    uint32_t sval = 0;      

    /* 第一阶段：每间隔 16KB 写入一个增量索引值 */
    for (i = 0; i < (32 * 1024 * 1024); i += (16 * 1024))
    {
        *(volatile uint32_t *)(SDRAM_BANK_ADDR + i) = temp++;
    }
    
    /* 第二阶段：读取并校验数据，检测地址回环 */
    for (i = 0; i < (32 * 1024 * 1024); i += (16 * 1024))
    {
        temp = *(volatile uint32_t *)(SDRAM_BANK_ADDR + i);
        
        /* 若读出的值不再递增或变小，说明发生了地址回环覆盖 */
        if ((temp != 0) && (temp <= sval))
        {
            printf("Detection Error: Address Wrap-around at %d KB!\r\n", i/1024);
            break;
        }
        else
        {
            sval = temp;
        }               
        /* 实时打印当前检测到的有效容量 */
        printf("SDRAM Valid Capacity: %d KB\r\n", (temp + 1) * 16);
    }
}
```

### 🚀 ④ 开启 D-Cache 的决定性影响
* **结论**：STM32H7 访问外部内存若不开启 **D-Cache**，性能将下降 10 倍以上！开启后需注意处理 DMA 传输时的 Cache 一致性。

---

## 💻 4. 核心 FMC 配置参考 (`FMC.c`)

以下为针对 W9825G6KH-6 的核心参数配置：

```c
/* 核心时序参数 (120MHz 环境) */
SdramTiming.LoadToActiveDelay    = 2; 
SdramTiming.ExitSelfRefreshDelay = 9; 
SdramTiming.SelfRefreshTime      = 6; 
SdramTiming.RowCycleDelay        = 8; // tRC >= tRAS + tRP
SdramTiming.WriteRecoveryTime    = 2; // 重要：需在 FMC.c 中手动从 5 改回 2
SdramTiming.RPDelay              = 2; 
SdramTiming.RCDDelay             = 3; // 120MHz 下设为 3 更稳健
```

> [!CAUTION]
> **性能压榨技巧**：在 CubeMX 界面中，`WriteRecoveryTime` 往往被限制不能小于 5。为了达到极致性能，建议在生成代码后手动将其改为 **2**。

---

## 📊 5. 性能实测结果
测试环境：HCLK 480MHz, FMC 120MHz, 开启 D-Cache。

| 操作类型 | 实测表现 |
| :--- | :--- |
| **写入速度 (Write Speed)** | **222.22 MB/s** |
| **读取速度 (Read Speed)** | **153.85 MB/s** |

---
/********************************** END **********************************/
