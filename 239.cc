#include <deque>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  // public:
  //     vector<int> maxSlidingWindow(vector<int> &nums, int k)
  //     {
  //
  //         deque<int> queue;
  //         vector<int> res;
  //
  //         for (size_t i = 0; i < nums.size(); i++)
  //         {
  //             if (i < k - 1)
  //             {
  //                 while (!queue.empty() && nums[i] > queue.back())
  //                 {
  //                     queue.pop_back();
  //                 }
  //                 queue.push_back(nums[i]);
  //             }
  //             else
  //             {
  //                 while (!queue.empty() && nums[i] > queue.back())
  //                 {
  //                     queue.pop_back();
  //                 }
  //                 queue.push_back(nums[i]);
  //
  //                 res.push_back(queue.front());
  //
  //                 if (nums[i - k + 1] == queue.front())
  //                 {
  //                     queue.pop_front();
  //                 }
  //             }
  //         }
  //
  //         return res;
  //     }
public:
  struct element {
    int m_val;
    int m_index;
    element(int val, int index) : m_val(val), m_index(index) {}

    bool operator<(const element &rhs) const { return m_val < rhs.m_val; }
  };

  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    priority_queue<element> pq;

    for (int i = 0; i < k; ++i) {
      pq.push({nums[i], i});
    }

    vector<int> res;
    res.push_back(pq.top().m_val);

    for (int i = k; i < nums.size(); ++i) {
      pq.push({nums[i], i});

      while (pq.top().m_index <= i - k) {
        pq.pop();
      }

      res.push_back(pq.top().m_val);
    }

    return res;
  }
};
