#include "Gui_Task.h"
#include "dma2d.h"
#include "lvgl.h"
#include "lv_port_disp.h"
/* 定义信号位 (必须是 2 的幂次方) */
#define SIG_DMA2D_DONE    (1UL << 0)  // 0x01: 硬件搬运完成
#define SIG_MON_DMA_ERR   (1UL << 1)  // 0x02: 发现配置错误
/* 定义任务句柄，用于后续管理任务（比如删除或挂起） */
osThreadId_t ledTaskHandle;
osThreadId_t screenTaskHandle;
osThreadId_t waveformTaskHandle;

#include "lvgl.h"


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
//任务属性（Attributes）
// LED 任务：简单逻辑，1KB 足够
const osThreadAttr_t ledTask_attr = {
    .name = "LedTask",
    .stack_size = 256 * 4,
    .priority = osPriorityNormal,
};

// 屏幕刷新任务：2KB 栈空间
const osThreadAttr_t screenTask_attr = {
    .name = "ScreenTask",
    .stack_size = 512 * 4,
    .priority = osPriorityNormal,
};

// 波形绘制任务：2KB 栈空间，高优先级
const osThreadAttr_t waveformTask_attr = {
    .name = "WaveTask",
    .stack_size = 512 * 4,
    .priority = osPriorityAboveNormal,
};


//任务主函数
/* 1. LED 显示任务 */
void StartLedTask(void *argument) {
    for(;;) {
        LED0_TOGGLE();
        osDelay(500); // 延时 500ms，让出 CPU
    }
}
static uint16_t my_image[101 * 201];
/* 任务 2: 屏幕刷新任务 (优先级 Normal) */
void StartScreenTask(void *argument) {


    // 在某处初始化这个数组
    for(int i=0; i < (101*201); i++) my_image[i] = 0x5500; // 全填成紫色
    for(;;) {
        // 尝试刷全屏为黑色
        ltdc_fill(0, 0, 799, 479, 0x0000); 
        osDelay(500); 
        ltdc_color_fill(0, 0, 100, 200, my_image);
        osDelay(500);
    }

}

/* 任务 3: 波形绘制任务 (优先级 AboveNormal) */
void StartWaveformTask(void *argument) {
    for(;;) {
        // 在屏幕中间画一个红色条块，模拟波形数据更新
        // 即使 ScreenTask 正在刷全屏，由于有 Mutex，这个任务会排队等待硬件空闲
        ltdc_fill(300, 200, 500, 210, 0xF800); 
        osDelay(20); // 采样频率更快
    }
}



//GUI任务--用于开始初始化其他任务&开启图像
void GUI_Task(void *argument)
{
  /* USER CODE BEGIN GUI_Task */    
    // 确保你的 DMA2D Mutex 已经创建完毕
    DMA2D_Mutex_Init();
//    /* --- 步骤 B: 调用创建函数 --- */    
//    // 创建任务
    ledTaskHandle      = osThreadNew(StartLedTask,      NULL, &ledTask_attr);
//    screenTaskHandle   = osThreadNew(StartScreenTask,   NULL, &screenTask_attr);
//    waveformTaskHandle = osThreadNew(StartWaveformTask, NULL, &waveformTask_attr);
//    
    
    lv_init();
    lv_port_disp_init();
    
   // lv_demo_staggered_boxes();
    lv_demo_staggered_boxes_ONE();

    
    for(;;) {
       lv_timer_handler();
        osDelay(5);
    //检测内存使用率
//    lv_mem_monitor_t mon;
//    lv_mem_monitor(&mon);
//    printf("Used: %d%%, Free: %dB\n", mon.used_pct, mon.free_size);
    }
  /* Infinite loop */

  /* USER CODE END GUI_Task */
}


