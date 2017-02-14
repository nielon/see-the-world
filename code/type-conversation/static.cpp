
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
  int *pI = new int(5);
  void *pV = pI;

  int *pD = reinterpret_cast<int*>(pV);

  cout << "pI is: " << pI <<
   " And pV is: " << pV <<
   " And pD is: " << pD << endl; 

  cout << (*pD) << endl;
  return 0;
}
