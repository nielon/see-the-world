#include "SelectionSort.h"

using namespace std;
void SelectionSort::algorithm(std::vector<int> &nums)
{
  for (size_t scope = nums.size(); scope > 0; --scope) {
    size_t max = 0;
    for (size_t i = 0; i < scope; ++i) {
      if (nums[i] > nums[max]) {
	max = i;
      }
    }
    if (max != scope-1) {
      int tmp = nums[max];
      nums[max] = nums[scope-1];
      nums[scope-1] = tmp;
    }
  }

}
