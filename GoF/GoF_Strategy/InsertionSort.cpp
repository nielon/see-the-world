#include "InsertionSort.h"

using namespace std;
void InsertionSort::algorithm(vector<int> & nums)
{
  for (size_t scope = 1; scope < nums.size(); ++scope) {
    for (size_t i = 0; i < scope; ++i) {
      if (nums[i] > nums[scope]) {
	int tmp = nums[i];
	nums[i] = nums[scope];
	nums[scope] = tmp;
      }
    }
  }
}
