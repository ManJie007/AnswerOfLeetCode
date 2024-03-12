#include <vector>

using namespace std;

class Solution {
private:
    void backtrack(vector<vector<int>>& res, vector<int> &nums, vector<int> &arrangement, vector<bool> &used) {
        if (arrangement.size() == nums.size()) {
            res.push_back(arrangement);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {

            if (used[i] == true) {
                continue;
            }

            arrangement.push_back(nums[i]);
            used[i] = true;
            backtrack(res, nums, arrangement, used);
            used[i] = false;
            arrangement.pop_back();

        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> arrangement;
        vector<bool> used;
        used.resize(nums.size(), false);

        backtrack(res, nums, arrangement, used);

        return res;

    }
};
