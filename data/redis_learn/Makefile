SRCS=${wildcard *.cpp}
EXES=${SRCS:.cpp=}

CPPFLAGS=-I /home/vimer/tool/src-pkg/msgpack-c/include
CPPFLAGS+=-I /home/vimer/tool/include
LDLIBS=-lhiredis
LDFLAGS=-L /home/vimer/tool/lib
CXX=g++ -std=c++11

.PHONEY:all
all:${EXES}
%: %.cpp
	${CXX} ${CPPFLAGS} $< -o $@ ${LDFLAGS} ${LDLIBS}

.PHONEY:clean
clean:
	${RM} ${EXES}
