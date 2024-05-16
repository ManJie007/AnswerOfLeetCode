#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

// struct element {
//   int m_i, m_j, m_k;
//
//   element(int i, int j, int k) {
//     vector<int> num = {i, j, k};
//     sort(num.begin(), num.end());
//
//     m_i = num[0];
//     m_j = num[1];
//     m_k = num[2];
//   }
//
//   vector<int> to_vec() const { return {m_i, m_j, m_k}; }
//
//   bool operator<(const element &rhs) const {
//     return m_i < rhs.m_i || (m_i == rhs.m_i && m_j < rhs.m_j) || (m_i ==
//     rhs.m_i && m_j == rhs.m_j && m_k < rhs.m_k);
//   }
// };
//
// class Solution {
// public:
//   vector<vector<int>> threeSum(vector<int> &nums) {
//     set<element> res_set;
//
//     for (int i = 0; i < nums.size(); ++i) {
//       for (int j = i + 1; j < nums.size(); ++j) {
//         for (int k = j + 1; k < nums.size(); ++k) {
//           if (nums[i] + nums[j] + nums[k] == 0) {
//             res_set.insert({nums[i], nums[j], nums[k]});
//           }
//         }
//       }
//     }
//
//     vector<vector<int>> res;
//     for (auto iter = res_set.begin(); iter != res_set.end(); ++iter) {
//       res.push_back(iter->to_vec());
//     }
//
//     return res;
//   }
// };

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;

    for (int i = 0; i < nums.size(); ++i) {
      if (i == 0 || nums[i] != nums[i - 1]) {
        int k = nums.size() - 1;
        for (int j = i + 1; j < nums.size(); ++j) {
          if (j == i + 1 || nums[j] != nums[j - 1]) {
            while (j < k && nums[i] + nums[j] + nums[k] > 0) {
              --k;
            }
            if (k > j && nums[i] + nums[j] + nums[k] == 0) {
              res.push_back({nums[i], nums[j], nums[k]});
            }
          }
        }
      }
    }

    return res;
  }
};

int main(int argc, char **argv) {
  vector<int> nums{-1, 0, 1, 2, -1, 4};
  Solution s;
  auto vecc = s.threeSum(nums);
  for (auto &vec : vecc) {
    for (auto &i : vec) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
