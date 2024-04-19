#include <vector>
#include <climits>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        int minCount = wall.size();
        map<int, int> index_count_map;

        for (auto &&vec : wall)
        {
            for (size_t i = 0; i < vec.size() && vec.size() > 1; i++)
            {
                if (i == 0)
                {
                    index_count_map[vec[i]]++;
                }
                else if (i < vec.size() - 1)
                {
                    vec[i] += vec[i - 1];
                    index_count_map[vec[i]]++;
                }
            }
        }

        for (auto iter = index_count_map.begin(); iter != index_count_map.end(); iter++)
        {
            minCount = min(minCount, static_cast<int>(wall.size() - iter->second));
        }

        return minCount;
    }
};

int main(int argc, char const *argv[])
{
    // vector<vector<int>> wall{{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};
    vector<vector<int>> wall{{1}, {1}, {1}};
    Solution s;
    s.leastBricks(wall);
    return 0;
}