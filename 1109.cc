#include <vector>
#include <iostream>

using namespace std;

class Solution
{
private:
    vector<int> diffVec;

public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {

        diffVec.resize(n, 0);
        vector<int> resultVec;
        resultVec.resize(n, 0);

        for (size_t k = 0; k < bookings.size(); k++)
        {
            auto &tmpVec = bookings[k];
            int i = tmpVec[0] - 1, j = tmpVec[1] - 1, val = tmpVec[2];

            // 更新差分数组
            if (i < n)
            {
                diffVec[i] += val;
                if (j + 1 < n)
                {
                    diffVec[j + 1] -= val;
                }
            }
        }
        resultVec[0] = diffVec[0];
        for (size_t l = 1; l < n; l++)
        {
            resultVec[l] = resultVec[l - 1] + diffVec[l];
        }

        return resultVec;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> updates{
        {1, 2, 10},
        {2, 3, 20},
        {2, 5, 25}};
    Solution solution;
    vector<int> result = solution.corpFlightBookings(updates, 5);

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
