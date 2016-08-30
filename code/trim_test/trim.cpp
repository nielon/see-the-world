#include <string>
#include <iostream>
using namespace std;

int main(void)
{
  const string str = "2016-08-24 10:47:00";
  string otime = str;
  otime.erase(otime.find(" "), 1);
  otime.erase(otime.find("-"), 1);
  otime.erase(otime.find("-"), 1);
  otime.erase(otime.find(":"), 1);
  otime.erase(otime.find(":"), 1);

  cout << "result is: " << otime << endl;
  return 0;
}
