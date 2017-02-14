#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Strategy.h"
class BubbleSort : public Strategy
{
private:
  

public:
  BubbleSort() = default;
  virtual ~BubbleSort() {};
  virtual void algorithm(std::vector<int>& nums);
};

#endif /* BUBBLESORT_H */
