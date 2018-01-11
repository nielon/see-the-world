#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
/*#include <sys/types.h>*/
#include <netinet/in.h>
/*#include <arpa/inet.h>*/
#include <unistd.h>
/*#include <fcntl.h>*/
/*#include <sys/shm.h>*/
#include <errno.h>

int main(void)
{
  int listenfd, connfd;
  struct sockaddr_in servaddr;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd == -1) {
    printf("create socket error:%s(errno %d)\n", strerror(errno), errno);
    exit (0);
  }
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(6666);

  if ((bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) == -1) {
    printf("bind socket error:%s(errno %d)\n", strerror(errno), errno);
    exit (0);
  }
  if (listen (listenfd, 10) == -1) {
    printf("listen socket error:%s(errno %d)\n", strerror(errno), errno);
    exit (0);
  }
  printf("===========waiting for client's request===============\n");
  const unsigned MAXLINE = 4096;
  char buff[MAXLINE];
  int n = 0;
  while (1) {
    if ((connfd = accept(listenfd, (struct sockaddr*)NULL, NULL )) == -1) {
      printf("accept socket error:%s(errno %d)\n", strerror(errno), errno);
      exit (0);
    }
    n = recv(connfd, buff, MAXLINE, 0);
    buff[n] = '\0';
    printf("recv msg from client: %s\n", buff);
    close(connfd);
  }
  close(listenfd);
  return 0;
}
