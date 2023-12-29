#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {

        unordered_map<char, int> need, window;
        for (auto c : t)
        {
            need[c]++;
        }

        // 左闭右开区间
        int i = 0, j = 0;
        int valid = 0;
        int start = -1, len = INT32_MAX;
        while (j < s.size())
        {
            auto c = s[j];
            window[c]++;
            ++j;
            if (need.find(c) != need.end() && need[c] == window[c])
            {
                valid++;
            }
            

            while (i < j && valid == need.size())
            {
                //更新结果
                if (j - i < len)
                {
                    len = j - i;
                    start = i;
                }
                
                
                auto d = s[i];
                window[d]--;
                ++i;

                if (need.find(d) != need.end() && window[d] == need[d] - 1)
                {
                    valid--;
                }
                
            }
        }

        //左闭右开区间
        return start == -1 ? "" : s.substr(start, len);
    }
};