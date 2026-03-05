# STM32H750 高性能嵌入式系统开发记录

本项目详细记录了基于 **STM32H750VBT6** 平台的完整演进过程，涵盖了从基础 Bootloader 到复杂的 RTOS + LVGL + 工业级 CAN 通信协议的整合实现。

## 📂 工程演进明细表 (Project Roadmap)

| 工程文件夹名称 | 开发日期 | 项目功能说明 |
| :--- | :---: | :--- |
| **ZDYZ_Bootload** | 2.2 | 基础引导程序，移植自安富莱工程，实现固件安全跳转。 |
| **ZDYZ_单片SDRAM_TEST_read-155M_write-223M** | 2.2 | 单片 SDRAM 驱动测试，实测写速度达 **223M/s**。 |
| **ZDYZ_双片SDRAM_TES_read-238M_write-446M** | 2.3 | 双片 SDRAM 驱动测试，带宽翻倍，实测写速度达 **446M/s**。 |
| **ZDYZ_LTDC_RGB屏幕：多层混合显示** | 2.3 | 驱动 RGB 屏幕，实现 LTDC 多层图像硬件混合显示。 |
| **ZDYZ_LTDC_RGB_DMA2D** | 2.5 | 验证 DMA2D 硬件搬运（M2M）逻辑，减轻 CPU 图像渲染负担。 |
| **ZDYZ_LTDC_RGB_DMA2D_FreeRTOS** | 2.5 | 引入 FreeRTOS 实时操作系统，构建多任务并行协作架构。 |
| **ZDYZ_LTDC_RGB_DMA2D_FreeRTOS_LVGL** | 2.6 | 移植 LVGL 图形库，重点对比 DMA2D 加速与 LTDC 零拷贝架构的性能。 |
| **ZDYZ_LTDC_RGB_DMA2D_FreeRTOS_LVGL_BACK_LED** | 2.7 | 增加系统运行状态指示灯，实现呼吸灯特效。 |
| **ZDYZ_LTDC_RGB_DMA2D_FreeRTOS_LVGL_GT1151Q_Driver** | - | 完成电容触摸芯片 GT1151Q 底层驱动与初始化。 |
| **ZDYZ_LTDC_RGB_DMA2D_FreeRTOS_LVGL_GT1158_Driver_5点触摸** | 2.25 | 优化触摸驱动，支持高性能五点触摸交互测试。 |
| **ZDYZ_Template_CAN** | 2.27 | 配置 FDCAN 外设，实现基础的经典 CAN (Classic CAN) 通信逻辑。 |
| **ZDYZ_CAN_TEST** | 2.28 | 实现动态 ID 发送接口及异步接收中断回调机制。 |
| **ZDYZ_CAN_RTOS_MUTEX** | 2.28 | **协议深度封装**：引入 Mutex 机制，彻底解决多任务下的数据竞争与字节序错误。 |
| **ZDYZ_CAN_RTOS** | 3.5 | **核心同步逻辑**：实现 UDP5000 与 ZDYZ 开发板之间的毫秒级状态同步。 |

---

## 🚀 核心技术亮点

1. **极致内存性能**：通过优化 FMC 时序，在 H750 上压榨出 **446M/s** 的写速度，为 LVGL 的双缓冲刷新提供了充足的带宽保障。
2. **工业级通信稳健性**：针对 CAN 协议进行的深度封装，通过 **Mutex 互斥锁**和**大端序自动转换**，确保了在多任务环境下指令下发的原子性与准确性。
3. **硬件加速显示**：充分利用 STM32H7 的 **DMA2D** 硬件引擎，实现了 UI 渲染与逻辑处理的并行化，显著降低了系统负载。
