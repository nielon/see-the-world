#include "lazySingleton.h"
#include <iostream>

Singleton* Singleton::_instance = 0;
Singleton::Garbo Singleton::_garbo;


Singleton* Singleton::Instance(char ch)
{
  if (_instance == 0) {
    if (ch == 'A') {
      _instance = new SingletonA();
    }
    else if (ch == 'B') {
      _instance = new SingletonB();
    }
    else
    {
      _instance = new Singleton();
    }
  }
  return _instance;
}
