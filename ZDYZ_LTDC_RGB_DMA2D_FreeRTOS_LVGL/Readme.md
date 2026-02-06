https://www.cnblogs.com/lesterbor/p/17953045 这是移�?LVGLv8.3的�?�?  参照完全没错

#define LV_TICK_CUSTOM 1
#if LV_TICK_CUSTOM
    #define LV_TICK_CUSTOM_INCLUDE "FreeRTOS.h"         /*Header for the system time function*/
    #define LV_TICK_CUSTOM_SYS_TIME_EXPR (xTaskGetTickCount())    /*Expression evaluating to current system time in ms*/
    /*If using lvgl as ESP32 component*/
    // #define LV_TICK_CUSTOM_INCLUDE "esp_timer.h"
    // #define LV_TICK_CUSTOM_SYS_TIME_EXPR ((esp_timer_get_time() / 1000LL))
#endif   /*LV_TICK_CUSTOM*/

记得打开LVGL的时钟配�?��否则动画跑不起来�?

#define LV_MEM_SIZE    (128U * 1024U)很重�? 


在GUI_Task任务�?��osDelay要�?�?��
    for(;;) {
       lv_timer_handler();
        osDelay(10);
    //检测内存使用率
    lv_mem_monitor_t mon;
    lv_mem_monitor(&mon);
    printf("Used: %d%%, Free: %dB\n", mon.used_pct, mon.free_size);
    }

你�?�?�� osDelay(50) 意味着 LVGL 每�?�?���? 20 次（20 FPS）�? 对于性能强劲�? H750 来�?，这有点“大材小用”了，画面可能会有轻�?��掉帧感�?

优化建�?：将 osDelay(50) 改为 osDelay(5) �? osDelay(10)





LVGL内部开�?���?��
/* 开�?��件加速：让大厨上�? */
#define LV_USE_GPU_STM32_DMA2D    1

/* 指定头文件：�? LVGL 认识你的 H750 */
#define LV_GPU_DMA2D_CMSIS_INCLUDE "stm32h7xx.h"

LVGL的内存池大小设置 以及内存池首地址，这边将内存设置在外部，而不用内部的axi总线上的内存，后续工程gui内容较多，缺点就是 会运行的慢一点，比不上使用内部。
    /*Size of the memory available for `lv_mem_alloc()` in bytes (>= 2kB)*/
    #define LV_MEM_SIZE (1024U * 1024U)          /*[bytes]*/

    /*Set an address for the memory pool instead of allocating it as a normal array. Can be in external SRAM too.*/
    #define LV_MEM_ADR  0xC0800000     /*0: unused*/
    /*Instead of an address give a memory allocator that will be called to get a memory pool for LVGL. E.g. my_malloc*/
    #if LV_MEM_ADR == 0
        #undef LV_MEM_POOL_INCLUDE
        #undef LV_MEM_POOL_ALLOC
    #endif

作者这边设置了#define BUF_1_2   0
#define FB_ADD_1_2  1 两个可选项，保留 BUF_1_2 作为教学和兼容性选项是一个非常有远见的做法，因为并不是所有的屏幕都支持“零拷贝”（比如常见的 SPI 接口屏或 8080 并口屏就必须使用搬运模式）。
维度模式一：BUF_1_2 (经典搬运型)模式二：FB_ADD_1_2 (零拷贝切换型)底层核心MemCPY (内存拷贝)Pointer Swap (指针切换)刷新函数使用 ltdc_color_fill (DMA2D 搬运)使用 HAL_LTDC_SetAddress (修改寄存器)数据流向缓冲区 $\xrightarrow{DMA2D}$ 显存缓冲区 $\equiv$ 显存 (原地不动)硬件要求几乎所有屏幕和接口都支持。必须是带 LTDC/主控能直接读取显存的硬件。学习价值适合理解 “局部刷新” 和 “外设写入”。适合理解 “硬件加速” 和 “显存映射”。
🔄 为什么说 BUF_1_2 是“绕”的？
你提到的“绕”，在技术上体现为数据流转的冗余步奏。即便地址设为一样，它依然在逻辑上绕了路：

逻辑解耦的负担： 在 BUF_1_2 模式下，LVGL 认为 color_p 只是一个普通的内存块。它并不知道这个块就是显存。所以它会老老实实地调用 flush_cb，请求你把这块数据“发”给显示器。

中间人的参与： 你调用了 ltdc_color_fill，这就引入了 DMA2D 这个中间人。

动作：DMA2D 必须去读取一次 SDRAM，然后再写入一次 SDRAM。

带宽浪费：对于 H7 来说，这增加了 FMC 总线的占用率。就像你把一叠钱从左口袋掏出来，交给跑腿公司，再让跑腿公司放进你的右口袋。

