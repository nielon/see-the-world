#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "Strategy.h"
class SelectionSort : public Strategy
{
private:
  

public:
  SelectionSort() = default;
  virtual ~SelectionSort() {};
  virtual void algorithm(std::vector<int> &nums);
};

#endif /* SELECTIONSORT_H */
