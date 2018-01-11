#include <iostream>
#include "Person.h"
using namespace std;

int Person::count = 0;

typedef void (*FuncPtr)();
int main(void)
{
  cout << "sizeof(Person) is:" << sizeof(Person) << endl;
  Person person;
  //Person nonexit();
  Person niel{};
  Person liyw{10, 20};
  int** address = reinterpret_cast<int** >(&liyw);
  FuncPtr* funcPtr = reinterpret_cast<FuncPtr* >(*address);
  for(int i=0;i<3;++i)
  {
    (*funcPtr)();
    ++funcPtr;
  }
  //int* p = reinterpret_cast<int *>(&liyw);
  //int count = sizeof(Person)/sizeof(int);
  //for(int i=0;i< count; ++i,++p)
  //{
    //cout << (*p) << endl;
  //}
  return 0;
}
