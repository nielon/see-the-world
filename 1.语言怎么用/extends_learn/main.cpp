#include <iostream>
#include <string>
using namespace std;

class Base
{
  public:
    void func()
    {
      cout << "func() in Base" << endl;
    }

    virtual void test()
    {
      cout << "test() in Base" << endl;
    }
};


class Derived: Base
{
  public:
    void func()
    {
      cout << "func() in Derived" << endl;
    }

    virtual void test()
    {
      cout << "test() in Derived" << endl;
    }
};

int main(void)
{
  {
    cout << "test1" << endl;
    Base *p = (Base *)new Derived();
    p->func();
    p->test();
  }
  {
    cout << "test2" << endl;
    Base *p = nullptr;
    p->func();
    //p->test();
  }
  {
    cout << "test3" << endl;
    Derived *pD = new Derived();
    pD->func();
    pD->test();
    Base *pB = (Base *)pD;
    pB->func();
    pB->test();
    
  }
  return 0;
}
