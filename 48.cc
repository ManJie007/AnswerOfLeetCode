#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    for (int i = 0, j = matrix.size() - 1; i < j; ++i, --j) {
      for (int k = 0; k < matrix[0].size(); ++k) {
        swap(matrix[i][k], matrix[j][k]);
      }
    }

    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};
