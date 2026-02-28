#include "HomePage_LED.h"
#include "Gui_Task.h"

/**********************LED*******************/
/* --- LED 模式配置 --- */
#define LED_MODE_BLINK   0  // 闪烁模式
#define LED_MODE_BREATH  1  // 呼吸模式

// 全局切换LED状态
#define UI_LED_WORKING_STYLE  LED_MODE_BREATH
/* ----------------- LED 视觉参数配置 (设计者修改区) ----------------- */

// 1. 呼吸灯参数
#define UI_LED_BREATH_IN_MS      200      // 吸气时间 (从暗到亮)
#define UI_LED_BREATH_OUT_MS     600     // 呼气时间 (从亮到暗)
#define UI_LED_BREATH_MIN_BRIGHT 50       // 最暗亮度 (0-255)
#define UI_LED_BREATH_MAX_BRIGHT 255      // 最亮亮度 (0-255)

// 2. 闪烁灯参数
#define UI_LED_BLINK_COLOR       0x52FF00 // 闪烁时的亮色 (纯绿)
#define UI_LED_BLINK_DEF_PERIOD  200      // 默认闪烁周期 (ms)

//LED呼吸效果
void ui_led_start_asymmetric_breathing(lv_obj_t *led_obj)
{
    if (led_obj == NULL) return;
    
    lv_obj_set_style_shadow_width(led_obj, 0, 0);   // 关掉阴影
    lv_obj_set_style_border_width(led_obj, 0, 0);   // 关掉边框
   
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, led_obj);
    
    // 使用宏定义替换硬编码
    lv_anim_set_values(&a, UI_LED_BREATH_MIN_BRIGHT, UI_LED_BREATH_MAX_BRIGHT);
    lv_anim_set_time(&a, UI_LED_BREATH_IN_MS);//  快速变亮 (吸气)
    lv_anim_set_playback_time(&a, UI_LED_BREATH_OUT_MS);// 1000ms 缓慢熄灭 (呼气)
    
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out); 
    
    lv_anim_set_exec_cb(&a, (void (*)(void *, int32_t))lv_led_set_brightness);
    lv_anim_start(&a);    

}

//LED闪烁
/**
 * @brief  LED 闪烁回调 (使用配置色)
 */

//static void led_blink_timer_cb(lv_timer_t * t) {
//    lv_obj_t * led = (lv_obj_t *)t->user_data;
//    static bool state = false;
//    state = !state;

//    if (state) {
//        lv_led_on(led);
//        lv_led_set_color(led, lv_color_hex(UI_LED_BLINK_COLOR)); 
//    } else {
//        lv_led_off(led);
//    }
//}
//多个LED操作的时候使用下面的函数
static void led_blink_timer_cb(lv_timer_t * t) {
    lv_obj_t * led = (lv_obj_t *)t->user_data;
    
    // 逻辑：如果当前亮度 > 127 就关掉，否则就开启
    // 这样不需要 static bool，多个 LED 独立运行互不影响
    if (lv_led_get_brightness(led) > 127) {
        lv_led_off(led);
    } else {
        lv_led_on(led);
        lv_led_set_color(led, lv_color_hex(UI_LED_BLINK_COLOR));
    }
}

/**
 * @brief  启动 LED 闪烁
 */
void ui_led_start_blink(lv_obj_t *led_obj) {
    
    if (led_obj == NULL) return;    
    lv_timer_create(led_blink_timer_cb, UI_LED_BLINK_DEF_PERIOD, led_obj);
}


/**
 * @brief  统一 LED 效果启动函数
 * @param  led_obj: 目标 LED 对象指针
 */
void ui_led_start(lv_obj_t *led_obj)
{
    if (led_obj == NULL) return; 
   
    #if (UI_LED_WORKING_STYLE == LED_MODE_BREATH)
        ui_led_start_asymmetric_breathing(led_obj);
    #else       
        ui_led_start_blink(led_obj); 
    #endif
    
}
