#include <string>
#include <stack>

using namespace std;

class Solution
{
private:
    char otherChar(char rightChar)
    {
        if (rightChar == ')')
            return '(';
        else if (rightChar == '}')
            return '{';
        else
            return '[';
    }

public:
    bool
    isValid(string s)
    {
        stack<char> charStack;

        for (auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                charStack.push(c);
            }
            else if (!charStack.empty() && otherChar(c) == charStack.top())
            {
                charStack.pop();
            }
            else
            {
                return false;
            }
        }

        return charStack.empty();
    }
};