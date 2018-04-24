#include "config.h"

#ifdef _USE_MY_PRINTLN_
  #include "print/func.h"
#else
  #include <iostream>
  using std::cout;
  using std::endl;
#endif


int main(void)
{
#ifdef _USE_MY_PRINTLN_
  println( "Hello, world.[print by println()]");
#else
  cout << ( "Hello, world.[print by std::cout]") << endl;
#endif
  return 0;
}
