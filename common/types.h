/**
 * @file types.h
 * @brief 通用类型定义
 *
 * 本文件定义了嵌入式开发中常用的数据类型，
 * 提供跨平台的类型兼容性。
 */

#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <stdint.h>
#include <stdbool.h>

/* 基本数据类型别名 */
typedef uint8_t   u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
typedef int8_t    s8;
typedef int16_t   s16;
typedef int32_t   s32;

/* ASCII字符范围 */
#define ASCII_PRINTABLE_MIN 0x20  /* 空格 - 第一个可打印字符 */
#define ASCII_PRINTABLE_MAX 0x7E  /* ~ - 最后一个可打印字符 */

/* GPIO状态定义 */
typedef enum {
    GPIO_LOW  = 0,
    GPIO_HIGH = 1
} gpio_state_t;

/* 返回状态码 */
typedef enum {
    STATUS_OK    = 0,
    STATUS_ERROR = -1,
    STATUS_BUSY  = -2,
    STATUS_TIMEOUT = -3
} status_t;

/* 位操作宏 */
#define BIT_SET(reg, bit)    ((reg) |= (1U << (bit)))
#define BIT_CLR(reg, bit)    ((reg) &= ~(1U << (bit)))
#define BIT_TOGGLE(reg, bit) ((reg) ^= (1U << (bit)))
#define BIT_READ(reg, bit)   (((reg) >> (bit)) & 1U)

/* 常用宏定义 */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/*
 * MIN/MAX宏 - 注意：参数会被求值两次，
 * 使用时避免传入带有副作用的表达式（如 MIN(a++, b++)）
 */
#define MIN(a, b)       (((a) < (b)) ? (a) : (b))
#define MAX(a, b)       (((a) > (b)) ? (a) : (b))

#endif /* COMMON_TYPES_H */