串行等待： 在你的代码里，osThreadFlagsWait 会让当前任务阻塞，直到 DMA2D 搬完。这意味着 CPU 在这段时间内必须停下来等待数据搬运完成。

🚀 为什么说 FB_ADD_1_2 是“直接”的？
身份合一： 缓冲区就是显存。LVGL 画完的那一刻，数据其实已经在显存里躺着了。

瞬间交接： 所谓的“刷新”，仅仅是给 LTDC 硬件发个信号：“别盯着刚才那块地盘看了，看这边！”。这个动作耗时几乎为 0。

并行效率： LTDC 硬件在读 FB0 显示上一帧时，CPU 和 DMA2D 可以完全不受干扰地在 FB1 上画下一帧。两者在物理空间上完全隔离，没有任何总线争抢。

💡 给读者的移植建议（补充你的总结）
如果你要写注释给后来者看，可以这样描述：

如果你是“初学者”或使用“非显存映射屏”：请开启 BUF_1_2。你需要实现 ltdc_color_fill，这能帮你理解如何将像素数据推送到硬件。注意：此时缓冲区地址建议避开显存基地址，存放在 SDRAM 的偏移区域。

如果你追求“极致性能”且使用“LTDC 屏”：请开启 FB_ADD_1_2。并将缓冲区地址与 LTDC 层地址对齐。这将开启“零拷贝”模式，彻底释放 CPU 带宽，让帧率达到硬件极限。


在我的guitask任务中，有两个函数，分别是 一个方块进行移动，另外一个是 一群方块进行移动（为了测试帧率以及CPU占用速度）
void lv_demo_staggered_boxes_ONE(void)
{
    /* 1. 先创建一个真实的方块对象 */
    lv_obj_t * my_box = lv_obj_create(lv_scr_act()); 
    lv_obj_set_size(my_box, 100, 100);                          // 设置大小 100x100
    lv_obj_set_style_bg_color(my_box, lv_palette_main(LV_PALETTE_RED), 0); // 设置颜色为红色
    lv_obj_align(my_box, LV_ALIGN_LEFT_MID, 0, 0);               // 靠左对齐

    /* 2. 创建并启动动画 */
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, my_box);             // 绑定刚才创建的红色方块
    lv_anim_set_values(&a, 0, 400);          // 设置 X 轴从 0 移动到 400
    lv_anim_set_time(&a, 5000);              // 动画时长 2 秒
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_x); // 动画执行函数：设置 X 坐标
    lv_anim_set_path_cb(&a, lv_anim_path_linear); // 线性运动
    lv_anim_set_playback_time(&a, 2000);     // 往返运动：回来也用 2 秒
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE); // 无限循环
    lv_anim_start(&a);                       // 启动！


}

/* --- 配置区域 --- */
#define SCREEN_WIDTH    800     // 屏幕宽度
#define SCREEN_HEIGHT   480     // 屏幕高度
#define BOX_SIZE        40     // 每个小方块的边长 (像素)
#define ANIM_RANGE      30      // 移动幅度 (向下浮动多少像素)
#define ANIM_TIME       1000    // 单程动画时间 (ms)
#define DELAY_STEP_X    50      // X轴方向每延迟一步增加的时间 (ms)
#define DELAY_STEP_Y    100     // Y轴方向每延迟一步增加的时间 (ms)


/**
 * 创建满屏错位移动的小方块
 */
