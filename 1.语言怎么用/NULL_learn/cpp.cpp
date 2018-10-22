#include <iostream>
using namespace std;

void Foo(int foo)
{
  cout << "Foo(int)" << foo << endl;
}

void Foo(const char *p)
{
  if(p == NULL)
    cout << "Foo(char*)" << endl;
  else
    cout << "Foo(char*)" << p << endl;
}

int main(void)
{
  if (NULL == 0) {
    cout << ("NULL == 0") << endl;
  }
  if (NULL == (void*)0) {
    cout << ("NULL == (void*)0") << endl;
  }
  Foo(1);
  const char *p = "abc";
  Foo(p);
  cout << "-----------" << endl;
  //Foo(NULL);
  Foo(NULL);
  Foo((int)NULL);
  Foo((char*)NULL);
  return 0;
}
