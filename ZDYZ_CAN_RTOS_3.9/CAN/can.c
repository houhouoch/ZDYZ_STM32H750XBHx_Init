/**
 ****************************************************************************************************
 * @file        can.c
 * @brief       CAN底层驱动层：负责原始数据的收发、RTOS同步及硬件错误处理
 * @details     
 * 1. 封装了带互斥锁和信号量的安全发送引擎
 * 2. 提供标准/扩展帧发送接口
 * 3. 包含完善的 FDCAN 错误诊断与自动恢复逻辑
 ****************************************************************************************************
 */
 
#include "./CAN/can.h"
#include <string.h>
#include <stdio.h>

/* --------------------------------------------------------------------------------------------------
 * [资源定义] 供全工程使用的 RTOS 句柄
 * -------------------------------------------------------------------------------------------------- */
osMessageQueueId_t can_rx_queue_handle;     // 接收消息队列
osMutexId_t        can_tx_mutex_handle;      // 发送互斥锁（防止多线程竞争FIFO）
osSemaphoreId_t    can_tx_semaphore_handle;  // 发送完成信号量（确保硬件发完再退出）


/**
 * @brief 初始化 CAN 模块所需的 RTOS 资源
 * @details 此函数必须在启动任何使用 CAN 的任务之前调用
 */
void CAN_Hardware_Resources_Init(void) {
    // 1. 接收队列 (16帧深度)
    can_rx_queue_handle = osMessageQueueNew(16, sizeof(CAN_Msg_t), NULL);
    
    // 2. 发送互斥锁 (递归锁)
    const osMutexAttr_t mutex_attr = { "CAN_Tx_Mutex", osMutexRecursive, NULL, 0 };
    can_tx_mutex_handle = osMutexNew(&mutex_attr);

    // 3. 发送完成信号量 (初始为 0)
    can_tx_semaphore_handle = osSemaphoreNew(1, 0, NULL);
    
// --- 4. 配置硬件过滤器与全局过滤策略 ---
    // 确保这些函数在 FDCAN 启动之前执行
    CAN_Set_Std_Filter_All();
    CANFD_Set_RX0_Filiter();
    
    // 拒绝所有未匹配的帧（标准/扩展/远程），保证系统只接收定义的指令
    if(HAL_FDCAN_ConfigGlobalFilter(&hfdcan1, FDCAN_REJECT, FDCAN_REJECT, FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE) != HAL_OK) {
        Error_Handler();
    }

    // --- 5. 开启中断通知 (Notification) ---
    // 注意：必须在 HAL_FDCAN_Start 之前或之后立即开启
    HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_TX_FIFO_EMPTY, 0);
    HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);
    
    // 开启错误监控中断，防止总线挂死
    HAL_FDCAN_ActivateNotification(&hfdcan1, 
          FDCAN_IT_ERROR_PASSIVE | FDCAN_IT_ERROR_WARNING | 
          FDCAN_IT_BUS_OFF | FDCAN_IT_ARB_PROTOCOL_ERROR | 
          FDCAN_IT_DATA_PROTOCOL_ERROR, 0);

    // --- 6. 正式启动 FDCAN 硬件外设 ---
    if(HAL_FDCAN_Start(&hfdcan1) != HAL_OK) {
        Error_Handler();
    }
}
/* --------------------------------------------------------------------------------------------------
 * [私有函数声明]
 * -------------------------------------------------------------------------------------------------- */
static void CAN_Tx_Queue_Send(FDCAN_TxHeaderTypeDef *header, uint8_t data[8]);
static void __CAN_Debug_Flag(void);

/* --------------------------------------------------------------------------------------------------
 * [核心API：发送接口]
 * -------------------------------------------------------------------------------------------------- */

/**
 * @brief 标准帧发送接口 (ID: 11位)
 */
