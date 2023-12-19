#include <vector>

using namespace std;

class NumArray {

private:
    vector<int> preSum;

public:
    NumArray(vector<int>& nums) {
        preSum.resize(nums.size() + 1, 0);
        for (size_t i = 0; i < nums.size(); i++)
        {
            preSum[i + 1] = preSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */