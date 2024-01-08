#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        deque<int> queue;
        vector<int> res;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i < k - 1)
            {
                while (!queue.empty() && nums[i] > queue.back())
                {
                    queue.pop_back();
                }
                queue.push_back(nums[i]);
            }
            else
            {
                while (!queue.empty() && nums[i] > queue.back())
                {
                    queue.pop_back();
                }
                queue.push_back(nums[i]);

                res.push_back(queue.front());

                if (nums[i - k + 1] == queue.front())
                {
                    queue.pop_front();
                }
            }
        }

        return res;
    }
};