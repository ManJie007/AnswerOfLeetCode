#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto &vec : intervals) {
      pq.push({vec[0], vec[1]});
    }

    vector<vector<int>> res;

    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();

      while (!pq.empty() && pq.top().first <= p.second) {
        p.second = max(p.second, pq.top().second);
        pq.pop();
      }

      res.push_back({p.first, p.second});
    }

    return res;
  }
};
