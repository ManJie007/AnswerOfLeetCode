#include <vector>
#include <iostream>

using namespace std;

class Solution {

private:
    vector<int> result_vec;
    vector<int> diff_vec;

    void diff(int i, int j, int val) {
        if (i < diff_vec.size())
        {
            diff_vec[i] += val;
            if (j + 1 < diff_vec.size())
            {
                diff_vec[j + 1] -= val;   
            }
                
        }

        result_vec[0] = diff_vec[0];
        for (size_t i = 1; i < result_vec.size(); i++)
        {
            //更新一下结果
            result_vec[i] = result_vec[i - 1] + diff_vec[i];
        }
        
        
    }

public:

    void printResult() {
        for (size_t i = 0; i < result_vec.size(); i++)
        {
            cout << result_vec[i] << " ";
        }
        cout << endl;
    }

    void getModifiedArray(int length, vector<vector<int>>& updates) {
        result_vec.resize(length, 0);
        diff_vec.resize(length, 0);

        for (size_t k = 0; k < updates.size(); k++)
        {
            auto& tmpVec = updates[k];
            int i = tmpVec[0], j = tmpVec[1], val = tmpVec[2];
            diff(i, j , val);
            printResult();
        }

    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> updates {
        {1, 3, 2},
        {2, 4, 3},
        {0, 2, -2}
    };
    Solution solution;
    solution.getModifiedArray(5, updates);    

    return 0;
}

