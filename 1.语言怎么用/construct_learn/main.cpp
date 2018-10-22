#include "MyClass.h"
using std::string;

int main(void)
{
  MyClass obj = string("niel");
  obj.Print();
  //MyClass obj;
  //MyClass obj();
  //obj.Print();

/* MyClass obj2 = obj;
  //MyClass obj2(obj);
  obj2.Print();

  MyClass obj3("niel", true, 26);
  obj3.Print();

  MyClass *p = new MyClass;
  p->Print();

  MyClass *p2 = new MyClass();
  p2->Print();

  MyClass *p3 = new MyClass(obj3);
  p3->Print();*/
  return 0;
}
