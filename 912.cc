#include <vector>

using namespace std;

class Solution {

private:
  vector<int> tmp;

  void mergesort(vector<int> &nums, int l, int r) {
    if (l >= r) {
      return;
    }
    int mid = (l + r) / 2;
    mergesort(nums, l, mid);
    mergesort(nums, mid + 1, r);
    int i = l, j = mid + 1;
    int cnt = 0;
    while (i <= mid && j <= r) {
      if (nums[i] <= nums[j]) {
        tmp[cnt++] = nums[i++];
      } else {
        tmp[cnt++] = nums[j++];
      }
    }
    while (i <= mid) {
      tmp[cnt++] = nums[i++];
    }
    while (j <= r) {
      tmp[cnt++] = nums[j++];
    }
    for (int i = 0; i < r - l + 1; ++i) {
        nums[i+l] = tmp[i];
    }
  }

public:
  vector<int> sortArray(vector<int> &nums) {
    tmp.resize(nums.size(), 0);
    mergesort(nums, 0, nums.size() - 1);
    return nums;
  }
};
