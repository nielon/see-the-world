#include "Context.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include <iostream>

using namespace std;
void Print(vector<int>& nums)
{
  for (size_t i = 0; i < nums.size(); ++i) {
    cout << nums[i] << "  ";
  }
  cout << endl;
}
int main(void)
{

  vector<int> nums = {6,4,7,5,3,9,0,2};
  Print(nums);

  Context context;
  //context.setStrategy(new BubbleSort());
  //context.setStrategy(new InsertionSort());
  context.setStrategy(new SelectionSort());
  context.algorithm(nums);
  Print(nums);
  return 0;
}
