#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution
{
public:
    int minInsertions(string s)
    {
        stack<char> charStack;
        int rightNeed = 0;
        for (size_t i = 0; i < s.size();)
        {

            if (s[i] == '(')
            {
                charStack.push(s[i]);
                ++i;
            }
            else
            {
                if ((!charStack.empty()))
                {
                    if (i < s.size() - 1 && s[i + 1] == ')')
                    {
                        charStack.pop();
                        i += 2;
                    }
                    else
                    {
                        charStack.pop();
                        rightNeed++;
                        i++;
                    }
                }
                else
                {
                    if (i < s.size() - 1 && s[i + 1] == ')')
                    {
                        rightNeed++;
                        i += 2;
                    }
                    else
                    {
                        rightNeed += 2;
                        i++;
                    }
                }
            }
        }

        int res = 0;
        res += charStack.size() * 2;
        res += rightNeed;

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.minInsertions("))(()()))()))))))()())()(())()))))()())(()())))()(");
    return 0;
}
