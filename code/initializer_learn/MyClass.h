#ifndef MYCLASS_H
#define MYCLASS_H
#include <string>

class MyClass
{
private:
  std::string m_name;
  bool m_gender;
  unsigned m_age;
  

public:
  MyClass();
  //MyClass(std::string name);
  MyClass(std::string name, bool gender = true, unsigned age = 20);
  MyClass(const MyClass& myClass);

  void Print();

  virtual ~MyClass();
};

#endif /* MYCLASS_H */
