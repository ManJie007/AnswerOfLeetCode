#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> need, window;
        for (auto c : s1)
        {
            need[c]++;
        }

        int j = 0, i = 0;
        int valid = 0;
        while (j < s2.size())
        {
            auto c = s2[j];
            window[c]++;
            ++j;

            if (need.find(c) != need.end() && need[c] == window[c])
            {
                valid++;
            }

            //记得是左闭右开区间
            if ((j - i) == s1.size())
            {
                if (valid == need.size())
                {
                    return true;
                }

                // 缩小窗口
                auto d = s2[i];
                window[d]--;
                ++i;

                if (need.find(d) != need.end() && window[d] == need[d] - 1)
                {
                    valid--;
                }
            }
        }

        return false;
    }
};