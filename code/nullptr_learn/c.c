#include <stdlib.h>
#include <stdio.h>

void FooInt(int foo)
{
  printf("FooInt(int) %d\n", foo);
}

void Foo(const char *p)
{
  if(p == NULL)
    printf("Foo(char*)\n");
  else
    printf("Foo(char*) %s\n", p);
}
int main(void)
{
  if (NULL == 0) {
    printf("NULL == 0\n");
  }
  if (NULL == (void*)0) {
    printf("NULL == (void*)0\n");
  }

  Foo(NULL);
  FooInt(NULL);
  return 0;
}
