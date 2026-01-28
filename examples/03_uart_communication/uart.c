/**
 * @file uart.c
 * @brief UART串口通信模块实现
 *
 * 本文件实现UART的初始化和数据收发功能。
 * 在模拟器模式下，通过打印和缓冲区模拟串口通信。
 */

#include <stdio.h>
#include <string.h>
#include "uart.h"

/* UART配置 */
static uart_config_t uart_cfg;

/*
 * 模拟接收缓冲区 - 环形缓冲区实现
 * 注意：此实现非线程安全。在使用中断的实际嵌入式环境中，
 * 需要添加适当的同步机制（如禁用中断或使用原子操作）。
 */
static u8 rx_buffer[UART_BUFFER_SIZE];
static u32 rx_head = 0;
static u32 rx_tail = 0;

/**
 * @brief 初始化UART（使用默认配置）
 */
status_t uart_init(void)
{
    uart_config_t default_config = {
        .baudrate  = UART_DEFAULT_BAUDRATE,
        .data_bits = 8,
        .stop_bits = 1,
        .parity    = 0
    };

    return uart_init_config(&default_config);
}

/**
 * @brief 使用指定配置初始化UART
 */
status_t uart_init_config(const uart_config_t *config)
{
    if (config == NULL) {
        return STATUS_ERROR;
    }

    /* 保存配置 */
    uart_cfg = *config;

    /* 清空接收缓冲区 */
    rx_head = 0;
    rx_tail = 0;
    memset(rx_buffer, 0, sizeof(rx_buffer));

    printf("[UART] 初始化完成\n");
    printf("[UART] 配置: 波特率=%u, 数据位=%u, 停止位=%u, 校验=%u\n",
           uart_cfg.baudrate,
           uart_cfg.data_bits,
           uart_cfg.stop_bits,
           uart_cfg.parity);

    return STATUS_OK;
}

/**
 * @brief 发送单个字节
 */
status_t uart_send_byte(u8 data)
{
    printf("[UART TX] 0x%02X", data);
    if (data >= ASCII_PRINTABLE_MIN && data <= ASCII_PRINTABLE_MAX) {
        printf(" '%c'", data);
    }
    printf("\n");
    return STATUS_OK;
}

/**
 * @brief 发送字符串
 */
status_t uart_send_string(const char *str)
{
    if (str == NULL) {
        return STATUS_ERROR;
    }

    printf("[UART TX] 字符串: \"%s\"\n", str);
    return STATUS_OK;
}

/**
 * @brief 发送数据缓冲区
 */
status_t uart_send_buffer(const u8 *data, u32 len)
{
    u32 i;

    if (data == NULL || len == 0) {
        return STATUS_ERROR;
    }

    printf("[UART TX] 发送 %u 字节: ", len);
    for (i = 0; i < len; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");

    return STATUS_OK;
}

/**
 * @brief 接收单个字节
 */
status_t uart_receive_byte(u8 *data)
{
    if (data == NULL) {
        return STATUS_ERROR;
    }

    if (!uart_data_available()) {
        return STATUS_TIMEOUT;
    }

    *data = rx_buffer[rx_tail];
    rx_tail = (rx_tail + 1) % UART_BUFFER_SIZE;

    printf("[UART RX] 0x%02X", *data);
    if (*data >= ASCII_PRINTABLE_MIN && *data <= ASCII_PRINTABLE_MAX) {
        printf(" '%c'", *data);
    }
    printf("\n");

    return STATUS_OK;
}

/**
 * @brief 检查是否有数据可读
 */
bool uart_data_available(void)
{
    return rx_head != rx_tail;
}

/**
 * @brief 模拟接收数据
 */
void uart_simulate_receive(const u8 *data, u32 len)
{
    u32 i;

    if (data == NULL || len == 0) {
        return;
    }

    printf("[UART] 模拟接收 %u 字节数据\n", len);

    for (i = 0; i < len; i++) {
        u32 next_head = (rx_head + 1) % UART_BUFFER_SIZE;
        if (next_head != rx_tail) {  /* 缓冲区未满 */
            rx_buffer[rx_head] = data[i];
            rx_head = next_head;
        } else {
            printf("[UART] 警告: 接收缓冲区已满\n");
            break;
        }
    }
}
