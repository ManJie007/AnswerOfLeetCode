#include <vector>

using namespace std;

class Solution {

public:
    int climbStairs(int n) {

        int size = n >= 3 ? n : 3;
        vector<int> nums(size + 1, 0);

        nums[1] = 1;
        nums[2] = 2;

        for(int i = 3; i <= n; ++i) {
            nums[i] = nums[i - 1] + nums[i - 2];
        }
        
        
        return nums[n];
    }
};
