/**
 * @file main.c
 * @brief LED闪烁示例主程序
 *
 * 本示例演示如何控制LED灯闪烁。
 * 在模拟器模式下通过打印信息模拟LED状态变化。
 */

#define _DEFAULT_SOURCE  /* for usleep() */
#include <stdio.h>
#include <unistd.h>
#include "led.h"

/* 闪烁间隔时间（微秒） */
#define BLINK_INTERVAL_US 500000  /* 500ms */

/* 闪烁次数 */
#define BLINK_COUNT 10

/**
 * @brief 延时函数
 * @param us 延时微秒数
 *
 * 在实际嵌入式系统中，这个函数需要根据硬件定时器实现。
 */
static void delay_us(u32 us)
{
    usleep(us);
}

/**
 * @brief 主函数
 *
 * 初始化LED并进行闪烁循环。
 */
int main(void)
{
    int i;

    printf("=== LED闪烁示例 ===\n");
    printf("闪烁次数: %d, 间隔: %dms\n\n", BLINK_COUNT, BLINK_INTERVAL_US / 1000);

    /* 初始化LED */
    if (led_init() != STATUS_OK) {
        printf("LED初始化失败！\n");
        return -1;
    }

    /* LED闪烁循环 */
    for (i = 0; i < BLINK_COUNT; i++) {
        printf("第 %d 次闪烁\n", i + 1);

        led_on();
        delay_us(BLINK_INTERVAL_US);

        led_off();
        delay_us(BLINK_INTERVAL_US);
    }

    printf("\n=== 示例结束 ===\n");
    return 0;
}
