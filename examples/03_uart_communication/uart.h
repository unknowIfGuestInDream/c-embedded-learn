/**
 * @file uart.h
 * @brief UART串口通信模块头文件
 *
 * 提供UART初始化和数据收发的接口函数。
 */

#ifndef UART_H
#define UART_H

#include "../../common/types.h"

/* UART默认配置 */
#define UART_DEFAULT_BAUDRATE 115200
#define UART_BUFFER_SIZE      256

/* UART配置结构体 */
typedef struct {
    u32 baudrate;      /* 波特率 */
    u8  data_bits;     /* 数据位 (5-8) */
    u8  stop_bits;     /* 停止位 (1-2) */
    u8  parity;        /* 校验位 (0:无, 1:奇, 2:偶) */
} uart_config_t;

/**
 * @brief 初始化UART（使用默认配置）
 * @return STATUS_OK 成功，STATUS_ERROR 失败
 */
status_t uart_init(void);

/**
 * @brief 使用指定配置初始化UART
 * @param config UART配置
 * @return STATUS_OK 成功，STATUS_ERROR 失败
 */
status_t uart_init_config(const uart_config_t *config);

/**
 * @brief 发送单个字节
 * @param data 要发送的字节
 * @return STATUS_OK 成功，STATUS_ERROR 失败
 */
status_t uart_send_byte(u8 data);

/**
 * @brief 发送字符串
 * @param str 要发送的字符串
 * @return STATUS_OK 成功，STATUS_ERROR 失败
 */
status_t uart_send_string(const char *str);

/**
 * @brief 发送数据缓冲区
 * @param data 数据缓冲区
 * @param len 数据长度
 * @return STATUS_OK 成功，STATUS_ERROR 失败
 */
status_t uart_send_buffer(const u8 *data, u32 len);

/**
 * @brief 接收单个字节
 * @param data 接收数据的指针
 * @return STATUS_OK 成功，STATUS_ERROR 失败，STATUS_TIMEOUT 超时
 */
status_t uart_receive_byte(u8 *data);

/**
 * @brief 检查是否有数据可读
 * @return true 有数据，false 无数据
 */
bool uart_data_available(void);

/**
 * @brief 模拟接收数据（用于测试）
 * @param data 模拟接收的数据
 * @param len 数据长度
 */
void uart_simulate_receive(const u8 *data, u32 len);

#endif /* UART_H */
