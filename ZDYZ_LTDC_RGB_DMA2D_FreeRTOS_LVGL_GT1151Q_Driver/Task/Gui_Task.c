#include "Gui_Task.h"

lv_ui ui;

/* 定义信号位 (必须是 2 的幂次方) */
#define SIG_DMA2D_DONE    (1UL << 0)  // 0x01: 硬件搬运完成
#define SIG_MON_DMA_ERR   (1UL << 1)  // 0x02: 发现配置错误
/* 定义任务句柄，用于后续管理任务（比如删除或挂起） */
osThreadId_t ledTaskHandle;

static void test_btn_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);

    if(code == LV_EVENT_CLICKED) {
        static uint8_t cnt = 0;
        cnt++;

        // 1. 改变按钮颜色 (给你一个视觉反馈)
        // 每次点击，按钮会在 绿色 -> 蓝色 -> 橙色 之间切换
        lv_color_t colors[] = {lv_palette_main(LV_PALETTE_GREEN), 
                               lv_palette_main(LV_PALETTE_BLUE), 
                               lv_palette_main(LV_PALETTE_ORANGE)};
        lv_obj_set_style_bg_color(btn, colors[cnt % 3], 0);

        // 2. 串口打印 (如果你还开着 printf)
        // printf("Button clicked! Count: %d\n", cnt);
    }
}
void ui_create_test_button(void)
{
    // 1. 在当前活跃屏幕上创建一个按钮
    lv_obj_t * btn = lv_btn_create(lv_scr_act()); 
    
    // 2. 设置大小和位置（放在屏幕中心）
    lv_obj_set_size(btn, 200, 80);
    lv_obj_align(btn, LV_ALIGN_CENTER, -200, 200);

    // 3. 为按钮添加标签文字
    lv_obj_t * label = lv_label_create(btn);
    lv_label_set_text(label, "TOUCH TEST");
    lv_obj_center(label);

    // 4. 绑定点击事件
    lv_obj_add_event_cb(btn, test_btn_event_cb, LV_EVENT_ALL, NULL);
    
    // 5. 设置一个初始的高级样式（可选）
    lv_obj_set_style_radius(btn, 10, 0); // 圆角
    lv_obj_set_style_shadow_width(btn, 20, 0); // 阴影
}


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
     HomePage_GroupCreate();
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
    lv_port_indev_init();
    //开机背景
   // __Load_Page();
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 200); // 200/100 左右即可点亮
    ui_create_test_button();
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


