/**
 * @file led.h
 * @brief LED控制模块头文件
 *
 * 提供LED初始化和控制的接口函数。
 */

#ifndef LED_H
#define LED_H

#include "../../common/types.h"

/* LED引脚定义（可根据实际硬件修改） */
#define LED_PIN 13

/**
 * @brief 初始化LED
 * @return STATUS_OK 成功，STATUS_ERROR 失败
 */
status_t led_init(void);

/**
 * @brief 点亮LED
 */
void led_on(void);

/**
 * @brief 熄灭LED
 */
void led_off(void);

/**
 * @brief 切换LED状态
 */
void led_toggle(void);

/**
 * @brief 获取LED当前状态
 * @return GPIO_HIGH LED亮，GPIO_LOW LED灭
 */
gpio_state_t led_get_state(void);

#endif /* LED_H */
