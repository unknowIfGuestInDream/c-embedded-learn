/**
 * @file button.c
 * @brief 按键控制模块实现
 *
 * 本文件实现按键的初始化和读取功能，包含消抖处理。
 * 在模拟器模式下，通过变量模拟按键状态。
 */

#define _DEFAULT_SOURCE  /* for usleep() */
#include <stdio.h>
#include <unistd.h>
#include "button.h"

/* 模拟的按键状态（用于测试） */
static gpio_state_t simulated_button_state = GPIO_HIGH;

/* 上一次按键状态（用于事件检测） */
static gpio_state_t last_button_state = GPIO_HIGH;

/**
 * @brief 延时函数（毫秒）
 */
static void delay_ms(u32 ms)
{
    usleep(ms * 1000);
}

/**
 * @brief 初始化按键
 *
 * 在实际硬件中，这里需要配置GPIO为输入模式，并设置上拉电阻。
 */
status_t button_init(void)
{
    simulated_button_state = GPIO_HIGH;
    last_button_state = GPIO_HIGH;
    printf("[按键] 初始化完成，引脚: %d\n", BUTTON_PIN);
    return STATUS_OK;
}

/**
 * @brief 读取按键原始状态
 *
 * 直接读取GPIO电平，不进行消抖处理。
 */
gpio_state_t button_read_raw(void)
{
    return simulated_button_state;
}

/**
 * @brief 读取按键状态（带消抖）
 *
 * 通过延时消抖，确保按键状态稳定。
 */
gpio_state_t button_read(void)
{
    gpio_state_t state1, state2;

    /* 第一次读取 */
    state1 = button_read_raw();

    /* 延时消抖 */
    delay_ms(DEBOUNCE_DELAY_MS);

    /* 第二次读取 */
    state2 = button_read_raw();

    /* 两次读取状态相同，说明状态稳定 */
    if (state1 == state2) {
        return state1;
    }

    /* 状态不稳定，返回未按下 */
    return GPIO_HIGH;
}

/**
 * @brief 检测按键事件
 *
 * 检测按键状态变化，返回对应的事件。
 */
button_event_t button_get_event(void)
{
    gpio_state_t current_state;
    button_event_t event = BUTTON_EVENT_NONE;

    current_state = button_read();

    /* 检测按下事件（高->低） */
    if (last_button_state == GPIO_HIGH && current_state == GPIO_LOW) {
        event = BUTTON_EVENT_PRESSED;
        printf("[按键] 事件: 按下 ▼\n");
    }
    /* 检测释放事件（低->高） */
    else if (last_button_state == GPIO_LOW && current_state == GPIO_HIGH) {
        event = BUTTON_EVENT_RELEASED;
        printf("[按键] 事件: 释放 ▲\n");
    }

    last_button_state = current_state;
    return event;
}

/**
 * @brief 模拟按键按下
 */
void button_simulate_press(void)
{
    simulated_button_state = GPIO_LOW;
}

/**
 * @brief 模拟按键释放
 */
void button_simulate_release(void)
{
    simulated_button_state = GPIO_HIGH;
}
