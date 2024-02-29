#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> graph;
  vector<int> indegree;

  void buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
    indegree.resize(numCourses, 0);
    graph.resize(numCourses);

    for (auto &require : prerequisites) {
      indegree[require[1]]++;
      graph[require[0]].push_back(require[1]);
    }
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    buildGraph(numCourses, prerequisites);

    vector<int> res;
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

        count++;

        res.push_back(n);

        for (auto adj : graph[n]) {
            indegree[adj]--;

            if (indegree[adj] == 0) {
                q.push(adj);
            }
        }
    }

    if (count !=  numCourses) {
        return {};
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
