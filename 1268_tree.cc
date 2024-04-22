#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
    unordered_map<char, Node *> ch_map;
    priority_queue<string> str_pq;
};

class Solution
{
private:
    void addNode(Node *root, const string &str)
    {
        Node *cur = root;
        for (auto &ch : str)
        {
            if (!cur->ch_map.count(ch))
            {
                cur->ch_map[ch] = new Node();
            }

            cur = cur->ch_map[ch];

            cur->str_pq.push(str);
            if (cur->str_pq.size() > 3)
            {
                cur->str_pq.pop();
            }
        }
    }

public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        Node *root = new Node();
        for (auto &str : products)
        {
            addNode(root, str);
        }

        vector<vector<string>> res;

        Node *cur = root;
        for (auto &ch : searchWord)
        {
            if (!cur->ch_map.count(ch))
            {
                res.push_back({});
            }
            else
            {
                cur = cur->ch_map[ch];
                vector<string> selects;

                while (!cur->str_pq.empty())
                {
                    selects.push_back(cur->str_pq.top());
                    cur->str_pq.pop();
                }
                reverse(selects.begin(), selects.end());
                res.push_back(move(selects));
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> vec{"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string word = "mouse";
    Solution s;
    s.suggestedProducts(vec, word);
    return 0;
}