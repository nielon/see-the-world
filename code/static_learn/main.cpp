#include <iostream>

using namespace std;

int g_value;

class myClass
{
  private:
    static int m_private;
    int m_id;
  public:
    static int m_public;
    int print();
};

int myClass::print()
{
  cout << m_id << endl;
  cout << m_public << endl;
  cout << m_private << endl;
  return 0;
}

int myClass::m_private = 2;
int myClass::m_public = 2;
int main(void)
{
  myClass::m_public = 3;
  //myClass::m_private = 3;
  myClass myclass;
  myclass.print();

  return 0;
}
