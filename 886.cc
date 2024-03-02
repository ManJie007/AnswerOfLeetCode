#include <vector>

using namespace std;

class Solution {
private:
  bool isBGraph = true;
  vector<vector<int>> graph;
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
      } else {
        if (color[n] == color[adj]) {
          isBGraph = false;
          return;
        }
      }
    }
  }

public:
  bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
    visited.resize(n, false);
    color.resize(n, false);
    graph.resize(n);


    for (auto &adj : dislikes) {
        int i = adj[0] - 1;
        int j = adj[1] - 1;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }

    for (int i = 0; i < graph.size(); ++i) {
      if (!visited[i]) {
        traverse(graph, i);
      }
    }
    return isBGraph;
  }
};
