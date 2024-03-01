#include <vector>

using namespace std;

class Solution {
private:
  bool isBGraph = true;
  vector<bool> visited;
  vector<bool> color;

  void traverse(vector<vector<int>> &graph, int n) {
    if (!isBGraph) {
        return;
    }
    if (visited[n]) {
        return;
    }

    visited[n] = true;

    for (auto adj : graph[n]) {
        if (!visited[adj]) {
            color[adj] = !color[n];
            traverse(graph, adj);
        }else {
            if (color[n] == color[adj]) {
                isBGraph = false;
                return;
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
        traverse(graph, i);
      }
    }
    return isBGraph;
  }
};
