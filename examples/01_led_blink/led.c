/**
 * @file led.c
 * @brief LED控制模块实现
 *
 * 本文件实现LED的初始化和控制功能。
 * 在模拟器模式下，通过打印信息模拟LED状态变化。
 */

#include <stdio.h>
#include "led.h"

/* LED当前状态 */
static gpio_state_t led_state = GPIO_LOW;

/**
 * @brief 初始化LED
 *
 * 在实际硬件中，这里需要配置GPIO为输出模式。
 * 模拟器模式下只进行状态初始化。
 */
status_t led_init(void)
{
    led_state = GPIO_LOW;
    printf("[LED] 初始化完成，引脚: %d\n", LED_PIN);
    return STATUS_OK;
}

/**
 * @brief 点亮LED
 *
 * 设置GPIO输出高电平，LED点亮。
 */
void led_on(void)
{
    led_state = GPIO_HIGH;
    printf("[LED] 状态: 亮 ●\n");
}

/**
 * @brief 熄灭LED
 *
 * 设置GPIO输出低电平，LED熄灭。
 */
void led_off(void)
{
    led_state = GPIO_LOW;
    printf("[LED] 状态: 灭 ○\n");
}

/**
 * @brief 切换LED状态
 *
 * 如果当前是亮的就熄灭，如果是灭的就点亮。
 */
void led_toggle(void)
{
    if (led_state == GPIO_HIGH) {
        led_off();
    } else {
        led_on();
    }
}

/**
 * @brief 获取LED当前状态
 */
gpio_state_t led_get_state(void)
{
    return led_state;
}
