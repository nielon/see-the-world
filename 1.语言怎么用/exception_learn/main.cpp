#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "parseNumber.h"

class DivisonByZeroException {};
int main(void)
{
  char *str1="234", *str2="0";
  try {
    int num1 = parseNumber(str1);
    int num2 = parseNumber(str2);
    if( num2 == 0 )
      throw DivisonByZeroException();
    printf("result is %lf\n", (double)num1 / num2);
  }
  catch (Overflow){
    printf("输入整数太大\n");
  }
  catch (NumberParseException){
    printf("输入不是整数\n");
  }
  catch (...)
  {
    printf("更多异常\n");
    throw;
  }
  return 0;
}
