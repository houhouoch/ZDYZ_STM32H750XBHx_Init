# ? STM32H750 FDCAN 工业级通信框架总结

? **项目概述** 本项目是基于 **STM32H750 + FreeRTOS** 实现的高可靠性电源仪器通信架构。通过对公司内部自定义 CAN 协议（29位扩展 ID 位域解析）的深度封装，解决了嵌入式通信中常见的“数据丢失”、“资源竞争”和“字节序错误”等核心痛点。

---

## ?? 核心架构设计：三层防御体系

为了保证 GUI（LVGL）任务不卡顿且通信不丢包，采用了以下分层设计：



* **驱动层 (BSP Layer)**：负责硬件同步。利用 `Mutex` 保护寄存器，利用 `Semaphore` 匹配物理总线速度。
* **协议适配层 (Protocol Layer)**：利用 C 语言的 `union` 和 `struct` 位域技术，实现 29 位扩展 ID 的“零成本”拆解。
* **任务业务层 (App Layer)**：高优先级任务分拣报文，普通优先级任务解析具体业务逻辑。

---

## ? 深度学习：那些被忽视的细节

### 1. 为什么发送函数必须加“信号量”？
* **误区**：以为 `HAL_FDCAN_AddMessageToTxFifoQ` 返回 `HAL_OK` 数据就发出去了。
* **真相**：该函数只是把数据塞进了硬件 FIFO。在 480MHz 的 CPU 面前，1Mbps 的总线速率极慢，连续调用会瞬间冲爆缓冲区。
* **解决方案**：发送后执行 `osSemaphoreAcquire` 进入休眠，由 `TxEventFifoCallback` 中断回调释放信号量。
* **收益**：实现了“软硬同步”，既不浪费 CPU 盲等，又保证了发送顺序。

### 2. 健壮性：拔掉 CAN 线后怎么办？
当物理链路断开时，硬件会因收不到 ACK 而无限重传，导致 FIFO 堵死。
* **超时撤回**：若 20ms 等不到信号量，果断执行 `HAL_FDCAN_AbortTxRequest`。
* **硬件自愈**：若错误计数器过高，通过修改 `CCCR` 寄存器强行重置 FDCAN 状态机。

### 3. 位域解析的“魔法”
本项目通过 `union` 联合体实现了 29 位扩展 ID 的自动解析，公式如下：

$$ID = (dir \ll 28) | (comm\_type \ll 24) | (mode \ll 19) | (device\_type \ll 16) | (ch\_num \ll 8) | addr$$

> **实例解析**：`0x03090102` 展开二进制后，对应的 `comm_type` 为 3（主动上报数据），`addr` 为 2（设备地址）。

### 4. 浮点数与大端序 (Endianness)
**坑点**：STM32 是小端序（Little-Endian），而工业协议常采用大端序（Big-Endian）。
直接 `memcpy` 得到的电压值会因字节序颠倒而完全错误（如 0.00V）。

```c
// 手动倒序拼装，适配大端序协议
uint32_t temp_v = ((uint32_t)rx[0] << 24) | 
                  ((uint32_t)rx[1] << 16) | 
                  ((uint32_t)rx[2] << 8)  | 
                  rx[3];
memcpy(&voltage, &temp_v, 4);
```

---

## ? 资源管理清单

| 资源名称 | 类型 | 用途 |
| :--- | :--- | :--- |
| `can_tx_mutex_handle` | `osMutex` | **TX 麦克风**：防止多任务并发写寄存器导致数据错乱。 |
| `can_tx_semaphore_handle` | `osSemaphore` | **TX 确认函**：确认物理层发送完成，实现软硬同步。 |
| `can_rx_queue_handle` | `osMessageQueue` | **RX 货架**：中断只管投递数据，任务异步按序取货。 |

---

## ? 常用接口参考

1.  **初始化**：`CAN_Task_App_Start()` —— 一键初始化资源并拉起高优先级处理任务。
2.  **发送指令**：`Protocol_Send_Command(uint8_t addr, uint8_t cmd)` —— 屏蔽位域细节，业务逻辑直接操作设备地址。
3.  **接收解析**：在 `CAN_Msg_Process_Task` 的 `switch-case` 中按 `comm_type` 快速扩展业务功能。

---

## ?? 维护建议

* **优先级压制**：`CAN_Msg_Process_Task` 的优先级必须高于 LVGL UI 任务，确保实时数据不积压。
* **位溢出检查**：调用标准帧接口时，务必校验 ID 是否超过 `0x7FF`，防止位溢出导致解析逻辑崩溃。
* **隔离设计**：建议在 MPU 配置中将 FDCAN 的 **Message RAM** 设为 Non-cacheable，避免数据一致性问题。