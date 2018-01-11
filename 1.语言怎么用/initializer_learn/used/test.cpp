#include <iostream>
using namespace std;
// 默认值是什么

int global_var1;
int global_var2 = 100;
int main(void)
{
  int inner_var1;
  int inner_var2 = 12;
  int inner_var = inner_var1;
  cout << "global_var1: " << global_var1 << endl;
  cout << "global_var2: " << global_var2 << endl;
  cout << "inner_var1: " << inner_var1 << endl;
  cout << "inner_var2: " << inner_var2 << endl;
  cout << "inner_var: " << inner_var << endl;
  return 0;

}