void CANFD_Send_Standard(uint32_t id, uint8_t pdata[8])
{
    if (id > 0x7FF) {
        printf("[CAN] Error: Standard ID 0x%X range overflow!\r\n", (unsigned int)id);
        return; 
    }   

    FDCAN_TxHeaderTypeDef TxHeader;
    TxHeader.Identifier          = id;
    TxHeader.IdType              = FDCAN_STANDARD_ID;
    TxHeader.TxFrameType         = FDCAN_DATA_FRAME;
    TxHeader.DataLength          = FDCAN_DLC_BYTES_8;
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader.BitRateSwitch       = FDCAN_BRS_OFF;
    TxHeader.FDFormat            = FDCAN_CLASSIC_CAN;
    TxHeader.TxEventFifoControl  = FDCAN_NO_TX_EVENTS;
    TxHeader.MessageMarker       = 0;
//    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader1, pdata) != HAL_OK)
//    {
//        // 如果发送失败，你可以在这里打个断点
//    }
    CAN_Tx_Queue_Send(&TxHeader, pdata);
}

/**
 * @brief 扩展帧发送接口 (ID: 29位)
 */
void CANFD_Send_Extended(uint32_t id, uint8_t pdata[8])
{
    FDCAN_TxHeaderTypeDef TxHeader;
    TxHeader.Identifier          = id;
    TxHeader.IdType              = FDCAN_EXTENDED_ID;
    TxHeader.TxFrameType         = FDCAN_DATA_FRAME;
    TxHeader.DataLength          = FDCAN_DLC_BYTES_8;
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader.BitRateSwitch       = FDCAN_BRS_OFF;
    TxHeader.FDFormat            = FDCAN_CLASSIC_CAN;
    TxHeader.TxEventFifoControl  = FDCAN_NO_TX_EVENTS;
    TxHeader.MessageMarker       = 0;
//    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader1, pdata) != HAL_OK)
//    {
//        // 如果发送失败，你可以在这里打个断点
//    }
    CAN_Tx_Queue_Send(&TxHeader, pdata);
}

/* --------------------------------------------------------------------------------------------------
 * [内部核心：发送引擎]
 * -------------------------------------------------------------------------------------------------- */
/**
 * @brief 底层发送引擎：处理互斥、FIFO空间检查、硬件投递及超时撤回
 */
static void CAN_Tx_Queue_Send(FDCAN_TxHeaderTypeDef *header, uint8_t data[8])
{
    // 1. 获取互斥锁，防止多个任务同时操作 FDCAN
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;

    // 2. 检查 FIFO 剩余空间，若无空间则尝试暴力重置（防止硬件卡死）
    uint32_t waitCount = 0;
    while(HAL_FDCAN_GetTxFifoFreeLevel(&hfdcan1) < 1) {
        if(waitCount++ > 20000) {
            hfdcan1.Instance->CCCR &= ~FDCAN_CCCR_INIT; 
            break;
        }
    }

    // 3. 投递报文至硬件 FIFO
    if(HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, header, data) == HAL_OK) 
    {
        // 4. 等待信号量：直到触发 TxFifoEmptyCallback 中断，证明数据已离开发送器
        if (osSemaphoreAcquire(can_tx_semaphore_handle, 20) != osOK) 
        {
            printf("[CAN] TX Timeout! Attempting Abort...\r\n");    
            
            // 撤回发送：获取最新请求索引并终止
            uint32_t idx = HAL_FDCAN_GetLatestTxFifoQRequestBuffer(&hfdcan1);
            HAL_FDCAN_AbortTxRequest(&hfdcan1, (1 << idx));
        }
    }

    // 5. 释放互斥锁
    osMutexRelease(can_tx_mutex_handle);
}
/* --------------------------------------------------------------------------------------------------
 * [硬件配置：过滤器]
 * -------------------------------------------------------------------------------------------------- */

void CANFD_Set_RX0_Filiter(void)
{
    FDCAN_FilterTypeDef sFilter;
    sFilter.IdType       = FDCAN_EXTENDED_ID;
    sFilter.FilterType   = FDCAN_FILTER_RANGE;
    sFilter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    sFilter.FilterIndex  = 0;
    sFilter.FilterID1    = 0x00000000;
    sFilter.FilterID2    = 0x1FFFFFFF; // 全放行
    HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilter);
}

void CAN_Set_Std_Filter_All(void)
{
    FDCAN_FilterTypeDef sFilter;   
    sFilter.IdType       = FDCAN_STANDARD_ID; 
    sFilter.FilterIndex  = 1;     
    sFilter.FilterType   = FDCAN_FILTER_RANGE;    
    sFilter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;  
    sFilter.FilterID1    = 0x000; 
    sFilter.FilterID2    = 0x7FF; // 全放行
    HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilter);
}

