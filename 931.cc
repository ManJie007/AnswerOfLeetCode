#include <algorithm>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution
{
private:
    vector<vector<int>> memo;

    int dp(vector<vector<int>> &matrix, int i, int j)
    {

        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
        {
            return 66666;
        }

        // base case
        if (i == 0)
        {
            return matrix[0][j];
        }

        // memo
        if (memo[i][j] != 66666)
        {
            return memo[i][j];
        }

        memo[i][j] = matrix[i][j] + std::min(std::min(dp(matrix, i - 1, j), dp(matrix, i - 1, j - 1)), dp(matrix, i - 1, j + 1));

        return memo[i][j];
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        memo.resize(n);
        for (auto &line : memo)
        {
            line.resize(matrix[0].size(), 66666);
        }

        int res = INT_MAX;

        for (int j = 0; j < n; ++j)
        {
            res = std::min(res, dp(matrix, n - 1, j));
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    Solution solution;
    std::cout << solution.minFallingPathSum(matrix);
    return 0;
}
