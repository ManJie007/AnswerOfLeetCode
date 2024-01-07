#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        stack<int> intStack;
        vector<int> res;
        res.resize(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; --i)
        {
            while (!intStack.empty() && temperatures[i] >= temperatures[intStack.top()])
            {
                intStack.pop();
            }

            if (!intStack.empty())
            {
                res[i] = intStack.top() - i;
            }
            else
            {
                res[i] = 0;
            }

            intStack.push(i);
        }

        return res;
    }
};