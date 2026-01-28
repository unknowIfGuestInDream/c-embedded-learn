# 按键输入示例 Makefile

# 编译器设置
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I../../common

# 目标文件
TARGET = main
SRCS = main.c button.c
OBJS = $(SRCS:.c=.o)

# 默认目标
all: $(TARGET)

# 链接
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 编译
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# 清理
clean:
	rm -f $(OBJS) $(TARGET)

# 运行
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
