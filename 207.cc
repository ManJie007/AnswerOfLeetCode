#include <vector>

using namespace std;

class Solution {
private:
  bool isCycle = false;
  vector<bool> visited;
  vector<bool> onPath;
  vector<vector<int>> graph;

  void buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
    visited.resize(numCourses, false);
    onPath.resize(numCourses, false);
    graph.resize(numCourses);

    for (auto &require : prerequisites) {
      graph[require[0]].push_back(require[1]);
    }
  }
  void traverse(int n) {
    if (onPath[n]) {
      isCycle = true;
      return;
    }
    if (visited[n] || isCycle) {
      return;
    }

    onPath[n] = true;
    visited[n] = true;

    for (auto &adj : graph[n]) {
        traverse(adj);
    }

    onPath[n] = false;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    buildGraph(numCourses, prerequisites);

    for (int i = 0; i < numCourses; ++i) {
      traverse(i);
    }

    return !isCycle;
  }
};
