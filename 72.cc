#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  int dp(string &word1, int i, string &word2, int j,
         vector<vector<int>> &memo) {
    // base case
    if (i == -1)
      return j + 1;

    if (j == -1)
      return i + 1;

    if (memo[i][j] != -1)
      return memo[i][j];

    if (word1[i] == word2[j]) {
      memo[i][j] = dp(word1, i - 1, word2, j - 1, memo);
    } else {
      memo[i][j] = min(dp(word1, i, word2, j - 1, memo) + 1,
                       min(dp(word1, i - 1, word2, j, memo) + 1,
                           dp(word1, i - 1, word2, j - 1, memo) + 1));
    }

    return memo[i][j];
  }

public:
  int minDistance(string word1, string word2) {
    vector<vector<int>> memo;
    memo.resize(word1.size());

    for (auto &vec : memo) {
      vec.resize(word2.size(), -1);
    }

    return dp(word1, word1.size() - 1, word2, word2.size() - 1, memo);
  }
};
