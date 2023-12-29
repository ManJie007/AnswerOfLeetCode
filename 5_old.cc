#include <string>
#include <tuple>
#include <iostream>

using namespace std;

class Solution
{
private:
    tuple<int, int> isPalindromicString(const string &s, int l, int r)
    {
        if (l == r)
        {
            // 回文串为奇数
            while ((l - 1) >= 0 && (r + 1 < s.size()) && s[l - 1] == s[r + 1])
            {
                --l;
                ++r;
            }
            return make_tuple(l, r);
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
                return make_tuple(l, r);
            }
            else
            {
                return make_tuple(l, l);
            }
        }
    }

public:
    string longestPalindrome(string s)
    {
        tuple<int, int> res = make_tuple(0, 0);
        for (size_t i = 0; i < s.size(); i++)
        {
            tuple<int, int> tmpRes1 = isPalindromicString(s, i, i);
            tuple<int, int> tmpRes2 = isPalindromicString(s, i, i + 1);

            if ((get<1>(tmpRes1) - get<0>(tmpRes1)) > (get<1>(res) - get<0>(res)))
            {
                res = tmpRes1;
            }

            if ((get<1>(tmpRes2) - get<0>(tmpRes2)) > (get<1>(res) - get<0>(res)))
            {
                res = tmpRes2;
            }
        }
        cout << get<0>(res) << " " << get<1>(res) << endl;
        return s.substr(get<0>(res), get<1>(res) + 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    // cout << solution.longestPalindrome("babad");
    cout << solution.longestPalindrome("cbbd");
    return 0;
}
