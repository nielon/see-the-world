#include <ctime>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
  char str[30];
  time_t tm_value = time(NULL);
  struct tm * tm_local = localtime(&tm_value);
  strftime(str, 30, "%F %H:%M:%S", tm_local);
  cout << str << endl;

  return 0;
}
