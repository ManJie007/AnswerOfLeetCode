#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {

        stack<char> charStack;
        int res = 0;

        for (auto c : s)
        {
            if (c == '(')
            {
                charStack.push(c);
            }
            else
            {
                if (!charStack.empty())
                {
                    charStack.pop();
                }
                else
                {
                    res++;
                }
            }
        }

        return charStack.size() + res;
    }
};