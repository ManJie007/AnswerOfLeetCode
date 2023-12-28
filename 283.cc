#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                int j = i;
                while (j < nums.size() && nums[j] == 0)
                {
                    ++j;
                }

                if (j == nums.size())
                {
                    //结束
                    return;
                }else
                {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
                
            }
        }
    }
};