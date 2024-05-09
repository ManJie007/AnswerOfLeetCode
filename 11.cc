#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  //  void printRes(vector<int> &height, int left, int right, int max_size) {
  //    for (int i = 0; i < height.size(); ++i) {
  //      cout << height[i] << " ";
  //    }
  //    cout << endl;
  //    for (int i = 0; i < height.size(); ++i) {
  //      if (i == left || i == right) {
  //        cout << "^"
  //             << " ";
  //        continue;
  //      }
  //      cout << "  ";
  //    }
  //    cout << endl;
  //
  //    cout <<
  //    "================================================================"
  //         << endl;
  //    cout << "left : " << left << endl;
  //    cout << "right : " << right << endl;
  //    cout << "cur_size" << (right - left) * min(height[left], height[right])
  //         << endl;
  //    cout << "max_size" << max_size << endl;
  //    cout <<
  //    "================================================================"
  //         << endl;
  //  }
  //
  //  int maxArea(vector<int> &height) {
  //    int left = 0, right = 0;
  //    int cur_size = 0, max_size = 0;
  //
  //    while (right < height.size()) {
  //      cur_size = (right - left) * min(height[left], height[right]);
  //      max_size = max(max_size, cur_size);
  //
  //      // printRes(height, left, right, max_size);
  //
  //      while (left + 1 < right &&
  //             ((right - left - 1) * min(height[left + 1], height[right])) >=
  //                 cur_size) {
  //        left++;
  //        max_size =
  //            max(max_size, (right - left) * min(height[left],
  //            height[right]));
  //
  //        // printRes(height, left, right, max_size);
  //      }
  //      ++right;
  //    }
  //
  //    return max_size;
  //  }
  int maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int ans = 0;

    while (left < right) {
      int area = min(height[left], height[right]) * (right - left);
      ans = max(ans, area);

      if (height[left] <= height[right]) {
        ++left;
      } else {
        --right;
      }
    }

    return ans;
  }
};

int main(int argc, char **argv) {

  // vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
  vector<int> height{2, 3, 4, 5, 18, 17, 6};
  Solution s;
  cout << s.maxArea(height);
  return 0;
}
