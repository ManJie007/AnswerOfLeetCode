#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> left(nums.size(), 0), right(nums.size(), 0);

    for (int i = 1; i < nums.size(); ++i) {
      if (i == 1) {
        left[i] = nums[i - 1];
      } else {
        left[i] = left[i - 1] * nums[i - 1];
      }
    }

    for (int i = nums.size() - 2; i >= 0; --i) {
      if (i == nums.size() - 2) {
        right[i] = nums[i + 1];
      } else {
        right[i] = right[i + 1] * nums[i + 1];
      }
    }

    vector<int> res(nums.size(), 0);

    for (int i = 0; i < nums.size(); ++i) {
      if (i == 0) {
        res[i] = right[i];
      } else if (i == nums.size() - 1) {
        res[i] = left[i];
      } else {
        res[i] = left[i] * right[i];
      }
    }

    return res;
  }
};

int main(int argc, char** argv) {
    vector<int> nums{1, 2, 3, 4};
    Solution s;
    s.productExceptSelf(nums);
    return 0;
}
