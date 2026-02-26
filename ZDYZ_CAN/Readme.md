# 🚀 STM32H750 FDCAN 通信实验项目 (Classic CAN 模式)

本项目基于 **STM32H750** 微控制器，展示了如何配置和使用 FDCAN 外设进行经典 CAN（Classic CAN）通信。通过硬件过滤器、中断接收和灵活的发送函数，实现了一个高效、可靠的嵌入式通信框架。

---

## 📅 项目概览

该实验实现了以下核心功能：
* **多格式发送**：支持固定 ID 发送与动态 ID/长度发送。
* **双重硬件过滤**：同时配置了标准帧（11位）与扩展帧（29位）过滤器。

---

## 📖 核心知识点：什么是 CAN 通信？

在深入代码之前，我们需要了解 CAN（Controller Area Network）协议的两个核心概念：

### 1. 帧格式 (Frame Formats)
本项目主要涵盖了两种帧格式：

| 格式 | ID 长度 | ID 范围 | 应用场景 |
| :--- | :--- | :--- | :--- |
| **标准帧 (Standard)** | 11 位 | 0x000 ~ 0x7FF | 工业控制、简单命令。 |
| **扩展帧 (Extended)** | 29 位 | 0x000 ~ 0x1FFFFFFF | 复杂网络、汽车 J1939 协议。 |



**原理**：硬件通过 **IDE 位** 来区分这两种格式。本项目通过配置两个不同的过滤器赛道，确保两类数据都能被正确捕获。

### 2. 帧类型 (Frame Types)
* **数据帧 (Data Frame)**：携带实际荷载信息的“搬运工”。（本项目重点）
* **远程帧 (Remote Frame)**：用于向其他节点“请求”数据，不带数据段。

---

## 🛠️ 技术实现细节

### 1. 硬件门卫：过滤器配置
为了减轻 CPU 的负担，本项目使用了硬件过滤器。只有匹配特定 ID 的报文才会触发中断。



* **标准位过滤器**：精准匹配 `0x123`。
* **扩展位过滤器**：精准匹配 `0x1234567`。
* **全局策略**：默认丢弃（REJECT）所有未在白名单内的报文，确保系统不受干扰。

### 2. 灵活的发送接口
项目中提供了两个维度的发送函数：
* `FDCAN1_Send_Msg`：用于发送固定 ID 的 8 字节心跳或状态数据。
* `FDCAN1_Send_Any_Msg`：通用接口，支持动态指定 ID 和 数据长度 (DLC)。

### 3. 中断接收逻辑
接收采用 `HAL_FDCAN_RxFifo0Callback` 回调函数。当新报文到达时：
1.  硬件自动将数据存入 Rx FIFO0。
2.  触发中断，由 `HAL_FDCAN_GetRxMessage` 提取数据。
3.  通过串口（USART1）实时打印报文 ID、长度及十六进制内容。

---

## ⚠️ 开发注意事项 (Tips for Readers)

1.  **数据长度解析**：在 FDCAN 中，`DataLength` 是一个 32 位宏（如 `0x00080000`）。在解析实际字节数时，需要正确处理位移或直接读取有效位。
2.  **中断性能**：本实验在中断中使用了 `printf`。在正式工业项目中，建议将打印逻辑移至 `while(1)` 循环中，通过标志位触发，以避免阻塞总线造成丢帧。
3.  **H7 时钟树**：FDCAN 对波特率精度要求极高。本项目配置 `NominalPrescaler = 5`，基于 HSE 时钟源，确保了 **500Kbps** 的稳定通信。



---

## 📂 关键代码片段

### 动态发送实现逻辑
```c
// 支持 1~8 字节长度的动态匹配转换
switch(len) {
    case 1: TxHeader.DataLength = FDCAN_DLC_BYTES_1; break;
    case 2: TxHeader.DataLength = FDCAN_DLC_BYTES_2; break;
    case 3: TxHeader.DataLength = FDCAN_DLC_BYTES_3; break;
    case 4: TxHeader.DataLength = FDCAN_DLC_BYTES_4; break;
    case 5: TxHeader.DataLength = FDCAN_DLC_BYTES_5; break;
    case 6: TxHeader.DataLength = FDCAN_DLC_BYTES_6; break;
    case 7: TxHeader.DataLength = FDCAN_DLC_BYTES_7; break;
    case 8: TxHeader.DataLength = FDCAN_DLC_BYTES_8; break;
}

// 将消息添加至发送 FIFO 队列
if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, tx_buf) != HAL_OK) {
    // 发送失败处理...
}
```

---

### 📖 开发者寄语
FDCAN 虽然向下兼容经典 CAN，但在寄存器配置和长度表示（DLC）上与旧款 bxCAN 差异巨大。本项目通过“白名单”机制，展示了 H750 处理高频通信时的高效性。
