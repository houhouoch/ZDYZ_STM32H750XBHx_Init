# STM32H7 FMC 驱动 W9825G6KH-6 SDRAM 移植实战与深度解析

本仓库记录了在 STM32H7 系列高性能 MCU 上移植 Winbond **W9825G6KH-6** SDRAM（32MB）的全过程。文档涵盖了实战避坑指南、核心时序计算逻辑以及性能优化的深层原理。

---

## 1. 硬件规格与核心参数
* [cite_start]**型号**：W9825G6KH-6 [cite: 1]
* [cite_start]**容量**：256Mbit (32MB)，组织结构为 4M words × 4 banks × 16 bits [cite: 1]
* [cite_start]**速度等级**：-6 档位，最高支持 166MHz (CL=3) 或 133MHz (CL=2) [cite: 1]
* [cite_start]**刷新要求**：8K Refresh Cycles / 64ms [cite: 1]

---

## 2. 深度知识点：理解 SDRAM 工作原理

### ① 存储结构：Bank、行(Row)与列(Column)
SDRAM 类似于一个三维表格。寻址一个数据需要三步：
1. **选 Bank**：通过 BA0-BA1 选择 4 个 Bank 中的一个。
2. [cite_start]**激活行**：发送行地址（A0-A12）并触发 `ACTIVE` 命令 [cite: 1]。
3. [cite_start]**读写列**：发送列地址（A0-A8）并触发 `READ/WRITE` 命令 [cite: 1]。
> **移植心得**：由于地址线是复用的，FMC 配置中的 `ColumnBitsNumber` 和 `RowBitsNumber` 必须与手册严格对应，否则会导致寻址空间错位。

### ② 关键时序参数的物理意义
* [cite_start]**$t_{RCD}$ (RAS to CAS Delay)**：行激活到列读写命令之间的延迟。这是给电容充电和感测放大器稳定的时间 [cite: 1]。
* [cite_start]**$t_{RP}$ (Row Precharge Delay)**：关闭当前行并准备激活下一行所需的预充电时间 [cite: 1]。
* [cite_start]**CAS Latency (CL)**：列地址选通脉冲潜伏期。即从发出读命令到总线上出现第一个有效数据所需的时钟周期数 [cite: 1]。
> [cite_start]**实战技巧**：在 120MHz 高频下，-6 等级的 $t_{RCD}$ 要求 18ns [cite: 1]，必须配置为 3 个周期。

---

## 3. 移植避坑指南与细节整理

### ① 信号完整性：GPIO 上拉与速度设置
* **细节**：所有 FMC 引脚在 CubeMX 中必须配置为 **Pull-up (上拉)** 且速度设为 **Very High**。
* **原理**：FMC 总线频率高达 100MHz+，信号线上的寄生电容会导致边沿畸变。上拉电阻能协助电平快速回升，减少过冲与振铃效应。

### ② 全局句柄统一性
* **坑位**：移植正点原子等外部代码时，往往会定义 `g_sdram_handle`。
* **对策**：必须统一使用 CubeMX 生成的 **`hsdram1`**。
* **原因**：HAL 库的底层回调与中断处理严格绑定在 `hsdram1` 句柄上。

### ③ FMC 逻辑约束与 WriteRecoveryTime
* **约束公式**：`WriteRecoveryTime >= SelfRefreshTime - RCDDelay`。
* **现象**：CubeMX 常会限制此值最小为 5，导致性能无法压榨。
* [cite_start]**解决**：在确保满足芯片 $t_{WR}$（2周期）[cite: 1] 的前提下，可以根据计算出的物理值在代码中手动强制微调为 2，但需确保不违反控制器的状态机死锁逻辑。

### ④ 存储回环问题
* **现象**：测试 64MB 时发现数据覆盖。
* **原因**：本单片 SDRAM 物理上限为 32MB（`0xC2000000`）。
* **对策**：测试循环必须限定在 32MB 以内。

---

## 4. 性能压榨：D-Cache 的决定性作用
在 STM32H7 这种带 Cache 的架构中：
* **不开启 D-Cache**：CPU 读写一次 SDRAM 都要产生总线等待，带宽可能不足理论值的 10%。
* **开启 D-Cache**：利用缓存的 Read-allocate 和 Write-back 机制，CPU 可以批量处理内存访问，大幅提升连续读写带宽。
> **注意**：若 SDRAM 用于 DMA 传输（如 LCD 显示），需配置 MPU 属性为 `Write-through` 或在传输前手动清理 Cache，防止 CPU 与 DMA 数据不一致。

---

## 5. 核心初始化序列代码 (参考)

```c
static void sdram_initialization_sequence(void) {
    FMC_SDRAM_CommandTypeDef command;
    // 1. 开启时钟
    command.CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;
    HAL_SDRAM_SendCommand(&hsdram1, &command, 0xFFFF);
    HAL_Delay(1);
    
    [cite_start]// 2. 全预充电 [cite: 1]
    command.CommandMode = FMC_SDRAM_CMD_PALL;
    HAL_SDRAM_SendCommand(&hsdram1, &command, 0xFFFF);
    
    [cite_start]// 3. 自动刷新 (至少8次) [cite: 1]
    command.CommandMode = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
    command.AutoRefreshNumber = 8;
    HAL_SDRAM_SendCommand(&hsdram1, &command, 0xFFFF);
    
    [cite_start]// 4. 加载模式寄存器：配置为 CL3 [cite: 1]
    command.CommandMode = FMC_SDRAM_CMD_LOAD_MODE;
    command.ModeRegisterDefinition = SDRAM_MODEREG_BURST_LENGTH_1 |
                                     SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL |
                                     SDRAM_MODEREG_CAS_LATENCY_3 |
                                     SDRAM_MODEREG_OPERATING_MODE_STANDARD |
                                     SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;
    HAL_SDRAM_SendCommand(&hsdram1, &command, 0xFFFF);
    
    // 5. 设置刷新频率 (120MHz下)
    HAL_SDRAM_ProgramRefreshRate(&hsdram1, 918);
}
