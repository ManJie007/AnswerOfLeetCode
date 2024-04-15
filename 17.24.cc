#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<int> getMaxMatrix(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        if (rows <= 0)
            return {};
        int cols = matrix[0].size();
        if (cols <= 0)
            return {};

        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int maxSum = INT_MIN;
        vector<int> res(4, 0);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                dp[i][j] = matrix[i][j];
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
                if (i > 0 && j > 0)
                    dp[i][j] -= dp[i - 1][j - 1];

                for (int k = 0; k <= i; k++)
                {
                    for (int m = 0; m <= j; m++)
                    {
                        int tmpSum = dp[i][j];

                        if (k > 0)
                            tmpSum -= dp[k - 1][j];
                        if (m > 0)
                            tmpSum -= dp[i][m - 1];
                        if (k > 0 && m > 0)
                            tmpSum += dp[k - 1][m - 1];

                        if (tmpSum > maxSum)
                        {
                            maxSum = tmpSum;
                            res = {k, m, i, j};
                        }
                    }
                }
            }
        }

        return res;
    }
};
