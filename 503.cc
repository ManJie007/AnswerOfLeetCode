#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {

        stack<int> intStack;
        vector<int> res;
        res.resize(nums.size(), -1);

        for (int i = 2 * nums.size() - 1; i >= 0; --i)
        {
            while (!intStack.empty() && nums[i % nums.size()] >= intStack.top())
            {
                intStack.pop();
            }

            if (!intStack.empty())
            {
                res[i % nums.size()] = intStack.top();
            }

            intStack.push(nums[i % nums.size()]);
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 1};

    Solution solution;
    solution.nextGreaterElements(nums);
    return 0;
}
