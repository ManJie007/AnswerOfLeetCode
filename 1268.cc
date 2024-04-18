#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        sort(products.begin(), products.end());

        auto last_iter = products.begin();
        vector<vector<string>> g_res;

        for (int i = 0; i < searchWord.size(); i++)
        {
            string str = searchWord.substr(0, i + 1);
            last_iter = lower_bound(last_iter, products.end(), str);
            vector<string> res;

            for (size_t i = 0; i < 3; i++)
            {
                if (last_iter + i < products.end() && (*(last_iter + i)).find(str) == 0)
                {
                    res.push_back(*(last_iter + i));
                }
            }

            g_res.push_back(res);
        }

        return g_res;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> input{"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string word = "mouse";
    Solution s;
    s.suggestedProducts(input, word);

    return 0;
}