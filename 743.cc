#include <algorithm>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int src, to, len;
  Edge(int src, int to, int len) : src(src), to(to), len(len) {}
};

struct State {
  int id;
  int disFromStart;

  State(int id, int disFromStart) : id(id), disFromStart(disFromStart) {}
};

bool compareNodeDist(const State &a, const State &b) {

  return a.disFromStart > b.disFromStart;
}

void dijkstra(vector<vector<Edge>> &graph, int start, vector<int> &dstTo) {

  dstTo[start] = 0;
  priority_queue<State, vector<State>, decltype(compareNodeDist) *> pq(
      compareNodeDist);

  pq.push({start, 0});

  while (!pq.empty()) {
    State cur = pq.top();
    pq.pop();
    int curId = cur.id;
    int curDistFomStart = cur.disFromStart;

    if (curDistFomStart > dstTo[curId]) {
        continue;
    }

    for (auto &edge : graph[curId]) {
        int nextId = edge.to;
        int dstToNextNode = dstTo[curId] + edge.len;

        if (dstTo[nextId] > dstToNextNode) {
            dstTo[nextId] = dstToNextNode;
            pq.push({nextId, dstToNextNode});
        } 
    }
  }
}

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<int> dstTo;
    vector<vector<Edge>> graph;

    // build
    dstTo.resize(n, INT_MAX);
    graph.resize(n);

    for (auto &time : times) {
      int src = time[0] - 1;
      int to = time[1] - 1;
      int len = time[2];
      graph[src].push_back({src, to, len});
    }

    dijkstra(graph, k - 1, dstTo);

    int res = 0;
    for (int i = 0; i < dstTo.size(); ++i) {
        if (dstTo[i] == INT_MAX) return -1;

        res = max(res, dstTo[i]);
    }
    return res;
  }
};
