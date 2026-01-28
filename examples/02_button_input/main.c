/**
 * @file main.c
 * @brief 按键输入检测示例主程序
 *
 * 本示例演示如何检测按键输入。
 * 在模拟器模式下，按Enter键模拟按键按下。
 */

#define _DEFAULT_SOURCE  /* for usleep() */
#include <stdio.h>
#include <unistd.h>
#include "button.h"

/* 模拟检测次数 */
#define SIMULATION_COUNT 5

/**
 * @brief 主函数
 *
 * 初始化按键并进行检测循环。
 */
int main(void)
{
    int i;
    int press_count = 0;

    printf("=== 按键输入检测示例 ===\n\n");

    /* 初始化按键 */
    if (button_init() != STATUS_OK) {
        printf("按键初始化失败！\n");
        return -1;
    }

    printf("\n开始模拟按键检测...\n\n");

    /* 模拟按键检测循环 */
    for (i = 0; i < SIMULATION_COUNT; i++) {
        printf("--- 第 %d 次检测 ---\n", i + 1);

        /* 模拟按键按下 */
        printf("模拟: 按下按键\n");
        button_simulate_press();

        /* 检测按键事件 */
        if (button_get_event() == BUTTON_EVENT_PRESSED) {
            press_count++;
            printf("检测到按键按下！总计: %d 次\n", press_count);
        }

        /* 延时 */
        usleep(100000);  /* 100ms */

        /* 模拟按键释放 */
        printf("模拟: 释放按键\n");
        button_simulate_release();

        /* 检测按键事件 */
        button_get_event();

        printf("\n");
        usleep(200000);  /* 200ms */
    }

    printf("=== 示例结束 ===\n");
    printf("总共检测到 %d 次按键按下\n", press_count);

    return 0;
}
