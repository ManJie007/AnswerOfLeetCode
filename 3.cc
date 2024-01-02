#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
private:
    bool checkMap(const unordered_map<char, int> &map)
    {
        auto iter = map.begin();

        while (iter != map.end())
        {
            if (iter->second > 1)
            {
                return true;
            }

            ++iter;
        }

        return false;
    }

public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> window;
        // 左开右闭区间
        int i = 0, j = 0;
        int res = 0, tmpLen = 0;
        while (j < s.size())
        {
            auto c = s[j];
            window[c]++;
            ++j;
            tmpLen++;

            // 收缩窗口
            while (checkMap(window))
            {
                auto d = s[i];
                window[d]--;
                ++i;
                tmpLen--;
            }

            if (tmpLen > res)
                res = tmpLen;
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb");
    return 0;
}
