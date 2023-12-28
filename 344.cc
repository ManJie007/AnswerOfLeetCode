#include <vector>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        for (size_t i = 0, j = s.size() - 1;; i++, --j)
        {
            if (i == j || i > j)
            {
                return;
            }

            swap(s[i], s[j]);
        }
    }
};