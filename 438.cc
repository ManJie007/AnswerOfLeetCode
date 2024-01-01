#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> need, window;
        vector<int> res;

        for (auto c : p)
        {
            need[c]++;
        }

        // 左闭右开区间
        int i = 0, j = 0;
        int valid = 0;
        while (j < s.size())
        {
            auto c = s[j];
            window[c]++;
            ++j;

            if (need.find(c) != need.end() && need[c] == window[c])
            {
                valid++;
            }

            if (j - i == p.size())
            {
                if (valid == need.size())
                {

                    res.push_back(i);
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

        return res;
    }
};

int main(int argc, char const *argv[])
{
    string s = "cbaebabacd", p = "abc";
    Solution solution;
    vector res = solution.findAnagrams(s, p);
    for (auto i : res)
    {
        cout << i << " ";
    }

    return 0;
}
