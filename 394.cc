#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution
{
private:
    stack<int> num_s;
    stack<string> string_s;

public:
    string decodeString(string s)
    {
        string res, tmp_str, num_str;
        int count = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i]))
            {
                if (!count)
                {
                    res += s[i];
                }
                else
                {
                    tmp_str += s[i];
                }
            }
            else if (isdigit(s[i]))
            {
                if (!tmp_str.empty())
                {
                    string_s.push(tmp_str);
                    tmp_str.clear();
                }

                num_str += s[i];
            }
            else if (s[i] == '[')
            {
                count++;
                num_s.push(stoi(num_str));
                num_str.clear();
            }
            else if (s[i] == ']')
            {
                count--;
                int num = num_s.top();
                num_s.pop();

                string str;
                for (size_t i = 0; i < num; i++)
                {
                    str += tmp_str;
                }
                tmp_str.clear();

                if (count == 0)
                {
                    res += str;
                }else
                {
                    if(string_s.size() > 0) {
                        string top = string_s.top();
                        string_s.pop();
                        top += str;
                        tmp_str = top;
                    }else {
                        tmp_str = str;
                    }
                }
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef");
    return 0;
}
