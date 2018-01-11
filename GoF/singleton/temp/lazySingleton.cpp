#include "lazySingleton.h"
#include <iostream>

Singleton* Singleton::_instance = 0;
Singleton::Garbo Singleton::_garbo;

Singleton::Singleton():m_value(24)
{
  std::cout << "singleton..." << std::endl;
}

Singleton* Singleton::Instance()
{
  if (_instance == 0) {
    _instance = new Singleton();
  }
  return _instance;
}

void Singleton::DestoryInstance()
{
  if (_instance != 0) {
    delete _instance;
    _instance = 0;
  }
}

