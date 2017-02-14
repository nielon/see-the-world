#include "BubbleSort.h"

using namespace std;
void BubbleSort::algorithm(vector<int> & nums)
{
  for (size_t scope = nums.size(); scope > 0; --scope) {
    for (size_t i = 1; i < scope; ++i) {
      if (nums[i-1] > nums[i]) {
        //swap(nums[i-1], nums[i]);
        int tmp = nums[i-1];
        nums[i-1] = nums[i];
        nums[i] = tmp;
      }
    }
  }
}
