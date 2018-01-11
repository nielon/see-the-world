#include <iostream>
#include <thread>
using namespace std;
void tfunc(string& str)
{
  for (int i = 0; i < 10; ++i) {
    str += "a";
  }
}

struct func
{
  int& i;
  func(int& i_):i(i_){};
  void operator() ()
  {
    for(unsigned j=0;j<100000;++j)
    {
      i = j + 5;
    }
  }
};
int main(void)
{
  int some_local_state = 0;
  func my_func(some_local_state);
  std::thread my_thread(my_func);
  my_thread.join();
  cout << "some_local_state is: " << some_local_state << endl;
  //
  string str = "h";
  std::thread my_thread2(tfunc, (some_local_state));
  my_thread2.join();
  cout << "str is: " << str << endl;
  return 0;
}
