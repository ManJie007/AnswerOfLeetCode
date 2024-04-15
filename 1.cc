#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> value_index_map;

        for (int i = 0; i < nums.size(); i++)
        {
            if (value_index_map.find(nums[i]) != value_index_map.end())
            {
                return {value_index_map[nums[i]], i};
            }

            value_index_map[target - nums[i]] = i;
        }

        return {-1, -1};
    }
};