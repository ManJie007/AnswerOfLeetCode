#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        string res;
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            return to_string(x) + to_string(y) > to_string(y) + to_string(x);
        });
        for (size_t i = 0; i < nums.size(); i++)
        {
            res += to_string(nums[i]);
        }

        return res;
    }
};