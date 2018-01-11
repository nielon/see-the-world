CXX=g++ -std=c++11
SRCS=${wildcard *.cpp}
OBJS=${SRCS:.cpp=.o}
EXES=${SRCS:.cpp=}

.PHONEY: all
#all: ${EXES}
all: main

LDLIBS=-lmysqlcppconn
LDFLAGS=-L'/home/vimer/tool/mysql-connector-c++/lib'
CPPFLAGS=-I'/home/vimer/tool/mysql-connector-c++/include' -I./

main:main.o MyUtility.o
	${CXX} $^ -o $@ ${LDFLAGS} ${LDLIBS}

%.o:%.cpp
	${CXX} -c $< -o $@ ${CPPFLAGS}

.PHONEY:clean

clean:
	${RM} ${OBJS} ${EXES}
