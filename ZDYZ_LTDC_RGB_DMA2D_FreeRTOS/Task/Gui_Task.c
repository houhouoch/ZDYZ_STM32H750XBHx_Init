#include "Gui_Task.h"
#include "dma2d.h"

/* 定义信号位 (必须是 2 的幂次方) */
#define SIG_DMA2D_DONE    (1UL << 0)  // 0x01: 硬件搬运完成
#define SIG_MON_DMA_ERR   (1UL << 1)  // 0x02: 发现配置错误
/* 定义任务句柄，用于后续管理任务（比如删除或挂起） */
osThreadId_t ledTaskHandle;
osThreadId_t screenTaskHandle;
osThreadId_t waveformTaskHandle;

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
    /* --- 步骤 B: 调用创建函数 --- */    
    // 创建任务
    ledTaskHandle      = osThreadNew(StartLedTask,      NULL, &ledTask_attr);
    screenTaskHandle   = osThreadNew(StartScreenTask,   NULL, &screenTask_attr);
    waveformTaskHandle = osThreadNew(StartWaveformTask, NULL, &waveformTask_attr);
    


    
    for(;;) {
        // 可以在这里处理 LVGL 的心跳，或者监控子任务状态
        osDelay(100); 
    }
  /* Infinite loop */

  /* USER CODE END GUI_Task */
}


