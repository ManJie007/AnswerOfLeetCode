#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

// class Solution {
// private:
//   int dp(vector<int> &nums, vector<int> &memo, int j) {
//
//     memo[j] = max(memo[j - 1] + nums[j], nums[j]);
//
//     return memo[j];
//   }
//
// public:
//   int maxSubArray(vector<int> &nums) {
//
//     vector<int> memo(nums);
//
//     int res = memo[0];
//     for (int i = 1; i < nums.size(); ++i) {
//       res = max(res, dp(nums, memo, i));
//     }
//
//     return res;
//   }
// };

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    vector<int> dp(nums.size() + 1, 0);

    for (int i = 1; i <= nums.size(); ++i) {
      dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
    }

    return *max_element(dp.begin() + 1, dp.end());
  }
};
