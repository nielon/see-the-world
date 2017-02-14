# 可执行文件
TARGET=test
# 扫描源文件
SRCS=test.c \
     test-add/test-add.c \
     test-sub/test-sub.c
# 依赖目标
OBJS=${SRCS:.c=.o}

# 指定编译器和选项
CC=gcc
CFLAGS=-Wall -std=c99
CPPFLAGS=-I'./test-add' -I'./test-sub'

.PHONEY:all clean

all:${TARGET}

# 目标文件生成可执行文件
${TARGET}:${OBJS}
	${CC} $^ -o $@

# 使用其隐含规则生成目标文件

clean:
	${RM} ${TARGET} ${OBJS}
