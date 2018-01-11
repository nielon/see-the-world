#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;
int main(void)
{
  while(1) {
    system("date");
    cout << endl;
    sleep(2);
  }
  return 0;
}
