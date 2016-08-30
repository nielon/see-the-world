SRCS=${wildcard *.cpp}
EXES=${SRCS:.cpp=}
CPPFLAGS=-I /home/vimer/tool/src-pkg/msgpack-c/include
CXX=g++ -std=c++11

.PHONEY:all
all:${EXES}
%: %.cpp
	${CXX} ${CPPFLAGS} $< -o $@ 

.PHONEY:clean
clean:
	${RM} ${EXES}
