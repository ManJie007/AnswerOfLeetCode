#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    vector<char> choice{'(', ')'};

    void backtrace(vector<string> &res, string &str, int left, int right, int len)
    {
        if (str.size() == len)
        {
            res.push_back(str);
        }

        for (int i = 0; i < choice.size(); i++)
        {
            if (left == len / 2 && i == 0)
                continue;
            if (right == len / 2 && i == 1)
                continue;
            if (left == right && i == 1)
                continue;

            char choose = choice[i];
            str.push_back(choose);
            if (i == 0)
            {
                backtrace(res, str, left + 1, right, len);
            }
            else if (i == 1)
            {
                backtrace(res, str, left, right + 1, len);
            }
            str.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string str;

        backtrace(res, str, 0, 0, n * 2);

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.generateParenthesis(3);
    return 0;
}
