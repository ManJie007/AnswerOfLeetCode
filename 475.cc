#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lower_bound_pos(const vector<int> &heaters, int house_pos)
    {
        int left = 0, right = heaters.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (heaters[mid] == house_pos)
            {
                return mid;
            }
            else if (heaters[mid] > house_pos)
            {
                right = mid - 1;
            }
            else if (heaters[mid] < house_pos)
            {
                left = mid + 1;
            }
        }

        if (left == 0 && heaters[left] != house_pos)
        {
            return -1;
        }

        return left;
    }

    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(heaters.begin(), heaters.end());

        vector<int> minRadius(houses.size(), INT_MAX);

        for (size_t i = 0; i < houses.size(); i++)
        {
            int pos = lower_bound_pos(heaters, houses[i]);
            if (pos >= 0 && pos < heaters.size() && heaters[pos] == houses[i])
            {
                minRadius[i] = 0;
            }
            else if (pos >= 0 && pos < heaters.size() && heaters[pos] > houses[i])
            {

                // 如果iter指向开头元素
                if (pos == 0)
                {
                    minRadius[i] = abs(heaters[0] - houses[i]);
                }
                else
                {
                    minRadius[i] = min(abs(heaters[pos] - houses[i]), abs(heaters[pos - 1] - houses[i]));
                }
            }
            else if (pos == -1)
            {

                minRadius[i] = abs(heaters[0] - houses[i]);
            }
            else if (pos == heaters.size())
            {
                minRadius[i] = abs(heaters[heaters.size() - 1] - houses[i]);
            }
        }

        return *max_element(minRadius.begin(), minRadius.end());
    }
};

int main(int argc, char const *argv[])
{
    vector<int> houses{1, 2, 3, 5, 15};
    vector<int> heaters{2, 30};
    Solution s;
    cout << s.findRadius(houses, heaters);
    return 0;
}
