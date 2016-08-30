SRCS=${wildcard *.cpp}
OBJS=${SRCS:.cpp=.o}
EXES=${SRCS:.cpp=}

.PHONEY: all
all: ${EXES}

LDLIBS=-lmysqlcppconn
LDFLAGS=-L'/home/vimer/tool/mysql-connector-c++/lib'
CPPFLAGS=-I'/home/vimer/tool/mysql-connector-c++/include'

%:%.o
	${CXX} $< -o $@ ${LDFLAGS} ${LDLIBS}

%.o:%.cpp
	${CXX} -c $< -o $@ ${CPPFLAGS}

.PHONEY:clean

clean:
	${RM} ${OBJS} ${EXES}