/* --------------------------------------------------------------------------------------------------
 * [中断回调区域]
 * -------------------------------------------------------------------------------------------------- */

/**
 * @brief 发送完成中断：解除 CAN_Tx_Queue_Send 的阻塞状态
 */
void HAL_FDCAN_TxFifoEmptyCallback(FDCAN_HandleTypeDef *hfdcan)
{
    if(can_tx_semaphore_handle != NULL) {
        osSemaphoreRelease(can_tx_semaphore_handle);
    }
}

/**
 * @brief 接收中断：将原始数据打包丢入 RTOS 队列，不在此处解析业务逻辑
 */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
    if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET)
    {
        FDCAN_RxHeaderTypeDef rx_header;
        uint8_t rx_buf[8];
        CAN_Msg_t msg_to_queue;

        if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &rx_header, rx_buf) == HAL_OK)
        {
            msg_to_queue.Identifier = rx_header.Identifier;
            msg_to_queue.IdType     = rx_header.IdType;
            msg_to_queue.Len        = (uint8_t)rx_header.DataLength;
            memcpy(msg_to_queue.Data, rx_buf, 8);

            if (can_rx_queue_handle != NULL) {
                osMessageQueuePut(can_rx_queue_handle, &msg_to_queue, 0, 0);
            }
        }
    }
}

/**
 * @brief 错误中断回调：包含硬件故障诊断与自动重连逻辑
 */
void HAL_FDCAN_ErrorCallback(FDCAN_HandleTypeDef *hfdcan)
{
    //led1翻转提示
        LED1_TOGGLE();
    uint32_t error_code = HAL_FDCAN_GetError(hfdcan);

    // 1. 诊断打印（保留，这是你的眼睛）
    HAL_FDCAN_PrintError(error_code);
    __CAN_Debug_Flag();

    // 2. 升级版重启逻辑：不仅是 BUS_OFF，严重的协议错误也触发重启
    if ((error_code & HAL_FDCAN_ERROR_PROTOCOL_ARBT) || (__HAL_FDCAN_GET_FLAG(hfdcan, FDCAN_FLAG_BUS_OFF))) 
    {
        printf("\r\n[System] 触发强制硬件恢复 (Reason: Protocol Error or Bus-Off)...\r\n");
        
        HAL_FDCAN_Stop(hfdcan);
        
        // 暴力重置：模仿前辈，直接操作寄存器退出初始化模式
        hfdcan->Instance->CCCR &= ~FDCAN_CCCR_INIT; 
        
        HAL_FDCAN_Start(hfdcan);
        
        // 重新开启所有通知
        HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE | FDCAN_IT_ERROR_WARNING | FDCAN_IT_ERROR_PASSIVE | FDCAN_IT_BUS_OFF, 0);
    }
}
/* --------------------------------------------------------------------------------------------------
 * [诊断工具：错误字典]
 * -------------------------------------------------------------------------------------------------- */
#if 1
// 错误代码与描述的映射结构体
typedef struct {
    uint32_t error_code;  // 错误代码
    const char *desc;     // 错误描述
} FDCAN_Error;

