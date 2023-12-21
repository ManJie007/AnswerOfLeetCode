#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
    vector<int> diffVec;
    vector<int> resultVec;

public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        diffVec.resize(1001, 0);
        resultVec.resize(1001, 0);

        for (size_t i = 0; i < trips.size(); ++i)
        {
            auto &tmpVec = trips[i];

            int val = tmpVec[0], start = tmpVec[1], end = tmpVec[2];

            if (start < 1001)
            {
                diffVec[start] += val;
                if (end < 1001)
                {
                    diffVec[end] -= val;
                }
            }
        }

        resultVec[0] = diffVec[0];
        if (resultVec[0] > capacity)
        {
            return false;
        }
        for (size_t i = 1; i < 1001; ++i)
        {
            resultVec[i] = resultVec[i - 1] + diffVec[i];
            if (resultVec[i] > capacity)
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> trips {
        {2, 1, 5}, 
        {3, 5, 7}
    };
    Solution solution;
    cout << solution.carPooling(trips, 3);
    return 0;
}
