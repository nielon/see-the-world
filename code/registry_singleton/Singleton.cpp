#include "Singleton.h"
#include <iostream>
Singleton* Singleton::_instance = nullptr;
std::map<std::string, Singleton*> Singleton::_registry;
Singleton* Singleton::Instance()
{
  if ( _instance == nullptr ) {
    const std::string SingletonName = getenv("SINGLETON");
    _instance = Lookup(SingletonName);
  }
  return _instance;
}
void Singleton::Register(const std::string& name, Singleton* singleton)
{
  Singleton* regist = Lookup(name);
  if ( regist == nullptr ) {
    _registry.insert(make_pair(name, singleton));
  }
  else 
  {
    std::cerr << "Already exists! Singleton Name: " << name << std::endl;
  }
}
Singleton* Singleton::Lookup(const std::string name)
{
  auto itor = _registry.find(name);
  if (itor == _registry.end()) {
    return nullptr;
  }
  return itor->second;
}
