#include "MyString.h"
int main ()
{
  string s0 ("Initial string");

  // constructors used in the same order as described above:
  MyString s1;
  //MyString s1a();
  MyString s1b{};
  MyString s1c = {};
  //s1c = (10, 'x');
  s1c = {10, 'x'};
  cout << "s1c = " << s1c << endl;
  s1c = {42, 'x'};
  cout << "s1c = " << s1c << endl;
  //s1c = ("abc", 2);
  s1c = {"abc", 2};
  cout << "s1c = " << s1c << endl;
  //s1c = (s0.begin(), s0.begin()+7);
  s1c = {s0.begin(), s0.begin()+7};
  cout << "s1c = " << s1c << endl;
  cout << "**************" << endl;
  MyString s2 (s0);
  MyString s2a {s0};
  MyString s2b = s0;
  cout << "**************" << endl;
  MyString s3 (s0, 8, 3);
  //MyString s3b = (s0, 8, 3);
  MyString s3a {s0, 8, 3};
  MyString s3d = {s0, 8, 3};
  cout << "**************" << endl;
  MyString s4 ("A character sequence");
  MyString s4b = ("A character sequence");
  MyString s4a {"A character sequence"};
  MyString s4d = {"A character sequence"};
  cout << "**************" << endl;
  MyString s5 ("Another character sequence", 12);
  //MyString s5b = ("Another character sequence", 12);
  MyString s5a {"Another character sequence", 12};
  MyString s5d = {"Another character sequence", 12};
  cout << "**************" << endl;
  MyString s6a (10, 'x');
  MyString s6x ('*', 'x');
  cout << "s6x = " << s6x << endl;
  //MyString s6e = (10, 'x');
  MyString s6c {10, 'x'};
  MyString s6f = {10, 'x'};
  MyString s6b (10, 42);      // 42 is the ASCII code for '*'
  MyString s6d {10, 42};
  MyString s6g = {10, 42};
  cout << "**************" << endl;
  MyString s7 (s0.begin(), s0.begin()+7);
  cout << "**************" << endl;
  MyString s8 {'n','i','e','l'};

  std::cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
  std::cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
  std::cout << "\ns6b: " << s6b << "\ns7: " << s7 << '\n';
  return 0;

}
