#include <cmath>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct Edge
{
  int src, dst, weigth;
  Edge(int src, int dst, int weigth) : src(src), dst(dst), weigth(weigth) {}
};

bool compareEdge(const Edge &a, const Edge &b) { return a.weigth > b.weigth; }

class Prim
{
private:
  priority_queue<Edge, vector<Edge>, decltype(compareEdge) *> pq;
  vector<bool> inMST;
  int weightSum = 0;
  vector<vector<Edge>> graph;

  void cut(int n)
  {
    for (auto &edge : graph[n])
    {
      int dst = edge.dst;
      if (inMST[dst])
      {
        continue;
      }

      pq.push(edge);
    }
  }

public:
  Prim(vector<vector<int>> &points) : pq(compareEdge)
  {
    inMST.resize(points.size(), false);
    graph.resize(points.size());

    auto len = [&](int x, int y) -> int
    {
      return abs(points[x][0] - points[y][0]) +
             abs(points[x][1] - points[y][1]);
    };

    for (int i = 0; i < points.size(); ++i)
    {
      for (int j = 0; j < points.size(); ++j)
      {
        if (i == j)
        {
          continue;
        }
        graph[i].push_back({i, j, len(i, j)});
      }
    }

    inMST[0] = true;
    cut(0);

    while (!pq.empty())
    {
      Edge edge = pq.top();
      pq.pop();

      if (inMST[edge.dst])
      {
        continue;
      }

      weightSum += edge.weigth;
      inMST[edge.dst] = true;
      cut(edge.dst);
    }
  }

  int getWeightSum() { return weightSum; }
};

class Solution
{
public:
  int minCostConnectPoints(vector<vector<int>> &points)
  {
    return Prim(points).getWeightSum();
  }
};

int main(int argc, char const *argv[])
{
  vector<vector<int>> points = {{0, 0}, {1, 1}, {1, 0}, {-1, 1}};
  Solution solution;
  cout << solution.minCostConnectPoints(points);
  return 0;
}
