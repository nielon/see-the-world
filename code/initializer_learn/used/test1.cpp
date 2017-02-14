#include <iostream>
using namespace std;
// 最常见的形式

int inner_var3;
int main(void)
{
  int inner_var1;
  cout << "inner_var1: " << inner_var1 << endl;
  inner_var1 = 11;

  int inner_var2 = 12;
  cout << "inner_var2: " << inner_var2 << endl;
  inner_var2 = 13;

  extern int inner_var3;
  //cout << "inner_var3: " << inner_var3 << endl;
  inner_var3 = 14;
  cout << "inner_var3: " << inner_var3 << endl;
  return 0;

}
