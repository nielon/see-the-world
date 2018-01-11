CC=gcc

TARGET=main
SRCS=main.c abc.c xyz.c
OBJS=${SRCS:.c=.o}

.PHONY:all clean

all:${TARGET}

${TARGET}:${OBJS}

clean:
	${RM} ${TARGET} ${OBJS}

# 自动生成依赖关系
-include ${SRCS:.c=.d}

%.d: %.c
	set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ : ]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
