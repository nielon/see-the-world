SRCS=${wildcard *.cpp}
EXES=${SRCS:.cpp=}

.PHONEY:all clean

all:${EXES}

clean:
	${RM} ${EXES}

%: %.cpp
	g++ -std=c++11 $< -o $@ -I /home/vimer/tool/include -L /home/vimer/tool/lib -llog4cplus
