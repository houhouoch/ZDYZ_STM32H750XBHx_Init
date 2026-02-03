# 🚀 STM32H7 FMC 驱动 W9825G6KH-6 双片并联 (32-bit) 极致性能指南

本项目记录了在 **STM32H7** 系列高性能 MCU 上，利用 FMC（Flexible Memory Controller）驱动两片 Winbond **W9825G6KH-6** 组成的 **32 位带宽、64MB 总容量** SDRAM 的实战全过程。通过硬件位宽倍增、时序精细压榨及 FMC 写 FIFO 的深度应用，实现了接近理论极限的 **446.93 MB/s** 写入性能。

---

## 🧠 1. 核心深度解析：双片并联硬件逻辑

理解“双片并联”是掌握 32 位带宽操作的核心。两片 16 位的 SDRAM 协同工作，逻辑如下：

* **地址共享**：两片芯片物理上共享同一组地址线（$A0 \sim A12$）和逻辑 Bank 选择线（$BA0, BA1$）。CPU 发出一个地址，两片芯片会同时定位到内部相同的存储单元。
* **数据分工（堆叠）**：
    * **芯片 A**：连接 FMC 数据总线的低位段 $D0 \sim D15$。
    * **芯片 B**：连接 FMC 数据总线的高位段 $D16 \sim D31$。
* **物理公式**：在 $120\text{ MHz}$ 频率下，单次读写位宽由 $2\text{ Bytes}$ 变为 $4\text{ Bytes}$：
    $$\text{理论带宽} = 120\text{ MHz} \times 4\text{ Bytes} = 480\text{ MB/s}$$
* **容量演变**：
    $$\text{总容量} = 32\text{ MB} \times 2 = 64\text{ MB}$$

---

## 🛠️ 2. CubeMX 关键配置改动

从单片 16 位切换到双片 32 位，CubeMX 中的这两项设置是性能的基石：

1.  **Memory Data Width**: 修改为 **`32 bits`**。
    * *作用*：激活 $D16 \sim D31$ 高位数据总线的管理逻辑。
2.  **Byte Enable**: 设置为 **`32-bit`**。
    * *作用*：使能 $NBL0 \sim NBL3$ 四根字节掩码线。这允许 CPU 执行精确的字节级（8-bit）跨片访问，避免误改写相邻数据。

---

## ⏱️ 3. 极致性能时序参数 (120MHz)

以下是基于 HCLK 480MHz 测得的极限配置，旨在压榨每一纳秒的性能：

| 参数项 | 推荐值 | 物理依据 |
| :--- | :---: | :--- |
| **ExitSelfRefreshDelay** | **9** | 满足手册 $t_{XSR} (72\text{ ns})$ 要求 |
| **SelfRefreshTime ($t_{RAS}$)** | **6** | 对应手册 $t_{RAS} (42\text{ ns})$ 最小值 |
| **RowCycleDelay ($t_{RC}$)** | **8** | 必须满足 $t_{RC} \ge t_{RAS} + t_{RP}$ ($6+2=8$) |
| **WriteRecoveryTime** | **2** | **性能核心**：生成代码后需在 `FMC.c` 手动从 5 改回 **2** |
| **RPDelay ($t_{RP}$)** | **2** | 对应手册 $t_{RP} (15\text{ ns})$ |
| **RCDDelay ($t_{RCD}$)** | **3** | 对应手册 $t_{RCD} (18\text{ ns})$，设为 3 更稳健 |

> [!WARNING]
> **必须开启 D-Cache**：STM32H7 若不开启 L1 Cache，外部总线会因频繁挂起导致性能下降 10 倍以上。

---

## 🏆 4. 极致压榨：FMC 写 FIFO 与抗中断实验

为了验证系统在真实多任务环境下的稳定性，我们引入了高频中断干扰实验。

### 🚨 干扰源设置 (Stress Test)
我们通过 **TIM3 定时器** 产生一个 **100KHz** 的极高频中断，在中断服务函数（ISR）中模拟计算开销，强制占用 CPU 资源：

```c
/* 模拟真实工况下的 CPU 干扰源 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM3) {
        static volatile uint32_t dummy_cnt;
        /* 模拟一些计算开销，强制中断 CPU 的主循环写入过程 */
        for(int i=0; i<50; i++) {
            dummy_cnt++; 
        }
    }
}
```

### 📊 干扰环境下的性能对比 (64MB 写入)

| 测试场景 | 写入速率 (MB/s) | 性能状态 | 效果分析 |
| :--- | :--- | :--- | :--- |
| **禁止 Write FIFO** | **139.41 MB/s** | 性能暴跌 | CPU 必须与物理总线强同步，频繁被中断打断导致效率极低 |
| **开启 Write FIFO** | **400.97 MB/s** | **解耦爆发** | **性能飞跃 +65%**！FIFO 缓冲了数据，CPU 处理中断时总线仍在后台持续工作 |

### 🧠 深度总结：FIFO 的解耦作用
1.  **总线解耦**：Write FIFO 允许 CPU 将数据高速“倒入”缓存池后立即返回，不再需要原地等待 SDRAM 的物理存储周期。
2.  **抗干扰鲁棒性**：在高频中断干扰下，即便 CPU 暂时离开去处理 ISR，FMC 硬件仍能利用 FIFO 内的残留数据维持外部总线的满载运行。
3.  **确定性保障**：通过寄存器级强制使能（`FMC_Bank1_R->BTCR[0] &= ~FMC_BCR1_WFDIS;`），确保系统在任何负载下都能维持 **400MB/s+** 的确定性吞吐。

---

## 💻 5. 极限速度测试程序 (8 路循环展开)

```c
#define SDRAM_BANK_ADDR      (0xC0000000UL)
#define SDRAM_TOTAL_WORDS    (64 * 1024 * 1024 / 4) // 64MB / 4字节

void SDRAM_Speed_Test(void) {
    volatile uint32_t *pBuf = (uint32_t *)SDRAM_BANK_ADDR;
    uint32_t i, elapsed;

    /* --- 极致写入测试 (32-bit 优化) --- */
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
* **真实工况 (100KHz 中断干扰 + FIFO)**：**400.97 MB/s**
* **恶劣工况 (100KHz 中断干扰 - 无 FIFO)**：**139.41 MB/s**

### 💡 核心启示
在高性能嵌入式场景中，**Write FIFO 的本质是用硬件空间换取软件容错**。通过 32 位并联方案，STM32H7 能够彻底消除 **RGB888 高分屏驱动** 或 **4K 级数据实时采集** 时的总线拥塞。

/********************************** END **********************************/
