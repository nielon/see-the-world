#ifndef CONTEXT_H
#define CONTEXT_H 

#include "Strategy.h"
class Context
{
public:
  Context () = default;
  ~Context () = default;
  void algorithm(std::vector<int>& nums)
  {
    m_pStrategy->algorithm(nums);
  }
  void setStrategy(Strategy *p)
  {
    m_pStrategy = p;
  }

private:
  /* data */
  Strategy *m_pStrategy;
};

#endif /* CONTEXT_H */
