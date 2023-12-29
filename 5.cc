#include <string>

using namespace std;

class Solution
{
private:
    string isPalindromicString(const string &s, int l, int r)
    {
        if (l == r)
        {
            // 回文串为奇数
            while ((l - 1) >= 0 && (r + 1 < s.size()) && s[l - 1] == s[r + 1])
            {
                --l;
                ++r;
            }
            return s.substr(l, r - l + 1);
        }
        else
        {
            // 回文串为偶数
            if (s[l] == s[r])
            {
                while ((l - 1) >= 0 && (r + 1 < s.size()) && s[l - 1] == s[r + 1])
                {
                    --l;
                    ++r;
                }
                return s.substr(l, r - l + 1);
            }
            else
            {
                return s.substr(l, 1);
            }
        }
    }

public:
    string longestPalindrome(string s)
    {
        string res;
        for (size_t i = 0; i < s.size(); i++)
        {
            string s1 = isPalindromicString(s, i, i);
            string s2 = isPalindromicString(s, i, i + 1);

            if (s1.length() > res.length())res = s1;
            if (s2.length() > res.length())res = s2;
        }

        return res;
    }
};