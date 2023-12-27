#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        for (size_t i = 0, j = 0; i < nums.size(); ++i)
        {
            if (nums[i] == val)
            {
                j = i;
                while (j < nums.size() && nums[j] == val)
                {
                    ++j;
                }

                if (j < nums.size())
                {
                    nums[i] = nums[j];
                    nums[j] = val;
                }
            }
        }

        int result = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                ++result;
            }
        }

        return result;
    }
};