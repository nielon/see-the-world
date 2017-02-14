#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class MyClass
{
  public:
    MyClass(const string& str):m_str(str)
    {
      cout << "constructor:" << m_str << endl; 
    }
    MyClass(const MyClass& my):m_str(my.m_str)
    {
      cout << "copy constructor:" << m_str << endl;
    }
    MyClass& operator=(const MyClass& obj) 
    {
      m_str = obj.m_str;
      return *this;
    }
    MyClass& operator+=(const MyClass& obj)
    {
      m_str += obj.m_str;
      return *this;
    }
    void Print()
    {
      cout << "content is:" << m_str << endl;
    }
    void SetContent(const string& str)
    {
      m_str = str;
    }
  private:
    string m_str;
};

//void operator<< (ostream oss, const MyClass& obj)
//{
  //obj.Print();
//}

int main(void)
{
  MyClass obj("hello");
  MyClass obj2(obj);
  MyClass obj3 = MyClass("world");
  MyClass obj4 = obj3;
  cout << "----------" << endl;
  obj4 = obj3.operator=(obj2);
  (obj4 = obj3).SetContent("hah");
  obj3.Print();
  obj4.Print();
  obj += obj4 += obj3;
  obj.Print();


  cout << "----------" << endl;
  string str1("a");
  string str2("b");
  string str3("c");
  str3 += str1 += str2;
  cout << str3 << endl;


  return 0;
}
