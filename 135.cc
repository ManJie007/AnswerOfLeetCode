#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    void changeCounts(const vector<int> ratings, vector<int> &counts, int index)
    {
        while (index > 0)
        {
            if (ratings[index - 1] > ratings[index] && counts[index - 1] <= counts[index])
            {
                counts[index - 1] = counts[index] + 1;
            }
            else if (ratings[index - 1] < ratings[index] && counts[index - 1] >= counts[index])
            {
                counts[index] = counts[index - 1] + 1;
            }
            index--;
        }
    }

public:
    int candy(vector<int> &ratings)
    {
        int index = 0;
        vector<int> counts(ratings.size(), 0);

        while (index < ratings.size())
        {
            counts[index] = 1;
            changeCounts(ratings, counts, index);
            index++;
        }

        int sum = 0;

        for (size_t i = 0; i < counts.size(); i++)
        {
            sum += counts[i];
        }

        return sum;
    }
};