// 错误映射表（按位定义，支持多错误同时打印）
FDCAN_Error fdcan_errors[] = {
    {HAL_FDCAN_ERROR_TIMEOUT,         "Timeout error"},
    {HAL_FDCAN_ERROR_NOT_INITIALIZED, "Peripheral not initialized"},
    {HAL_FDCAN_ERROR_NOT_READY,       "Peripheral not ready"},
    {HAL_FDCAN_ERROR_NOT_STARTED,     "Peripheral not started"},
    {HAL_FDCAN_ERROR_NOT_SUPPORTED,   "Mode not supported"},
    {HAL_FDCAN_ERROR_PARAM,           "Parameter error"},
    {HAL_FDCAN_ERROR_PENDING,         "Pending operation"},
    {HAL_FDCAN_ERROR_RAM_ACCESS,      "Message RAM Access Failure"},
    {HAL_FDCAN_ERROR_FIFO_EMPTY,      "Get element from empty FIFO"},
    {HAL_FDCAN_ERROR_FIFO_FULL,       "Put element in full FIFO"},
    {HAL_FDCAN_ERROR_LOG_OVERFLOW,    "Overflow of CAN Error Logging Counter"},
    {HAL_FDCAN_ERROR_RAM_WDG,         "Message RAM Watchdog event occurred"},
    {HAL_FDCAN_ERROR_PROTOCOL_ARBT,   "Protocol Error in Arbitration Phase (Nominal Bit Time is used)"},
    {HAL_FDCAN_ERROR_PROTOCOL_DATA,   "Protocol Error in Data Phase (Data Bit Time is used)"},
    {HAL_FDCAN_ERROR_RESERVED_AREA,   "Access to Reserved Address"},
    {HAL_FDCAN_ERROR_TT_GLOBAL_TIME,  "Global Time Error : Synchronization deviation exceeded limit"},
    {HAL_FDCAN_ERROR_TT_TX_UNDERFLOW, "Tx Count Underflow : Less Tx trigger than expected in one matrix cycle"},
    {HAL_FDCAN_ERROR_TT_TX_OVERFLOW,  "Tx Count Overflow : More Tx trigger than expected in one matrix cycle"},
    {HAL_FDCAN_ERROR_TT_SCHEDULE1,    "Scheduling error 1"},
    {HAL_FDCAN_ERROR_TT_SCHEDULE2,    "Scheduling error 2"},
    {HAL_FDCAN_ERROR_TT_NO_INIT_REF,  "No system startup due to missing reference message"},
    {HAL_FDCAN_ERROR_TT_NO_REF,       "Missing reference message"},
    {HAL_FDCAN_ERROR_TT_APPL_WDG,     "Application watchdog not served in time"},
    {HAL_FDCAN_ERROR_TT_CONFIG,       "Error found in trigger list"},
    {0, NULL}  // 结束标志
};

/**
 * @brief 打印FDCAN错误信息
 * @param error 错误代码（可由多个错误位组合）
 */
void HAL_FDCAN_PrintError(uint32_t error) {
    if(error == HAL_FDCAN_ERROR_NONE) return;
    printf("FDCAN Code: 0x%08X (", (unsigned int)error);
    for(const FDCAN_Error *err = fdcan_errors; err->desc != NULL; err++) {
        if(error & err->error_code) printf("%s ", err->desc);
    }
    printf(")\n");
}



/**
 * @brief 硬件标志位深度诊断
 */
