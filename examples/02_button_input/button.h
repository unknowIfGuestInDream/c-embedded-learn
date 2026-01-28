/**
 * @file button.h
 * @brief 按键控制模块头文件
 *
 * 提供按键初始化和读取的接口函数。
 */

#ifndef BUTTON_H
#define BUTTON_H

#include "../../common/types.h"

/* 按键引脚定义（可根据实际硬件修改） */
#define BUTTON_PIN 2

/* 消抖延时时间（毫秒） */
#define DEBOUNCE_DELAY_MS 20

/* 按键事件类型 */
typedef enum {
    BUTTON_EVENT_NONE = 0,    /* 无事件 */
    BUTTON_EVENT_PRESSED,     /* 按键按下 */
    BUTTON_EVENT_RELEASED     /* 按键释放 */
} button_event_t;

/**
 * @brief 初始化按键
 * @return STATUS_OK 成功，STATUS_ERROR 失败
 */
status_t button_init(void);

/**
 * @brief 读取按键原始状态
 * @return GPIO_HIGH 未按下，GPIO_LOW 按下
 */
gpio_state_t button_read_raw(void);

/**
 * @brief 读取按键状态（带消抖）
 * @return GPIO_HIGH 未按下，GPIO_LOW 按下
 */
gpio_state_t button_read(void);

/**
 * @brief 检测按键事件
 * @return 按键事件类型
 */
button_event_t button_get_event(void);

/**
 * @brief 模拟按键按下（用于测试）
 */
void button_simulate_press(void);

/**
 * @brief 模拟按键释放（用于测试）
 */
void button_simulate_release(void);

#endif /* BUTTON_H */
