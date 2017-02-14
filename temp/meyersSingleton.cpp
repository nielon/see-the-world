#include "meyersSingleton.h"
#include <iostream>

MeyersSingleton::MeyersSingleton()
{
  std::cout << "meyersSingleton..." << std::endl;
}

MeyersSingleton& MeyersSingleton::Instance()
{
  static MeyersSingleton _instance;
  return _instance;
}
