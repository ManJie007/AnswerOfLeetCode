#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> res;
  vector<int> path;

  void traverse(vector<vector<int>> &graph, int k, int n) {
    if (k == n) {
      res.push_back(path);
      return;
    }

    for (auto &i : graph[k]) {
      path.push_back(i);
      traverse(graph, i, n);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    path.push_back(0);
    traverse(graph, 0, graph.size() - 1);
    return res;
  }
};
