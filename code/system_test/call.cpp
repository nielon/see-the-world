#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

int mySystem(const string& str);
int main(void)
{
  mySystem("./run");
  cout << "END" << endl;
  return 0;
}
int mySystem(const string& str)
{
  cout << "=========" << endl;
  cout << "calls system(\"" << str << "\"): " << endl;
  int status = system(str.c_str());
  cout << "status is:" << status << endl;
  if (status != -1)
    cout << "WEXITSTATUS(status) is:" << WEXITSTATUS(status) << endl;
  if (WIFEXITED(status))
    cout << "\"" << str << "\" finished! And return(exit) " <<  WEXITSTATUS(status) << endl;
  return status;
}
