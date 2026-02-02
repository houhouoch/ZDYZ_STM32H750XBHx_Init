# 🚀 STM32H7 FMC 驱动 W9825G6KH-6 SDRAM 移植实战与深度解析

本仓库记录了在 **STM32H7** 系列高性能 MCU 上移植 Winbond **W9825G6KH-6** SDRAM（32MB）的全过程。这份文档不仅汇总了实战中的“填坑”经验，还深入解析了 SDRAM 的工作原理，帮助开发者从底层理解时序与性能优化。

---

## 📑 1. 硬件规格与核心参数
* **芯片型号**：Winbond W9825G6KH-6
* **物理容量**：256Mbit (32MB)
* **组织结构**：4M words × 4 banks × 16 bits
* **速度等级**：-6 档位，最高支持 166MHz (CL=3)
* **刷新要求**：8K次刷新周期 / 64ms

---

## 🧠 2. 核心知识点：深入理解 SDRAM

### 🔍 逻辑结构：Bank、行(Row)与列(Column)
SDRAM 内部并非一个连续的大数组，而是一个多层级的表格结构：
* **L-Bank**：逻辑 Bank。该芯片有 4 个 Bank。切换 Bank 需要时间，但交替访问不同 Bank 可以隐藏预充电时间，提高带宽。
* **行(Row)与列(Column)**：通过行地址（A0-A12）定位到一行，再通过列地址（A0-A8）定位到具体的存储单元。
* **💡 移植心得**：由于地址线复用，FMC 中的 `ColumnBitsNumber` 和 `RowBitsNumber` 必须与手册严格对应，否则会造成数据读写错位。

### ⏱️ 关键时序参数的物理意义
* **$t_{RCD}$ (RAS to CAS Delay)**：行激活到列读写命令之间的延迟。它是给电容充电和感测放大器稳定的“准备时间”。
* **$t_{RP}$ (Row Precharge Delay)**：预充电时间。关闭当前行并准备激活下一行所需的“重置时间”。
* **CAS Latency (CL)**：列地址选通脉冲潜伏期。即从发出读命令到数据线上出现第一个有效数据所需的“等待周期”。
* **💡 实战技巧**：在 120MHz 下，-6 等级的 $t_{RCD}$ 要求 18ns，换算后必须配置为 **3** 个周期，（但正点原子这边写的是2，不知道在后面会不会出问题）。

---

## 🛠️ 3. 移植避坑指南与细节汇总

### ⚡ ① 信号完整性：引脚必须上拉
* **操作**：在 CubeMX 中，FMC 的地址线、数据线及控制线必须全部配置为 **上拉 (Pull-up)**。
* **原理**：120MHz 是极高频率，信号线上的寄生电容会导致电平跳变迟缓。开启上拉能加快信号上升沿速度，抑制信号浮空带来的噪声。

### 🔗 ② 全局句柄统一 (`hsdram1`)
* **操作**：移植代码（如初始化序列）时，必须将所有对 `HAL_SDRAM_SendCommand` 的调用句柄统一为 CubeMX 生成的 **`hsdram1`**。
* **原理**：HAL 库的内部锁定机制和状态机是基于句柄的。混用 `g_sdram_handle` 会导致驱动状态混乱，引起卡死。

### ✅ ③ CAS Latency 匹配原则
* **配置**：FMC 控制器的 `CASLatency` 必须与发送给 SDRAM 芯片模式寄存器（Mode Register）的值**严格一致**。
* **现象**：若控制器设为 CL3 而芯片设为 CL2，FMC 会在第 3 拍采样，而芯片第 2 拍就送出了数据，这会导致读出的数据全是错位的。

### 📏 ④ 存储容量的物理上限
* **操作**：测试函数（如 `sdram_test`）的上限必须设为 **32MB** (`32*1024*1024`)。
* **原理**：单片 W9825 只有 256Mbit。如果按 64MB 测试，地址线 A13 之后会发生**回环（Wrap-around）**，新写入的数据会覆盖低端地址的数据，导致校验报错。

### 🚀 ⑤ 开启 D-Cache 的必要性
* **结论**：STM32H7 访问外部 SDRAM 若不开启 **D-Cache**，性能将慢 10 倍以上！
* **MPU 建议**：将 SDRAM 区域配置为 `Write-through` 或 `Write-back`。如果是做 LCD 显存，建议设为 `Write-through` 以保证 DMA 与 CPU 数据一致。

---

## 💻 4. 推荐初始化序列代码

```c
static void sdram_initialization_sequence(void) {
    FMC_SDRAM_CommandTypeDef command;
    
    // 1. 发送时钟使能命令 (CLK ENABLE)
    command.CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;
    command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
    command.AutoRefreshNumber = 1;
    command.ModeRegisterDefinition = 0;
    HAL_SDRAM_SendCommand(&hsdram1, &command, 0xFFFF);
    HAL_Delay(1); // 至少等待 100us
    
    // 2. 发送预充电命令 (PALL)
    command.CommandMode = FMC_SDRAM_CMD_PALL;
    HAL_SDRAM_SendCommand(&hsdram1, &command, 0xFFFF);
    
    // 3. 发送自动刷新命令 (至少 8 次)
    command.CommandMode = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
    command.AutoRefreshNumber = 8;
    HAL_SDRAM_SendCommand(&hsdram1, &command, 0xFFFF);
    
    // 4. 加载模式寄存器 (Mode Register)
    // 配置为：突发长度 1 (或 8)、串行模式、CAS 延迟 3
    command.CommandMode = FMC_SDRAM_CMD_LOAD_MODE;
    command.ModeRegisterDefinition = SDRAM_MODEREG_BURST_LENGTH_1 |
                                     SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL |
                                     SDRAM_MODEREG_CAS_LATENCY_3 |
                                     SDRAM_MODEREG_OPERATING_MODE_STANDARD |
                                     SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;
    HAL_SDRAM_SendCommand(&hsdram1, &command, 0xFFFF);
    
    // 5. 配置刷新频率计数器
    // 计算公式: (64ms / 8192) * 120MHz - 20 = 918
    HAL_SDRAM_ProgramRefreshRate(&hsdram1, 918);
}
