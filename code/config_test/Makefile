CC=g++
TARGET=main
SRCS=${wildcard *.cpp}
OBJS=${SRCS:.cpp=.o}
DEPS=${SRCS:.cpp=.d}
	
.PHONY:all clean

all:${TARGET}

${TARGET}:${OBJS}

clean:
	${RM} ${TARGET} ${OBJS} ${DEPS}

# 自动生成依赖关系
sinclude ${DEPS}

%.d: %.cpp 
	set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :  ]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
