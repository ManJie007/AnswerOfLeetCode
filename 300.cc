#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  int lis(vector<int> &nums, vector<int> &memo, int j) {

    for (int i = 0; i < j; ++i) {
        if (nums[i] < nums[j]) {
            memo[j] = max(memo[j], memo[i] + 1);
        }   
    }

    return memo[j];
  }

public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> memo;
    memo.resize(nums.size(), 1);

    int res = 1;

    for (int i = 0; i < nums.size(); ++i) {
      res = max(res, lis(nums, memo, i));
    }

    return res;
  }
};
