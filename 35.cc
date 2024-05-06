#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int binary_search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) >> 1;

            if (nums[mid] <= target) {
                left = mid + 1;
            }else if (nums[mid] > target) {
                right = mid - 1;
            }
        }

        if (right < 0) {
            return 0;
        }else if (right >= nums.size()) {
            return nums.size();
        }

        return nums[right] == target ? right : right + 1;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        
        return binary_search(nums, target);
    }
};

int main(int argc, char** argv) {

    vector<int> nums {1, 3, 5, 6};
    Solution s;
    cout << s.searchInsert(nums, 5) << endl;
    cout << s.searchInsert(nums, 2) << endl;
    cout << s.searchInsert(nums, 7) << endl;
    return 0;
}
