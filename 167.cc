#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result;

        int i = 0, j = 1;
        while (numbers[j] < target/2)
        {
            ++j;
        }
        
        while (j < numbers.size())
        {
            i = 0;
            while (i < j)
            {
                if (numbers[i] + numbers[j] == target)
                {
                    result.push_back(i + 1);
                    result.push_back(j + 1);
                    return result;
                }

                ++i;
            }
            ++j;
        }

        return result;
    }
};