#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {

    unordered_set<int> num_set;

    for (auto &num : nums) {
      num_set.insert(num);
    }

    int longest_len = 0;
    for (auto it = num_set.begin(); it != num_set.end(); ++it) {
      if (!num_set.count(*it - 1)) {
        int num = *it;
        int len = 1;
        while (num_set.count(num + 1)) {
          num += 1;
          len += 1;
        }

        longest_len = max(longest_len, len);
      }
    }

    return longest_len;
  }
};
