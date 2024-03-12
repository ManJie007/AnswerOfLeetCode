#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        dp.resize(amount + 1, amount + 1);
        
        //base case
        dp[0] =  0;

        for (int i = 0; i <= amount; ++i) {
            for (auto coin : coins){
                if ( i - coin < 0) {
                    continue;
                }
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }

        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
