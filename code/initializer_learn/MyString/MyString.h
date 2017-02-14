#include <string>
#include <iostream>

using namespace std;
class MyString : public string
{
public:
  // default (1)
  MyString():string()
  {
    cout << "default (1)" << endl;
  }
  // copy (2)
  MyString (const string& str) : string(str)
  {
    cout << "copy (2)" << endl;
  }
  // substring (3)
  MyString (const string& str, size_t pos, size_t len = npos): string(str, pos, len)
  {
    cout << "substring (3)" << endl;
  }
  // from c-string (4)
  MyString(const char* s):string(s)
  {
    cout << "from c-string (4)" << endl;
  }
  // from buffer (5)
  MyString(const char* s, size_t n):string(s, n)
  {
    cout << "from buffer (5)" << endl;
  }
  // fill (6)
  MyString(size_t n, char c):string(n, c)
  {
    cout << "fill (6)" << endl;
  }
  // range (7)
  template <class InputIterator>
    MyString(InputIterator first, InputIterator last): string(first, last)
  {
    cout << "range (7)" << endl;
  }
  // initializer list (8)
  MyString(initializer_list<char> il): string(il)
  {
    cout << "initializer list (8)" << endl;
  }
  // move (9)
  MyString(string&& str) noexcept;


};
