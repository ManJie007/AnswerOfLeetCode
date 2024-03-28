#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<string> str_stack;
        string str = "";

        for (auto c : s)
        {
            if (c == '(')
            {
                str_stack.push(str);
                str = "";
            }
            else if (c == ')')
            {
                reverse(str.begin(), str.end());
                str = str_stack.top() + str;
                str_stack.pop();
            }
            else
            {
                str.push_back(c);
            }
        }

        return str;
    }
};
