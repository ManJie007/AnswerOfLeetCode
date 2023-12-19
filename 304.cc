#include <vector>
#include <iostream>

using namespace std;

class NumMatrix
{
private:
    // C++尽量使用stl，而不是裸指针 用指针创建二维数据还需要记录行数和列数 在析构函数中使用
    // //先尝试指针解法
    // int** mat_ptr = nullptr;
    vector<vector<int>> preSums;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            vector<int> &vec = matrix[i];
            vector<int> addVec((vec.size() + 1), 0);

            if (i == 0)
            {
                preSums.push_back(addVec);
            }

            for (size_t j = 0; j < vec.size(); j++)
            {
                addVec[j + 1] = preSums[i][j + 1] + addVec[j] + vec[j] - preSums[i][j];
            }
            preSums.push_back(addVec);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return preSums[row2 + 1][col2 + 1] - preSums[row2 + 1][col1] - preSums[row1][col2 + 1] + preSums[row1][col1];
    }

    void printMatrix()
    {
        for (size_t i = 0; i < preSums.size(); i++)
        {
            vector<int> &vec = preSums[i];
            for (size_t j = 0; j < vec.size(); j++)
            {
                cout << vec[j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    NumMatrix numMatrix(matrix);
    numMatrix.printMatrix();
    cout << numMatrix.sumRegion(1, 1, 2, 2);
    return 0;
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */