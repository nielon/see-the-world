
.PHONY:all
all:main

CPPFLAGS=-Wall -std=c++11 -ggdb
LDLIBS=-pthread

main:main.o
	${CXX} $^ -o $@ ${LDLIBS}

main.o:main.cpp
	${CXX} -c $^ -o $@ ${CPPFLAGS}

.PHONY:clean
clean:
	${RM} main main.o
