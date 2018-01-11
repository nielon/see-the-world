#include <iostream>
#include <utility>
using namespace std;
void swap(string& a, string& b)
{
  a = std::move(b);
}
void swap(int& a, int& b)
{
  a = std::move(b);
}
int main(void)
{
  string nie = "nie";
  string wei = "wei";
  swap(nie, wei);
  cout << "nie = " << nie << endl;
  cout << "wei = " << wei << endl;
  // int
  int a = 1;
  int b = 2;
  swap(a, b);
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  return 0;
}
