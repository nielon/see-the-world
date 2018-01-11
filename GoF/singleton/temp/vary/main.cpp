#include "lazySingleton.h"
#include <iostream>
using namespace std;

int main(void)
{
  // 1
  Singleton* pSingleton = Singleton::Instance('A');
  Singleton* pSingleton2 = Singleton::Instance('B');
  cout << "pSingleton is: " << pSingleton << endl;
  cout << "pSingleton is: " << pSingleton2 << endl;
  //pSingleton->DestoryInstance();
  //Singleton& singleton = *pSingleton;
  //cout << "singleton'addr is: " << &singleton << endl;
  //singleton.Print();
  //Singleton& singleton2(*pSingleton);
  //cout << "singleton2'addr is: " << &singleton2 << endl;

  //
  //MeyersSingleton meyers = MeyersSingleton::Instance();
  //MeyersSingleton meyers2(MeyersSingleton::Instance());
  //cout << "meyers is: " << &meyers << endl;
  //cout << "meyers2 is: " << &meyers2 << endl;
  //MeyersSingleton meyers3 = meyers;
  //cout << "meyers3 is: " << &meyers3 << endl;
  ////MeyersSingleton meyers3(meyers);
  //cout << "meyers1 is: " << &meyers1 << endl;
  //cout << "meyers2 is: " << &meyers2 << endl;
  //cout << "meyers3 is: " << &meyers3 << endl;

  return 0;
}
