#include <stdio.h>
#include <stdlib.h>

typedef void (*Cout)(const char*);

void Print(const char* str)
{
  printf("Print() without new line: %s", str);
}
void Println(const char* str)
{
  printf("Println(): %s\n", str);
}

int main(void)
{
  Cout cout = Print;
  (*cout)("abc");
  printf("------------------\n");
  cout = Println;
  cout("niel");
  printf("------------------\n");
  return 0;
}
