#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class Solution
{
private:
    int size;
    vector<int> nums;
    // unordered_set<int> record_set;
    unordered_map<int, int> val_index_map;

public:
    Solution(int n, vector<int> &blacklist)
    {
        for (int i = 0; i < n; i++)
        {
            nums.push_back(i);
        }

        size = n - blacklist.size();

        for (auto i : blacklist)
        {
            // record_set.insert(i);
            val_index_map[i] = i;
        }

        int last = n - 1;
        for (auto i : blacklist)
        {
            if (i >= size)
            {
                continue;
            }
            // while (record_set.count(last))
            while (val_index_map.count(last))
            {
                last--;
            }
            // swap(nums[i], nums[last]);
            val_index_map[i] = last;
            last--;
        }
    }

    int pick()
    {
        // return nums[rand() % size];
        int index = rand() % size;
        if (val_index_map.count(index))
        {
            return val_index_map[index];
        }
        
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */