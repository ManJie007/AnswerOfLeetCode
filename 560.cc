#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//  int subarraySum(vector<int> &nums, int k) {
//    int count = 0;
//
//    for (int i = 0; i < nums.size(); ++i) {
//      int sum = 0;
//      for (int j = i; j < nums.size(); ++j) {
//        sum += nums[j];
//        if (sum == k) {
//          count++;
//          if (j + 1 < nums.size() && nums[j+1] == 0) {
//          } else {
//            break;
//          }
//        }
//      }
//    }
//
//    return count;
//  }
//};

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> num_map;
    num_map.insert(make_pair(0, 1));
    //num_map.insert({0, 1});

    int count = 0, pre = 0;

    for(auto &x : nums) {
        pre += x;
        if (num_map.find(pre - k) != num_map.end()) {
            count += num_map[pre - k];
        }
        num_map[pre]++;
    }

    return count;
  }
};
int main(int argc, char **argv) {

  vector<int> nums{1, 2, 3};
  int k = 3;
  Solution s;
  cout << s.subarraySum(nums, k);
  return 0;
}
