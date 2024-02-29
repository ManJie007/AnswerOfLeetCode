#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Solution {
private:
  int partition(vector<int> &nums, int l, int r) {
    int p = nums[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; ++j) {
      if (nums[j] <= p) {
        i++;
        swap(nums[i], nums[j]);
      }
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
  }

  void quicksort(vector<int> &nums, int l, int r) {
    if (l >= r)
      return;

    int i = rand() % (r - l + 1) + l;
    swap(nums[i], nums[r]);
    int pos = partition(nums, l, r);
    quicksort(nums, l, pos - 1);
    quicksort(nums, pos + 1, r);
  }

public:
  vector<int> sortArray(vector<int> &nums) {
    srand(time(NULL));
    quicksort(nums, 0, nums.size() - 1);
    return nums;
  }
};
