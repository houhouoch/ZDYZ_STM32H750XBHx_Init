# 🚀 STM32H7 FMC 驱动 W9825G6KH-6 双片并联 (32-bit) 极致性能指南

本项目记录了在 **STM32H7** 系列微控制器上，利用 FMC（Flexible Memory Controller）外设驱动两片 Winbond **W9825G6KH-6** 组成的 **32 位带宽、64MB 总容量** SDRAM 的实战过程。通过硬件层面的位宽倍增与软件层面的时序优化，实现了接近理论上限的 **446.93 MB/s** 写入吞吐性能。

---

## 🧠 1. 核心深度解析：双片并联的硬件逻辑

对于初学者来说，理解 32 位并联的物理结构是操作的关键。

### 🔍 为什么位宽翻倍性能也翻倍？
单片 W9825G6KH-6 是 16 位位宽。当我们将两片芯片并联时：
* **地址线共享**：两片芯片的 $A0 \sim A12$、行选择线 $BA0 \sim BA1$、以及控制信号（$CLK, CKE, CAS, RAS, WE$）全部连在一起。CPU 发出一个地址，两片芯片会同时响应。
* **数据线分离（堆叠）**：
    * **芯片 A** 连接 FMC 的低位数据线 $D0 \sim D15$。
    * **芯片 B** 连接 FMC 的高位数据线 $D16 \sim D31$。
* **结果**：CPU 执行一次 32 位的读写指令，实际上是让两片芯片各存/取了 16 位数据。在相同的时钟频率下，单次传输的数据量直接翻倍，这就是性能爆发的根源。

### 📏 容量是如何演变的？
* **逻辑格子**：单片容量为 $4M \times 4Banks \times 16bits = 32MB$。
* **并联后**：地址格子的数量没变（依然是 13 行地址 + 9 列地址），但每个格子的“深度”从 16 位变成了 32 位。
* **总容量**：$32MB \times 2 = 64MB$。

---

## 🛠️ 2. CubeMX 关键配置改动

从单片 16 位模式切换到双片 32 位模式，在 STM32CubeMX 中需执行以下核心操作：

1.  **Memory Data Width**: 由 `16 bits` 修改为 **`32 bits`**。
    * *意义*：激活内核对 $D16 \sim D31$ 高位数据总线的管理。
2.  **Byte Enable**: 设置为 **`32-bit`** (或使能对应的字节屏蔽信号)。
    * *意义*：使能 $NBL0 \sim NBL3$ 四根字节掩码线。这极其重要！它允许 CPU 在 32 位的总线上精确执行单字节（8-bit）或半字（16-bit）的改写，而不会误伤同一地址的其他位。

---

## ⏱️ 3. 极致性能时序参数 (120MHz)

为了压榨出超过 440MB/s 的性能，时序配平必须极其精确。以下是基于 HCLK 480MHz（FMC 120MHz）的极限参数：

| 参数项 | 推荐值 | 物理依据与调优心得 |
| :--- | :--- | :--- |
| **ExitSelfRefreshDelay** | **9** | 满足手册 $72\text{ns}$ 要求 |
| **SelfRefreshTime ($t_{RAS}$)** | **6** | 满足手册 $42\text{ns}$ 最小值 |
| **RowCycleDelay ($t_{RC}$)** | **8** | 必须满足 $t_{RC} \ge t_{RAS} + t_{RP} (6+2=8)$ |
| **WriteRecoveryTime** | **2** | **性能关键**：CubeMX 限制最小为 5，生成代码后需在 `FMC.c` 手动改回 **2** |
| **RPDelay ($t_{RP}$)** | **2** | 满足手册 $15\text{ns}$ 要求 |
| **RCDDelay ($t_{RCD}$)** | **3** | 满足手册 $18\text{ns}$ 要求，设为 3 更稳健 |

> [!WARNING]
> **必须配置 MPU 开启 L1 Cache**（建议开启 Write-back 模式），否则外部总线频繁停顿，性能将不及目前的十分之一。

---

## 💻 4. 极限速度测试程序 (循环展开优化)

为了测试真实带宽，建议使用 8 路循环展开，减少指令跳转对总线的占用：

```c
#define SDRAM_BANK_ADDR      (0xC0000000UL)
#define SDRAM_TOTAL_WORDS    (64 * 1024 * 1024 / 4) // 总 64MB / 4字节

void SDRAM_Speed_Test(void) {
    volatile uint32_t *pBuf = (uint32_t *)SDRAM_BANK_ADDR;
    uint32_t i, elapsed;

    /* --- 极致写入测试 (Write-Back 模式) --- */
    Get_System_Time(1); // 启动计时
    for (i = 0; i < SDRAM_TOTAL_WORDS; i += 8) {
        pBuf[i+0] = 0xAAAAAAAA; pBuf[i+1] = 0xBBBBBBBB;
        pBuf[i+2] = 0xCCCCCCCC; pBuf[i+3] = 0xDDDDDDDD;
        pBuf[i+4] = 0xEEEEEEEE; pBuf[i+5] = 0xFFFFFFFF;
        pBuf[i+6] = 0x11111111; pBuf[i+7] = 0x22222222;
    }
    elapsed = Get_System_Time(2);
    printf("Write Speed: %.2f MB/s\r\n", (64.0f * 1000000.0f) / elapsed);

    /* --- 极致读取测试 --- */
    volatile uint32_t temp;
    Get_System_Time(1);
    for (i = 0; i < SDRAM_TOTAL_WORDS; i += 8) {
        temp = pBuf[i+0]; temp = pBuf[i+1]; temp = pBuf[i+2]; temp = pBuf[i+3];
        temp = pBuf[i+4]; temp = pBuf[i+5]; temp = pBuf[i+6]; temp = pBuf[i+7];
    }
    (void)temp;
    elapsed = Get_System_Time(2);
    printf("Read Speed: %.2f MB/s\r\n", (64.0f * 1000000.0f) / elapsed);
}
```

---

## 📊 5. 实测性能报告

**测试环境**：HCLK 480MHz / FMC 120MHz / 32-bit 并联 / D-Cache 开启。

| 指标 | 测试结果 | 性能分析 |
| :--- | :--- | :--- |
| **写入速度** | **446.93 MB/s** | 达到理论上限 ($480MB/s$) 的 **93%**，表现惊人。 |
| **读取速度** | **238.81 MB/s** | 虽然受限于总线仲裁，但已远超单片 16 位模式。 |

---

## 💡 总结
通过将 SDRAM 配置为 32 位双片并联，我们不仅获得了 **64MB** 的海量存储，更利用硬件位宽的原生优势突破了单片模式的带宽瓶颈。对于需要驱动 **RGB888 接口高分辨率屏幕** 或进行 **4K 级数据实时采集** 的应用，这种 32 位并联方案是 STM32H7 的终极形态。

/********************************** END **********************************/
