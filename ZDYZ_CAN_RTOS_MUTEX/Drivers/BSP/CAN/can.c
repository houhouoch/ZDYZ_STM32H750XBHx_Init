#include "./BSP/CAN/can.h"
#include "fdcan.h"


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
    if(error == HAL_FDCAN_ERROR_NONE) {
        printf("FDCAN: No error\n");
        return;
    }
    printf("FDCAN Errors: ");
    int has_error = 0;
    FDCAN_Error *err = fdcan_errors;
    // 遍历所有错误，打印匹配的描述
    while(err->desc != NULL) {
        if((error & err->error_code) != 0) {
            if(has_error) { printf("; "); }
            printf("%s", err->desc);
            has_error = 1;
        }
        err++;
    }
    // 处理未知错误
    if(!has_error) {
        printf("Unknown error (0x%08X)", error);
    }
    printf("\n");
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

/**
 * @brief 错误中断回调：加入强制重启逻辑
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
#endif


// 资源定义
osMessageQueueId_t can_rx_queue_handle;
osMutexId_t        can_tx_mutex_handle;
osSemaphoreId_t    can_tx_semaphore_handle;

/**
 * @brief 在这里统一创建所有 CAN 相关的 RTOS 资源
 */
void CAN_App_Init(void) {
    // 1. 接收队列 (16帧深度)
    can_rx_queue_handle = osMessageQueueNew(16, sizeof(CAN_Msg_t), NULL);
    
    // 2. 发送互斥锁 (递归锁) 创建互斥锁的句柄和属性
    const osMutexAttr_t mutex_attr = { "CAN_Tx_Mutex", osMutexRecursive, NULL, 0 };
    can_tx_mutex_handle = osMutexNew(&mutex_attr);//创建锁

    // 3. 发送完成信号量 (初始为0)
    can_tx_semaphore_handle = osSemaphoreNew(1, 0, NULL);
}
 
/**
 * @brief 核心：发送函数 
 */
static void CAN_Tx_Queue_Send(FDCAN_TxHeaderTypeDef *header, uint8_t data[8])
{
    // 1. 互斥锁 拿锁
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;

    // 2. 检查 FIFO 空间，防卡死暴力重置
    uint32_t waitCount = 0;
    while(HAL_FDCAN_GetTxFifoFreeLevel(&hfdcan1) < 1) {
        if(waitCount++ > 20000) {
            hfdcan1.Instance->CCCR &= ~FDCAN_CCCR_INIT; 
            break;
        }
    }

    // 3. 投递报文
    if(HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, header, data) == HAL_OK) 
    {
        // 4. 等待信号量：直到硬件真正发完触发中断（限时 20ms）
        // 这保证了发送函数退出时，数据已经离开发送缓冲区
        // 等待信号量
        osStatus_t status = osSemaphoreAcquire(can_tx_semaphore_handle, 20);     
        if (status != osOK) {
        // 1. 打印诊断信息，告诉你线可能断了
            printf("[CAN] TX error...\r\n");    
            
            // 撤回卡住的报文：获取最新索引并转换为掩码
            uint32_t idx = HAL_FDCAN_GetLatestTxFifoQRequestBuffer(&hfdcan1);
            HAL_FDCAN_AbortTxRequest(&hfdcan1, (1 << idx));
        }
        
    }

    // 5. 释放锁
    osMutexRelease(can_tx_mutex_handle);
}



/* --- 中断回调区域 --- */
/**
 * @brief 硬件发送完成回调：给信号量发“通行证”
 */
void HAL_FDCAN_TxFifoEmptyCallback(FDCAN_HandleTypeDef *hfdcan)
{
    if(can_tx_semaphore_handle != NULL) {
        osSemaphoreRelease(can_tx_semaphore_handle);
    }
}

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
    if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET)
    {
        FDCAN_RxHeaderTypeDef rx_header;
        uint8_t rx_buf[8];
        CAN_Msg_t msg_to_queue;

        if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &rx_header, rx_buf) == HAL_OK)
        {
            // 打包数据到结构体
            msg_to_queue.Identifier = rx_header.Identifier;
            msg_to_queue.IdType     = rx_header.IdType;
            msg_to_queue.Len        = (uint8_t)rx_header.DataLength;
            memcpy(msg_to_queue.Data, rx_buf, 8);

            // 存入队列：最后一个参数设为 0（中断里绝不能等待）
            if (can_rx_queue_handle != NULL) {
                osMessageQueuePut(can_rx_queue_handle, &msg_to_queue, 0, 0);
            }
        }
    }
}

