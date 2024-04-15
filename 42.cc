#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> left(height.size(), 0);
        int left_maxheight = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] > left_maxheight)
            {
                left_maxheight = height[i];
            }
            left[i] = max(height[i], left_maxheight);
        }

        vector<int> right(height.size(), 0);
        int right_maxheight = 0;
        for (int i = height.size() - 1; i >= 0; i--)
        {
            if (height[i] > right_maxheight)
            {
                right_maxheight = height[i];
            }
            right[i] = max(height[i], right_maxheight);
        }

        int sum = 0;

        for (size_t i = 0; i < height.size(); i++)
        {
            sum += min(left[i], right[i]) - height[i];
        }

        return sum;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution s;
    s.trap(height);
    return 0;
}
