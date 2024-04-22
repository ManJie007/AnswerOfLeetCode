#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
                int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1};
    Solution s;
    cout << s.canJump(nums);

    return 0;
}