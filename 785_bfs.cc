#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  bool isBGraph = true;
  vector<bool> visited;
  vector<bool> color;

  void traverse_bfs(vector<vector<int>> &graph, int n) {
    queue<int> q;
    visited[n] = true;
    q.push(n);

    while (!q.empty() && isBGraph) {
      int k = q.front();
      q.pop();

      for (auto adj : graph[k]) {
        if (!visited[adj]) {
          color[adj] = !color[k];
          visited[adj] = true;
          q.push(adj);
        } else {
          if (color[adj] == color[k]) {
            isBGraph = false;
            return;
          }
        }
      }
    }
  }

public:
  bool isBipartite(vector<vector<int>> &graph) {
    visited.resize(graph.size(), false);
    color.resize(graph.size(), false);

    for (int i = 0; i < graph.size(); ++i) {
      if (!visited[i]) {
        traverse_bfs(graph, i);
      }
    }
    return isBGraph;
  }
};
