#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "Strategy.h"
class InsertionSort : public Strategy
{
private:
  

public:
  InsertionSort() = default;
  virtual ~InsertionSort() {};
  virtual void algorithm(std::vector<int>&);
};

#endif /* INSERTIONSORT_H */
