#include <vector>

using namespace std;

class Solution
{
private:
    int left_bound(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                right = mid - 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
        }

        if (left < 0 || left >= nums.size())
        {
            return -1;
        }
        return nums[left] == target ? left : -1;
        
    }
    int right_bound(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
        }

        if (right < 0 || right >= nums.size())
        {
            return -1;
        }
        return nums[right] == target ? right : -1;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        return {left_bound(nums, target), right_bound(nums, target)};
    }
};