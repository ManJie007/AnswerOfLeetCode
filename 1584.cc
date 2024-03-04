#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class UF {
private:
  int count;
  vector<int> parent;

  int find(int x) {
    while (x != parent[x]) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }

    return x;
  }

public:
  UF(int n) {
    count = n;
    parent.resize(n);

    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  void union_a_b(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB) {
      return;
    }

    parent[rootA] = rootB;
    count--;
    return;
  }

  bool isConnected(int a, int b) { return find(a) == find(b); }

  int getCount() { return count; }
};

struct Edge {
  int x, y, len;
  Edge(int x, int y, int len) : x(x), y(y), len(len) {}
};

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {

    auto dist = [&](int x, int y) -> int {
      return abs(points[x][0] - points[y][0]) +
             abs(points[x][1] - points[y][1]);
    };
    int n = points.size();
    UF uf(n);
    vector<Edge> edges;

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        edges.push_back({i, j, dist(i, j)});
      }
    }
    sort(edges.begin(), edges.end(),
         [](Edge &a, Edge &b) -> bool { return a.len < b.len; });
    int ret = 0, num = 1;

    for (auto &edge : edges) {
      if (!uf.isConnected(edge.x, edge.y)) {
        uf.union_a_b(edge.x, edge.y);
        ret += edge.len;
        num++;
        if(num == n){
            break;
        }
      }
    }
    return ret;
  }
};
