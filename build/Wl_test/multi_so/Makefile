SRCS=${wildcard *.cpp}
TAG=${SRCS:.cpp=}
REALNAME=  lib${TAG}.so.0.0.1
SONAME=    lib${TAG}.so.0
LINKERNAME=lib${TAG}.so


.PHONEY:all

all: ${REALNAME}

${REALNAME}: ${SRCS} 
	g++ $^ -fPIC -shared -Wl,-soname,${SONAME} -o $@ && \
	/sbin/ldconfig -n . && \
	ln -s ${SONAME} ${LINKERNAME}

.PHONEY:clean

clean:
	${RM} ${REALNAME} ${SONAME} ${LINKERNAME}
