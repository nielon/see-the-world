#include <string>
#include <iostream>
using namespace std;

class Base
{
  public:
    virtual void Print(){}
};

class Derived : public Base
{
  public:
    Derived():Base(), m_str("Derived") {}
    void foo() { cout << "foo() " << m_str << endl; }
  private:
    string m_str;
};

void Print_dynamic(Base* pb)
{
  cout << "Before cast, address is: " << pb << endl;
  Derived *pd = dynamic_cast<Derived*>(pb);
  cout << "After dynamic_cast, address is: " << pd << endl;
  if (pd)
    pd->foo();
}
void Print_static(Base* pb)
{
  cout << "Before cast, address is: " << pb << endl;
  Derived *pd = static_cast<Derived*>(pb);
  cout << "After static_cast, address is: " << pd << endl;
  if(pd)
    pd->foo();
}

int main(void)
{
    Base *pb1 = new Derived();
    Base *pb2 = new Base();
    Print_dynamic(pb1);
    Print_dynamic(pb2);

    cout << endl << "---------" << endl;

    Print_static(pb1);
    Print_static(pb2);

  return 0;
}
