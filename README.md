# C嵌入式学习项目

这是一个用于学习嵌入式C语言编程的入门项目，包含多个学习示例，每个示例放置在独立的文件夹中。

## 学习示例列表

| 序号 | 示例名称 | 描述 | 难度 |
|------|----------|------|------|
| 01 | LED闪烁 | 学习GPIO输出控制，实现LED灯闪烁 | ⭐ |
| 02 | 按键输入 | 学习GPIO输入检测，实现按键控制 | ⭐ |
| 03 | 串口通信 | 学习UART串口通信基础 | ⭐⭐ |

## 开发环境

- 编译器：GCC (或嵌入式专用工具链如arm-none-eabi-gcc)
- 开发板：可根据实际情况选择（如STM32、Arduino等）
- 操作系统：Linux / Windows / macOS

## 快速开始

1. 克隆项目到本地：
   ```bash
   git clone https://github.com/unknowIfGuestInDream/c-embedded-learn.git
   ```

2. 进入示例目录：
   ```bash
   cd c-embedded-learn/examples/01_led_blink
   ```

3. 编译示例（以模拟器方式）：
   ```bash
   make
   ```

4. 运行示例：
   ```bash
   ./main
   ```

## 烧写指南

详见 [烧写手顺](docs/烧写手顺.md)

## 许可证

本项目采用 MIT 许可证 - 详见 [LICENSE](LICENSE) 文件
