#include "stdio.h"
#include "stdlib.h"

int main() {
  printf("sizeof(_Bool): %d\n", sizeof(_Bool));
  printf("sizeofa(char): %d\n", sizeof(char));
  printf("sizeofa(int): %d\n", sizeof(int));

  _Bool b = -213;
  printf("_Bool b = %d\n", b);
  _Bool b2 = 213;
  printf("_Bool b2 = %d\n", b2);

  return 0;
}
  
