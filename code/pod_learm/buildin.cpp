#include <iostream>

using std::cout ;
using std::endl;

class MyClass
{

};

int main(void)
{
  int *p = new int ;
  cout << *p << endl;

  int *q = new int();
  cout << *q << endl;

  MyClass func();
  MyClass myClass;
  // TODO 这是返回 MyClass 类型的函数？还是调用缺省构造函数定义的对象？
  return 0;
}