/* --- 标准/扩展帧区域 --- */
/**
 * @brief 标准帧发送接口 
 */
void CANFD_Send_Standard(uint32_t id, uint8_t pdata[8])
{
    
    // 防呆检查：如果 ID 超过了标准帧的 11 位限制，直接拦截并报错
    if (id > 0x7FF) {
        printf("[CAN] Error: Standard ID 0x%X is out of range!\r\n", (unsigned int)id);
        return; 
    }   
    FDCAN_TxHeaderTypeDef TxHeader1;
    TxHeader1.Identifier = id;                      // CAN ID
    TxHeader1.IdType = FDCAN_STANDARD_ID;           // 标准ID
    TxHeader1.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader1.DataLength = FDCAN_DLC_BYTES_8;       // 发送长度：8byte
    TxHeader1.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader1.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader1.FDFormat = FDCAN_CLASSIC_CAN;         // CANFD
    TxHeader1.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader1.MessageMarker = 0;
//    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader1, pdata) != HAL_OK)
//    {
//        // 如果发送失败，你可以在这里打个断点
//    }
    CAN_Tx_Queue_Send(&TxHeader1,pdata);
}

/*
 * @brief       void CANFD_Send_Extended(uint32_t id ,uint8_t* pdata)
 * @details     CAN发送Ext数据包(最大8字节)
                ID范围:0x000~0x1FFFFFFF(536870911)
 */
void CANFD_Send_Extended(uint32_t id, uint8_t pdata[8])
{
    FDCAN_TxHeaderTypeDef TxHeader1;
    TxHeader1.Identifier = id;                      // CAN ID
    TxHeader1.IdType = FDCAN_EXTENDED_ID;           // 拓展ID
    TxHeader1.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader1.DataLength = FDCAN_DLC_BYTES_8;       // 发送长度：8byte
    TxHeader1.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader1.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader1.FDFormat = FDCAN_CLASSIC_CAN;         // CANFD
    TxHeader1.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader1.MessageMarker = 0;
//    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader1, pdata) != HAL_OK)
//    {
//        // 如果发送失败，你可以在这里打个断点
//    }
    CAN_Tx_Queue_Send(&TxHeader1,pdata);
}

void CANFD_Send_ExtRemote(uint32_t id)
{
    uint8_t can1_txbuf[8] = {0};
    FDCAN_TxHeaderTypeDef TxHeader1;
    TxHeader1.Identifier = id;                      // CAN ID
    TxHeader1.IdType = FDCAN_EXTENDED_ID;           // 拓展ID
    TxHeader1.TxFrameType = FDCAN_REMOTE_FRAME;
    TxHeader1.DataLength = FDCAN_DLC_BYTES_8;       // 发送长度：8byte
    TxHeader1.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader1.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader1.FDFormat = FDCAN_CLASSIC_CAN;         // CANFD
    TxHeader1.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader1.MessageMarker = 0;
    
    CAN_Tx_Queue_Send(&TxHeader1,can1_txbuf);
}

/**
 * @brief 配置扩展帧过滤器 (全放行模式)
 */
void CANFD_Set_RX0_Filiter(void)
{
    FDCAN_FilterTypeDef sFilter;
    sFilter.IdType = FDCAN_EXTENDED_ID;
    sFilter.FilterType = FDCAN_FILTER_RANGE;
    sFilter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    sFilter.FilterIndex = 0;
    sFilter.FilterID1 = 0x0000;
    sFilter.FilterID2 = 0xFFFFFFFF;
    if(HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilter) != HAL_OK) {
        Error_Handler();
    }
}

/**
 * @brief 配置标准帧过滤器 (全放行模式)
 */
void CAN_Set_Std_Filter_All(void)
{
    FDCAN_FilterTypeDef sFilter;   
    // 1. 设置为标准 ID 类型
    sFilter.IdType = FDCAN_STANDARD_ID;    
    // 2. 使用不同的索引号 (扩展帧用了 0，标准帧建议用 1)
    sFilter.FilterIndex = 1;     
    // 3. 过滤模式：范围过滤
    sFilter.FilterType = FDCAN_FILTER_RANGE;    
    // 4. 匹配后存入 FIFO0
    sFilter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;  
    // 5. 设置标准帧的全范围：$0x000$ 到 $0x7FF$
    sFilter.FilterID1 = 0x000; 
    sFilter.FilterID2 = 0x7FF;     
    if(HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilter) != HAL_OK) {
        Error_Handler();
    }
}




