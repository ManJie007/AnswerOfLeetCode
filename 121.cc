#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
 //   int maxProfit(vector<int>& prices) {
 //
 //       int res = 0;
 //
 //       for(int i = 0; i < prices.size(); ++i) {
 //           for(int j = 0; j < i; ++j) {
 //               res = max(prices[i] - prices[j], res);
 //           }
 //       }
 //
 //       return res;
 //   }
    int maxProfit(vector<int>& prices) {

        int res = 0, minprice = INT_MAX;

        for(int i = 0; i < prices.size(); ++i) {
            res = max(res, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }

        return res;
    }
};

int main(int argc, char** argv) {

    vector<int> prices {7, 1, 5, 3, 6, 4};
    Solution s;
    cout << s.maxProfit(prices);
    return 0;
}
