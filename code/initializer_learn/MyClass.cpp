#include "MyClass.h"
#include <iostream>
using namespace std;

MyClass::MyClass()
{
  cout << "default(1)" << endl;
}
//MyClass::MyClass(std::string name):m_name(name)
//{
  //cout << "implicit(1)" << endl;
//}

MyClass::MyClass(std::string name, bool gender, unsigned age):m_name(name), m_gender(gender), m_age(age)
{

}

MyClass::MyClass(const MyClass& obj)
{
  cout << "copy(2)" << endl;
  m_name = obj.m_name;
  m_gender = obj.m_gender;
  m_age = obj.m_age;
}

void MyClass::Print()
{
  cout << m_name << ";" << m_gender << ":" << m_age << endl;
}

MyClass::~MyClass()
{

}
