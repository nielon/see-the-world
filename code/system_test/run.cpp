#include <iostream>
#include <unistd.h>
using namespace std;
int main(void)
{
  int a = 0;
  while (1)
  {
    cout << "value is: " << ++a << endl;
    sleep(1);
  }
  return 0;
}

