/**
 * @file main.c
 * @brief UART串口通信示例主程序
 *
 * 本示例演示如何进行串口数据的发送和接收。
 * 在模拟器模式下通过缓冲区模拟串口通信。
 */

#include <stdio.h>
#include <string.h>
#include "uart.h"

/**
 * @brief 主函数
 *
 * 演示UART的基本使用方法。
 */
int main(void)
{
    u8 rx_data;
    const char *test_string = "Hello, UART!";
    u8 test_buffer[] = {0x01, 0x02, 0x03, 0x04, 0x05};

    printf("=== UART串口通信示例 ===\n\n");

    /* 初始化UART */
    if (uart_init() != STATUS_OK) {
        printf("UART初始化失败！\n");
        return -1;
    }

    printf("\n--- 测试1: 发送单个字节 ---\n");
    uart_send_byte('A');
    uart_send_byte('B');
    uart_send_byte('C');

    printf("\n--- 测试2: 发送字符串 ---\n");
    uart_send_string(test_string);

    printf("\n--- 测试3: 发送数据缓冲区 ---\n");
    uart_send_buffer(test_buffer, sizeof(test_buffer));

    printf("\n--- 测试4: 模拟接收数据 ---\n");
    /* 模拟接收一些数据 */
    uart_simulate_receive((const u8 *)"TEST", 4);

    /* 读取接收到的数据 */
    printf("读取接收缓冲区:\n");
    while (uart_data_available()) {
        if (uart_receive_byte(&rx_data) == STATUS_OK) {
            /* 数据已在uart_receive_byte中打印 */
        }
    }

    printf("\n--- 测试5: 模拟数据回显 ---\n");
    /* 模拟接收并回显 */
    const char *echo_data = "ECHO";
    uart_simulate_receive((const u8 *)echo_data, strlen(echo_data));

    printf("回显接收到的数据:\n");
    while (uart_data_available()) {
        if (uart_receive_byte(&rx_data) == STATUS_OK) {
            printf("回显: ");
            uart_send_byte(rx_data);
        }
    }

    printf("\n=== 示例结束 ===\n");
    return 0;
}
