#include <chrono>
#include <iostream>

int main(void)
{
  std::chrono::duration<int> two(2);
  std::chrono::duration<double, std::ratio<60,1>> thirty(0.5);

  auto ad = two + thirty;
  std::cout << sizeof(decltype(ad)::rep) << std::endl;
  std::cout << ad.count() << std::endl;
  return 0;
}
