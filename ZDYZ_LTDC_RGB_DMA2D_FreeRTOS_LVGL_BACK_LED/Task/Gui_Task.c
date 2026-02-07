#include "Gui_Task.h"

lv_ui ui;

/* 定义信号位 (必须是 2 的幂次方) */
#define SIG_DMA2D_DONE    (1UL << 0)  // 0x01: 硬件搬运完成
#define SIG_MON_DMA_ERR   (1UL << 1)  // 0x02: 发现配置错误
/* 定义任务句柄，用于后续管理任务（比如删除或挂起） */
osThreadId_t ledTaskHandle;




//任务属性（Attributes）
// LED 任务：简单逻辑，1KB 足够
const osThreadAttr_t ledTask_attr = {
    .name = "LedTask",
    .stack_size = 256 * 4,
    .priority = osPriorityNormal,
};


//任务主函数
/* 1. LED 显示任务 */
void StartLedTask(void *argument) {
    for(;;) {
        LED0_TOGGLE();
        osDelay(500); // 延时 500ms，让出 CPU
    }
}




static void __Boot_Display_Logo(void)
{
    //  声明和获取图片资源 
    LV_IMG_DECLARE(_Logo_alpha_569x159);    
    LV_IMG_DECLARE(_HY_LOGO_alpha_639x178);  
    //  定义指针并指向想要的图片描述符
   const lv_img_dsc_t *imgSrc = &_Logo_alpha_569x159;  // 切换Logo
    //  设置图片源
   lv_img_set_src(ui.Back_img_Logo, imgSrc);
    // 重置 Image 对象的大小为“自适应内容”
    lv_obj_set_size(ui.Back_img_Logo, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    // 5. 对齐方式
    lv_obj_align(ui.Back_img_Logo, LV_ALIGN_CENTER, 0, 0);
    osDelay(200);
    // 6. 循环渐亮背光
    for(uint8_t i = 0; i <= 100; i += 1)
    {
        osDelay(20);  
        lv_task_handler();        
        //打开背光
     __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, i * 2);       
    } 
    
    //lv_obj_add_flag(ui.Back_img_Logo, LV_OBJ_FLAG_HIDDEN); 
    lv_obj_del(ui.Back_img_Logo); // 彻底删除对象释放内存
    ui.Back_img_Logo = NULL;

}


/*
 * @brief       static void __Load_Page(void)
 * @details     加载UI页面
 */
static void __Load_Page(void)
{
    //创建页面
    setup_scr_Back(&ui);
    //显示页面
    lv_scr_load(ui.Back); 
      //渐变背光   
    {
    __Boot_Display_Logo();
    }
    // HomePage_GroupCreate();
//    // 5. 强制刷新
//    lv_obj_invalidate(ui.screen_cont_1); 
    


}


//GUI任务--用于开始初始化其他任务&开启图像
void GUI_Task(void *argument)
{
  /* USER CODE BEGIN GUI_Task */    
    // 确保你的 DMA2D Mutex 已经创建完毕
    DMA2D_Mutex_Init();
    //LED
    ledTaskHandle      = osThreadNew(StartLedTask,      NULL, &ledTask_attr);
    //LVGL初始化
    lv_init();
    lv_port_disp_init();
    //开机背景
    __Load_Page();
    
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


