#include <stdlib.h>
#include <stdio.h>
int main(void)
{
  {
    /*int num = double(3.14);*/
    int num2 = (double)3.14;
  }
  int num = 7;
  int num1 = 3;
  {
    double dou = num / num1;
    printf("%lf\n", dou);
  }
  {
    /*double dou = double(num / num1);*/
    /*printf("%lf\n", dou);*/
  }
  {
    double dou = (double)num / num1;
    printf("%lf\n", dou);
  }
  {
    double dou = ((double)num) / num1;
    printf("%lf\n", dou);
  }
  {
    /*double dou = num / (double(num1));*/
    double dou = num / ((double)(num1));
    printf("%lf\n", dou);
  }
  return 0;
}
