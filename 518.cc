#include <vector>

using namespace std;

class Solution {
private: 
    //返回前i中零钱，金额为j的时候有多少中组合数
    int dp(vector<int> &coins, int i, int j, vector<vector<int>> &memo) {
        //base case
        if (i < 0) return 0;
        if (j <= 0) return 1;

        //avoid useless calculus
        if (memo[i][j] != -1) return memo[i][j];

        if (j - coins[i] < 0) {
            memo[i][j] = dp(coins, i - 1, j, memo);
        }else {
            memo[i][j] = dp(coins, i - 1, j, memo) + dp(coins, i, j - coins[i], memo);
        }

        return memo[i][j];
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo;

        memo.resize(coins.size());

        for (auto &vec : memo) {
            vec.resize(amount + 1, -1);
        }

        return dp(coins, coins.size() - 1, amount, memo);
    }
};
