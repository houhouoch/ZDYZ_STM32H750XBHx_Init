# SCPI Parser 移植与使用指南

本项目基于 [Jan Breuer / scpi-parser](https://github.com/j123b567/scpi-parser.git) 库进行移植，旨在为嵌入式设备提供标准化的 SCPI 指令解析功能。

> **参考入门资料：** [SCPI 的一个小小介绍和入门](https://www.yono233.cn/posts/novel/24_7_12_SCPI)

---

## /********************************** 移植   **********************************/

移植的过程相对简单：

1. **导入文件**：把 `libscpi` 这个文件夹整个拖入到工程，然后在 MDK 中把 `src` 的 `.c` 文件进行加入，再把相应的头文件路径进行加载就完事了！
2. **定义接口**：这时候会报错，是因为下面这个结构体中没定义相关的函数，这边建议写一个 `.c` 文件把 `SCPI_Write` 写上即可。
   
```c
scpi_interface_t scpi_interface = {
    .error = SCPI_Error,
    .write = SCPI_Write,
    .control = NULL, //SCPI_Control,
    .flush = NULL,   //SCPI_Flush,
    .reset = NULL,   //SCPI_Reset,
};

3  、完成上述步骤后还会报错
 //{.pattern = "SYSTem:COMMunication:TCPIP:CONTROL?", .callback = SCPI_SystemCommTcpipControlQ,},
把这个取消掉即可
/**********************************   解决    **********************************/
4、作者这边不想使用MicroLIB，之前看帖子说这个库会引起一些莫名其妙的bug
然后我在usart,c那边照着正点原子的写法 加上了一些函数，导致这里会报错
这里报错是指#pragma import(__use_no_semihosting)
然后我把这个取消掉，虽然程序没有错误了，上电运行不起来。这时候我进入调试模式，发现需要复位3次才能跑起来。
如果你嫌麻烦 可以把MicroLIB勾上。

这边作者其实有做处理的方法，就是添加以下几个函数来“欺骗”链接器，告诉它我们不需要文件系统支持

#if 1
#if (__ARMCC_VERSION >= 6010050)          
__asm(".global __use_no_semihosting\n\t"); 
__asm(".global __ARM_use_no_argv \n\t");   
#else
#pragma import(__use_no_semihosting)
    void _sys_exit(int x) { x = x; }
    void _ttywrch(int ch) { ch = ch; }
struct __FILE
{
    int handle;
};
FILE __stdout;
FILE __stdin;
FILE __stderr;

#endif
int fputc(int ch, FILE *f)
{
    while ((USART1->ISR & 0X40) == 0);   
    USART1->TDR = (uint8_t)ch;         
    return ch;
}
#endif
/**********************************   使用    **********************************/
void SCPI_Config_Init(void) {
    /*
     * 参数含义：
     * &scpi_context: 解析器句柄
     * scpi_commands: 指令映射表
     * &scpi_interface: 包含写函数和错误函数的接口
     * scpi_units_def: 单位定义（通常传 NULL 或默认值）
     * 后面四个字符串对应 *IDN? 的返回信息：厂商, 型号, 序列号, 版本
     */
    SCPI_Init(&scpi_context,
              scpi_commands,
              &scpi_interface,
              scpi_units_def,
              "UNI-TREND", "UDP6900", "SN123456", "V1.0.0",
              scpi_input_buffer, SCPI_INPUT_BUFFER_LENGTH,
              scpi_error_queue_data, SCPI_ERROR_QUEUE_SIZE);
}
设置一个函数去定义
然后再使用这个函数

后面最主要的是   SCPI_Input(&scpi_context, (char*)g_usart_rx_buf, Size);
使能这个SCPI_Input即可
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if (huart->Instance == USART1)
    {
        /* 1. 【核心修正】在读取数据前，必须作废该段内存的 Cache */
        /* 这样确保 CPU 接下来读到的 g_usart_rx_buf 是从 RAM 里拿到的最新 DMA 数据 */
        SCB_InvalidateDCache_by_Addr((uint32_t*)g_usart_rx_buf, USART_REC_LEN);

        /* 2. 安全处理：手动添加字符串结束符 */
        if(Size < USART_REC_LEN) {
            g_usart_rx_buf[Size] = '\0'; 
        } else {
            g_usart_rx_buf[USART_REC_LEN - 1] = '\0';
        }
        
        SCPI_Input(&scpi_context, (char*)g_usart_rx_buf, Size);
        
        /* 5. 重新开启接收 */
        /* 因为你使用的是 DMA_NORMAL 模式，必须手动重启 */
        HAL_UARTEx_ReceiveToIdle_DMA(&huart1, g_usart_rx_buf, USART_REC_LEN);
    }
}
验证 ：通过串口调试助手 打印*IDN? 看看是否能有对应的值打印出来

/**********************************   END    **********************************/

