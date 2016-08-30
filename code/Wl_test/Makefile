SRCS=${wildcard *.cpp}
EXES=${SRCS:.cpp=}
TAG=${SRCS:.cpp=}
REALNAME=  lib${TAG}.so.0.0.1
SONAME=    lib${TAG}.so.0
LINKERNAME=lib${TAG}.so

LDLIBS=-ladd
LDLIBS+=-lmulti
LDFLAGS=-L./add_so
LDFLAGS+=-L./multi_so
#LD_RUN_PATH=/home/vimer/code/Wl_test/add_so:/home/vimer/code/Wl_test/multi_so
LD_RUN_PATH1=/home/vimer/code/Wl_test/add_so
LD_RUN_PATH2=/home/vimer/code/Wl_test/multi_so

.PHONEY:all

all: ${EXES}

${EXES}: ${SRCS} 
	g++ $^ -o $@ ${LDFLAGS} ${LDLIBS} -Wl,-rpath -Wl,${LD_RUN_PATH1}:${LD_RUN_PATH2} && \
	./${EXES}

.PHONEY:clean

clean:
	${RM} ${EXES}
