#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        for (auto iter = nums.begin(); iter != nums.end();)
        {
            auto iter2 = iter;
            int count = 0;
            while (iter2 != nums.end() && *iter == *iter2)
            {
                ++count;
                ++iter2;
            }

            if (count > 1)
            {
                iter = nums.erase(++iter, iter2);
            }
            else
            {
                ++iter;
            }
        }

        return nums.size();
    }
};