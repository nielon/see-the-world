#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
class Strategy
{
private:
  

public:
  Strategy() = default;
  virtual ~Strategy() {};
  virtual void algorithm(std::vector<int>&) = 0;
};

#endif /* STRATEGY_H */
