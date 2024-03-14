#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  int dp(string text1, int i, string text2, int j, vector<vector<int>> &memo) {

    // base case
    if (i == -1 || j == -1)
      return 0;

    if (memo[i][j] != -1) {
      return memo[i][j];
    }

    if (text1[i] == text2[j]) {
      memo[i][j] = dp(text1, i - 1, text2, j - 1, memo) + 1;
    } else {
      memo[i][j] = max(dp(text1, i - 1, text2, j, memo),
                       dp(text1, i, text2, j - 1, memo));
    }

    return memo[i][j];
  }

public:
  int longestCommonSubsequence(string text1, string text2) {
    
      vector<vector<int>> memo;
      memo.resize(text1.size());

     for (auto &vec : memo) {
         vec.resize(text2.size(), -1);
     }

     return dp(text1, text1.size() - 1, text2, text2.size() - 1, memo);
  }
};
