#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    vector<int> tmp(nums.size());
    copy(nums.begin(), nums.end(), tmp.begin());

    for (int i = 0; i < nums.size(); ++i) {
      int new_index = (i + k) % nums.size();
      nums[new_index] = tmp[i];
    }
  }
};

int main(int argc, char **argv) { return 0; }
