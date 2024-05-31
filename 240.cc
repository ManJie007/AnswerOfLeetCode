#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    for (auto &&row : matrix) {
      auto it = lower_bound(row.begin(), row.end(), target);
      if (it != row.end() &&*it == target)
        return true;
    }

    return false;
  }
};
