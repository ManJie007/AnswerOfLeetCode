#include <string>

using namespace std;

class Solution
{
private:
    int pos = 0;
    string decode_string_r(string s)
    {
        string res, num_str;

        while (pos < s.size())
        {
            if (isdigit(s[pos]))
            {
                num_str += s[pos];
                pos++;
            }
            else if (isalpha(s[pos]))
            {
                res += s[pos];
                pos++;
            }
            else if (s[pos] == '[')
            {
                pos++;
                string tmp = decode_string_r(s);
                for (size_t i = 0; i < stoi(num_str); i++)
                {
                    res += tmp;
                }
                num_str.clear();
            }
            else if (s[pos] == ']')
            {
                ++pos;
                return res;
            }
        }

        return res;
    }

public:
    string decodeString(string s)
    {
        return decode_string_r(s);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.decodeString("3[a]2[bc]");    
    return 0;
}
