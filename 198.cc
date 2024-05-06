#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int size = nums.size() >= 3 ? nums.size() : 3;
        vector<int> vals(size, 0);

        vals[0] = nums.size() >= 1 ? nums[0] : 0;
        vals[1] = nums.size() >= 2? max(nums[0], nums[1]) : 0;

        for(int i = 2; i < nums.size(); ++i) {
            vals[i] = max(vals[i - 2] + nums[i], vals[i - 1]);
        }
        
        return vals[nums.size() - 1 >= 0 ? nums.size() - 1 : 0];
    }
};

int main(int argc, char** argv) {

    vector<int> nums {2, 1};
    Solution s;
    cout << s.rob(nums);

    return 0;
}
