#include <iostream>
using namespace std;

// 计算总价，可能打折
class Add
{
  public :
  Add(const double factor = 1.0):m_factor(factor) {};
  int operator()(const double price, const unsigned count)
  {
    return (price * count * m_factor);
  };
  private :
    double m_factor;
};

int main(void)
{
  Add add1;
  cout << "add1():" << add1(5, 8) << endl; 
  Add add8(0.8);
  cout << "add8():" << add8(5, 8) << endl; 
  return 0;
}
