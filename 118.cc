#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for(int i = 1; i <= numRows; ++i) {
            vector<int> tmp(i, 1);

            for(int j = 1; j <= (int)tmp.size() - 2; ++j) {
                tmp[j] = res[i - 2][j - 1] + res[i-2][j];
            }

            res.push_back(tmp);
        }


        return res;
    }
};


int main(int argv, char** agrv) {

    Solution s;
    auto res = s.generate(5);

    for(auto &&tmp : res) {
        for(auto &&item : tmp) {
            cout << item << " ";
        }

        cout << endl;
    }
    return  0;
}
