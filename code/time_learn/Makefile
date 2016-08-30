SRCS=${wildcard *.cpp}
OBJS=${SRCS:.cpp=.o}
EXES=${SRCS:.cpp=}

CXX= g++ -std=c++11

.PHONEY: all
all: ${EXES}

%: %.o
	${CXX} %< -o %@

%.o: %.cpp
	${CXX} -c %< -o %@

clean:
	${RM} *.o ${EXES}


