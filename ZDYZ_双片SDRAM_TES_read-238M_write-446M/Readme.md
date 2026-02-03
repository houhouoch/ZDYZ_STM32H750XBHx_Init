# 🚀 STM32H7 FMC 驱动 W9825G6KH-6 双片并联 (32-bit) 极致性能指南

本项目记录了在 **STM32H7** 系列高性能 MCU 上，利用 FMC（Flexible Memory Controller）驱动两片 Winbond **W9825G6KH-6** 组成的 **32 位带宽、64MB 总容量** SDRAM 的实战全过程。通过硬件位宽倍增、时序精细压榨及 FMC 写 FIFO 的深度应用，实现了接近理论极限的 **446.93 MB/s** 写入性能。

---

## 🧠 1. 核心深度解析：双片并联硬件逻辑

理解“双片并联”是掌握 32 位带宽操作的核心。两片 16 位的 SDRAM 协同工作，逻辑如下：

* **地址共享**：两片芯片物理上共享同一组地址线（$A0 \sim A12$）和行选择线（$BA0, BA1$）。CPU 发出一个地址，两片芯片会同时定位到内部相同的存储单元。
* **数据分工（堆叠）**：
    * **芯片 A**：负责数据总线的低位段 $D0 \sim D15$。
    * **芯片 B**：负责数据总线的高位段 $D16 \sim D31$。
* **性能爆发**：单次读写由 $2\text{ Bytes}$ 变为 $4\text{ Bytes}$，理论带宽翻倍。
    $$\text{理论带宽 (120 MHz)} = 120\text{ MHz} \times 4\text{ Bytes} = 480\text{ MB/s}$$
* **容量演变**：
    $$\text{总容量} = 32\text{ MB} \times 2 = 64\text{ MB}$$

---

## 🛠️ 2. CubeMX 关键配置改动

从单片 16 位切换到双片 32 位，CubeMX 中的这两项设置至关重要：

1.  **Memory Data Width**: 修改为 **`32 bits`**。
    * *作用*：激活 $D16 \sim D31$ 高位数据总线的管理逻辑。
2.  **Byte Enable**: 设置为 **`32-bit`**。
    * *作用*：使能 $NBL0 \sim NBL3$ 四根字节掩码线。这允许 CPU 在 32 位总线上执行精确的字节级访问，避免误写相邻数据。

---

## ⏱️ 3. 极致性能时序参数 (120MHz)

为了跑出理想性能，时序配平必须极其精确。以下是基于 HCLK 480MHz 测得的极限配置：

| 参数项 | 推荐值 | 物理依据与心得 |
| :--- | :---: | :--- |
| **ExitSelfRefreshDelay** | **9** | 满足手册 $t_{XSR} (72\text{ ns})$ 要求 |
| **SelfRefreshTime ($t_{RAS}$)** | **6** | 对应手册 $t_{RAS} (42\text{ ns})$ 最小值 |
| **RowCycleDelay ($t_{RC}$)** | **8** | 必须满足 $t_{RC} \ge t_{RAS} + t_{RP}$ ($6+2=8$) |
| **WriteRecoveryTime** | **2** | **性能核心**：生成代码后需在 `FMC.c` 手动从 5 改回 **2** |
| **RPDelay ($t_{RP}$)** | **2** | 对应手册 $t_{RP} (15\text{ ns})$ |
| **RCDDelay ($t_{RCD}$)** | **3** | 对应手册 $t_{RCD} (18\text{ ns})$，设为 3 更稳健 |

> [!WARNING]
> **必须开启 D-Cache**：STM32H7 若不开启 L1 Cache（推荐 Write-back 模式），外部总线会因频繁挂起导致性能下降 10 倍以上。

---

## 🏆 4. 极致压榨：FMC 写 FIFO (Write FIFO) 解析

在 **100KHz 高频中断干扰** 的真实工况下，我们对比了 FMC 写 FIFO 的巨大作用：

### 📊 实验数据 (64MB 连续写入)

| 测试场景 | 写入速率 (MB/s) | 性能状态 | 备注 |
| :--- | :--- | :--- | :--- |
| **禁止 Write FIFO** | **139.41 MB/s** | 性能暴跌 | CPU 必须同步等待物理总线 |
| **开启 Write FIFO** | **400.97 MB/s** | **解耦爆发** | 吞吐量相比禁止状态提升 **+65.23%** |

### 🧠 为什么 Write FIFO 是“入场券”？
1.  **总线解耦**：允许 CPU 将数据丢进缓存池后立即返回，无需等待 SDRAM 的物理存储周期。
2.  **抗干扰鲁棒性**：在高频中断（100KHz）干扰下，FIFO 充当了“流量池”。即便 CPU 暂时处理中断，FMC 硬件仍能利用缓存数据维持外部总线满载运行，使吞吐量依然保持在 **90%** 左右的水平。

### 📝 防御性编程：寄存器级强制使能
虽然 H750 硬件复位后默认开启 FIFO，但在初始化序列中显式执行以下代码能确保状态的绝对确定性：
```c
/* 显式开启 FMC 硬件写 FIFO，压榨极致性能 */
FMC_Bank1_R->BTCR[0] &= ~FMC_BCR1_WFDIS;
```

---

## 💻 5. 极限速度测试程序 (8 路循环展开)

```c
#define SDRAM_BANK_ADDR      (0xC0000000UL)
#define SDRAM_TOTAL_WORDS    (64 * 1024 * 1024 / 4) // 64MB / 4字节

void SDRAM_Speed_Test(void) {
    volatile uint32_t *pBuf = (uint32_t *)SDRAM_BANK_ADDR;
    uint32_t i, elapsed;

    /* --- 极致写入测试 --- */
    Timer_Start(); 
    for (i = 0; i < SDRAM_TOTAL_WORDS; i += 8) {
        pBuf[i+0] = 0xAAAAAAAA; pBuf[i+1] = 0xBBBBBBBB;
        pBuf[i+2] = 0xCCCCCCCC; pBuf[i+3] = 0xDDDDDDDD;
        pBuf[i+4] = 0xEEEEEEEE; pBuf[i+5] = 0xFFFFFFFF;
        pBuf[i+6] = 0x11111111; pBuf[i+7] = 0x22222222;
    }
    elapsed = Timer_Stop();
    printf("Write Speed: %.2f MB/s\r\n", (64.0f * 1000000.0f) / elapsed);
}
```

---

## 📊 6. 实测性能报告总结

**测试环境**：HCLK 480MHz / FMC 120MHz / 32-bit 并联 / D-Cache 开启。

* **理想工况 (独占总线)**：**446.93 MB/s** (理论上限的 **93%**)
* **真实工况 (100KHz 中断 + FIFO)**：**400.97 MB/s**
* **恶劣工况 (100KHz 中断 - 无 FIFO)**：**139.41 MB/s**

### 💡 核心启示
在高性能 MCU 场景中，**Write FIFO 的本质是用硬件空间换取软件容错**。通过 32 位并联方案，STM32H7 能够彻底消除 **RGB888 高分屏驱动** 或 **4K 级数据采集** 时的总线拥塞，是该芯片的“终极存储形态”。

/********************************** END **********************************/
