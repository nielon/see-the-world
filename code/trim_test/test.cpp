#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;
int main(void)
{
  std::string str = "   niel loves liyw   !  ";
  std::cout << "str: |" << str << "|" << std::endl;
  // trim all spaces: remove_if
  auto itor = remove_if(str.begin(), str.end(), std::isspace);
  std::cout << "str: |" << str << "|" << std::endl;
  str.erase(itor, str.end());
  std::cout << "str: |" << str << "|" << std::endl;

  return 0;
}
