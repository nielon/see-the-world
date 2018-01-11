#include <iostream>

using namespace std;

class MyClass
{
  public:
    MyClass(int n)
    {
      cout << n << endl;
      cout << this << endl;
    };
    MyClass()
    {
      MyClass(0);
      cout << this << endl;
    };

};

int main(void)
{
  MyClass myClass;
  return 0;
}
