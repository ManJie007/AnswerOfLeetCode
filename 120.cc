#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
        if (j - 1 < 0) {
          dp[i][j] = dp[i - 1][j] + triangle[i][j];
        } else if (j == i) {
          dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
        } else {
          dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
      }
    }

    for (auto &vec : dp) {
      for(int i : vec) {
        cout << i << " ";
      } 
      cout << endl;
    }

    auto &vec = dp[dp.size() - 1];
    return *min_element(vec.begin(), vec.end());
  }
};
