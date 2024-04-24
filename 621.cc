#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{

public:
    struct Task
    {
        int nextValid;
        int rest;

        Task() : nextValid(1), rest(0) {}
        Task(int nextValid, int rest) : nextValid(nextValid), rest(rest) {}
    };

    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> freq;

        for (auto &ch : tasks)
        {
            freq[ch]++;
        }

        vector<Task> vec;
        for (auto iter = freq.begin(); iter != freq.end(); ++iter)
        {
            vec.emplace_back(1, iter->second);
        }

        int time = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            time++;
            int minTimeValue = INT_MAX;
            for (int j = 0; j < vec.size(); j++)
            {
                if (vec[j].rest)
                {
                    minTimeValue = min(minTimeValue, vec[j].nextValid);
                }
            }

            time = max(time, minTimeValue);

            int best = -1;
            for (int j = 0; j < vec.size(); j++)
            {
                if (vec[j].rest && vec[j].nextValid <= time)
                {
                    if (best == -1 || vec[j].rest > vec[best].rest)
                    {
                        best = j;
                    }
                }
            }

            vec[best].nextValid = time + n + 1;
            vec[best].rest--;
        }

        return time;
    }
};
