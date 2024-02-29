#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
  vector<int> indegree;
  vector<vector<int>> graph;

  void buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
    indegree.resize(numCourses, 0);
    graph.resize(numCourses);

    for (auto &require : prerequisites) {
        indegree[require[1]] += 1;
        graph[require[0]].push_back(require[1]);
    }
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    buildGraph(numCourses, prerequisites);

    int count = 0;
    queue<int> q;

    for (int i = 0; i < numCourses; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        ++count;

        //减少其他点的入度
        for (auto &adj : graph[n]) {
            indegree[adj] -= 1;

            if (indegree[adj] == 0) {
                q.push(adj);
            }
        }
    }

    return numCourses == count;
  }
};