void lv_demo_staggered_boxes(void)
{
    /* 计算行数和列数，确保铺满屏幕 */
    int cols = SCREEN_WIDTH / BOX_SIZE + 1;
    int rows = SCREEN_HEIGHT / BOX_SIZE + 1;

    /* 获取当前活动屏幕作为父对象 */
    lv_obj_t * parent = lv_scr_act();

    /* 为了性能，移除父对象的滚动条和默认样式 */
    lv_obj_remove_style_all(parent);
    lv_obj_set_style_bg_color(parent, lv_color_black(), 0); // 背景设为黑色

    for(int y = 0; y < rows; y++) {
        for(int x = 0; x < cols; x++) {
            
            /* --- 1. 创建方块对象 --- */
            lv_obj_t * box = lv_obj_create(parent);
            lv_obj_set_size(box, BOX_SIZE, BOX_SIZE);
            
            /* 绝对定位：根据行列号计算初始位置 */
            lv_coord_t start_x = x * BOX_SIZE;
            lv_coord_t start_y = y * BOX_SIZE;
            lv_obj_set_pos(box, start_x, start_y);

            /* --- 2. 设置样式 (为了好看，去掉边框和圆角，并根据位置生成渐变色) --- */
            /* 生成颜色：让颜色随着位置变化，形成彩虹墙效果 */
            /* 使用 HSV 颜色空间更容易生成平滑过渡的颜色 */
            // Hue(色相)根据 X 轴变化, Saturation(饱和度)根据 Y 轴变化
            uint8_t hue = (x * 255) / cols;
            uint8_t sat = 150 + (y * 100) / rows; 
            lv_color_t color = lv_color_hsv_to_rgb(hue, sat, 220);

            lv_obj_set_style_bg_color(box, color, 0);
            lv_obj_set_style_bg_opa(box, LV_OPA_COVER, 0); // 确保不透明
            lv_obj_set_style_border_width(box, 1, 0);      // 设置1像素边框方便看清边界
            lv_obj_set_style_border_color(box, lv_color_black(), 0);
            lv_obj_set_style_radius(box, 0, 0);            // 直角方块
            lv_obj_set_scrollbar_mode(box, LV_SCROLLBAR_MODE_OFF); // 关闭内部滚动条

            /* --- 3. 设置错位动画 (核心逻辑) --- */
            /* 计算延迟时间：这是错位效果的灵魂 */
            /* 延迟时间 = 列号 * X步进 + 行号 * Y步进 */
            uint32_t delay = (x * DELAY_STEP_X) + (y * DELAY_STEP_Y);

            lv_anim_t a;
            lv_anim_init(&a);
            lv_anim_set_var(&a, box); // 绑定当前方块

            /* 设置动画值：在 Y 轴方向上，从当前位置向下移动 ANIM_RANGE 个像素 */
            lv_anim_set_values(&a, start_y, start_y + ANIM_RANGE);
            
            /* 设置执行回调函数：改变 Y 坐标 */
            lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_y);

            /* 设置时间参数 */
            lv_anim_set_time(&a, ANIM_TIME);          // 去程时间
            lv_anim_set_playback_time(&a, ANIM_TIME); // 回程时间 (实现往返运动)
            lv_anim_set_delay(&a, delay);             // 【关键】设置启动延迟
            
            /* 设置运动路径：使用 Ease In Out 让运动更顺滑自然 */
            lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);
            
            /* 设置无限重复 */
            lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
            
            /* 启动动画 */
            lv_anim_start(&a);
        }
    }
}
这边实验案例使用一个小方块进行左右移动，可以看到BUF_1_2的使能，其cpu占用百分之75，而使能FB_ADD_1_2 ，其cpu降低至百分之25
这两种方案 明显后者cpu占用的小一点，这样方便cpu处理后续CAN通信以及其他

这边单独对#define BUF_1_2   0进行一个解释
在我的ltdc_color_fill中， 我是void ltdc_color_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color)
{    
    //  抢占互斥锁 (Mutex)
    if (osMutexAcquire(dma2dMutexHandle, osWaitForever) != osOK) return;
    uint32_t width  = ex - sx + 1;
    uint32_t height = ey - sy + 1;
    uint32_t addr   = 0xC0000000 + 2 * (800 * sy + sx); 
    /* 记录当前正在调用的任务 ID */
    drawingTaskHandle = osThreadGetId();
    /*  Cache 管理：确保 DMA2D 读到的是最新的内存数据 */
    SCB_CleanDCache_by_Addr((uint32_t*)color, width * height * 2);
    /*  配置模式与地址 */
    DMA2D->CR      = DMA2D_M2M;                      // 存储器到存储器模式
    DMA2D->FGMAR   = (uint32_t)color;                 // 源：LVGL 缓冲区
    DMA2D->OMAR    = addr;                            // 目：SDRAM 显存
    DMA2D->FGOR    = 0;                               // 源偏移
    DMA2D->OOR     = 800 - width;                     // 目标偏移 (屏幕宽度 - 填充宽度)
    DMA2D->FGPFCCR = LTDC_PIXEL_FORMAT_RGB565;        // 输入格式
    DMA2D->OPFCCR  = LTDC_PIXEL_FORMAT_RGB565;        // 输出格式
    DMA2D->NLR     = (height) | (width << 16);        // 设置宽高    
    /*  开启中断并启动 */
    DMA2D->IFCR |= DMA2D_IFCR_CTCIF;                  // 先清一次标志位
    DMA2D->CR   |= DMA2D_CR_TCIE;                     // 使能传输完成中断
    DMA2D->CR   |= DMA2D_CR_START;                    // 开启搬运
    /* 阻塞当前调用的任务 */
    osThreadFlagsWait(SIGNAL_DMA2D_TC, osFlagsWaitAll, osWaitForever);  
    //  释放互斥锁
    osMutexRelease(dma2dMutexHandle);
}
  DMA2D->OMAR    = addr;                            // 目：SDRAM 显存将其换成地址设置为0xc0000000
  要注意 这里的#define VOL_BUF_1    (0xC0200000)   /* 缓冲区1：偏移 2MB 处 */  设置不能设置目标地址和源地址一样 
  VOL_BUF_1    (0xC0200000)为源地址   (0xC0000000) 为目标地址 