static void __CAN_Debug_Flag(void) {
    // 发送相关标志
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_TX_COMPLETE))
    //        printf( "TX_COMPLETE (Transmission Completed)\r\n");
    if(__HAL_FDCAN_GET_FLAG(&hfdcan1, FDCAN_FLAG_TX_ABORT_COMPLETE))
    { printf( "TX_ABORT_COMPLETE (Transmission Cancellation Finished)\r\n"); }
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_TX_FIFO_EMPTY))
    //        printf( "TX_FIFO_EMPTY (Tx FIFO Empty)\r\n");
    //    // 接收相关标志
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_RX_HIGH_PRIORITY_MSG)
    //        printf( "RX_HIGH_PRIORITY_MSG (High priority message received)\r\n");
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_RX_BUFFER_NEW_MESSAGE)
    //        printf( "RX_BUFFER_NEW_MESSAGE (New message in Rx Buffer)\r\n");
    // 发送事件FIFO相关标志
    if(__HAL_FDCAN_GET_FLAG(&hfdcan1, FDCAN_FLAG_TX_EVT_FIFO_ELT_LOST))
    { printf( "TX_EVT_FIFO_ELT_LOST (Tx Event FIFO element lost)\r\n"); }
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_TX_EVT_FIFO_FULL))
    //        printf( "TX_EVT_FIFO_FULL (Tx Event FIFO full)\r\n");
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_TX_EVT_FIFO_WATERMARK))
    //        printf( "TX_EVT_FIFO_WATERMARK (Tx Event FIFO reached watermark)\r\n");
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_TX_EVT_FIFO_NEW_DATA))
    //        printf( "TX_EVT_FIFO_NEW_DATA (New data in Tx Event FIFO)\r\n");
    //    // 接收FIFO0相关标志
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_RX_FIFO0_MESSAGE_LOST))
    //        printf( "RX_FIFO0_MESSAGE_LOST (Rx FIFO0 message lost)\r\n");
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_RX_FIFO0_FULL))
    //        printf( "RX_FIFO0_FULL (Rx FIFO0 full)\r\n");
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_RX_FIFO0_WATERMARK))
    //        printf( "RX_FIFO0_WATERMARK (Rx FIFO0 reached watermark)\r\n");
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_RX_FIFO0_NEW_MESSAGE))
    //        printf( "RX_FIFO0_NEW_MESSAGE (New message in Rx FIFO0)\r\n");
    //    // 接收FIFO1相关标志
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_RX_FIFO1_MESSAGE_LOST))
    //        printf( "RX_FIFO1_MESSAGE_LOST (Rx FIFO1 message lost)\r\n");
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_RX_FIFO1_FULL))
    //        printf( "RX_FIFO1_FULL (Rx FIFO1 full)\r\n");
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_RX_FIFO1_WATERMARK))
    //        printf( "RX_FIFO1_WATERMARK (Rx FIFO1 reached watermark)\r\n");
    //    if (__HAL_FDCAN_GET_FLAG(&hfdcan1,FDCAN_FLAG_RX_FIFO1_NEW_MESSAGE))
    //        printf( "RX_FIFO1_NEW_MESSAGE (New message in Rx FIFO1)\r\n");
    // 错误及异常相关标志
    if(__HAL_FDCAN_GET_FLAG(&hfdcan1, FDCAN_FLAG_RAM_ACCESS_FAILURE))
    { printf( "RAM_ACCESS_FAILURE (Message RAM access failure)\r\n"); }
    if(__HAL_FDCAN_GET_FLAG(&hfdcan1, FDCAN_FLAG_ERROR_LOGGING_OVERFLOW))
    { printf( "ERROR_LOGGING_OVERFLOW (Error logging counter overflow)\r\n"); }
    if(__HAL_FDCAN_GET_FLAG(&hfdcan1, FDCAN_FLAG_ERROR_PASSIVE))
    { printf( "ERROR_PASSIVE (Error-Passive status changed)\r\n"); }
    if(__HAL_FDCAN_GET_FLAG(&hfdcan1, FDCAN_FLAG_ERROR_WARNING))
    { printf( "ERROR_WARNING (Error-Warning status changed)\r\n"); }
    if(__HAL_FDCAN_GET_FLAG(&hfdcan1, FDCAN_FLAG_BUS_OFF))
    { printf( "BUS_OFF (Bus-Off status changed)\r\n"); }
    if(__HAL_FDCAN_GET_FLAG(&hfdcan1, FDCAN_FLAG_RAM_WATCHDOG))
    { printf( "RAM_WATCHDOG (Message RAM watchdog event)\r\n"); }
    if(__HAL_FDCAN_GET_FLAG(&hfdcan1, FDCAN_FLAG_ARB_PROTOCOL_ERROR))
    { printf( "ARB_PROTOCOL_ERROR (Arbitration phase protocol error)\r\n"); }
    if(__HAL_FDCAN_GET_FLAG(&hfdcan1, FDCAN_FLAG_DATA_PROTOCOL_ERROR))
    { printf( "DATA_PROTOCOL_ERROR (Data phase protocol error)\r\n"); }
    if(__HAL_FDCAN_GET_FLAG(&hfdcan1, FDCAN_FLAG_RESERVED_ADDRESS_ACCESS))
    { printf( "RESERVED_ADDRESS_ACCESS (Access to reserved address)\r\n"); }
    if(__HAL_FDCAN_GET_FLAG(&hfdcan1, FDCAN_FLAG_TIMESTAMP_WRAPAROUND))
    { printf( "TIMESTAMP_WRAPAROUND (Timestamp counter wrap-around)\r\n"); }
    if(__HAL_FDCAN_GET_FLAG(&hfdcan1, FDCAN_FLAG_TIMEOUT_OCCURRED))
    { printf( "TIMEOUT_OCCURRED (Timeout reached)\r\n"); }
}
#endif

