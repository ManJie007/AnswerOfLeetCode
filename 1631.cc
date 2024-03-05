#include <climits>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct State {
  int x, y;
  int effortFromStart;
  State(int x, int y, int effortFromStart)
      : x(x), y(y), effortFromStart(effortFromStart) {}
};

vector<vector<int>> adj(vector<vector<int>> &heights, int x, int y) {
  static vector<vector<int>> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

  vector<vector<int>> res;
  int m = heights.size(), n = heights[0].size();

  for (auto &vec : d) {
    int nx = x + vec[0];
    int ny = y + vec[1];

    if (nx >= m || nx < 0 || ny >= n || ny < 0) {
      continue;
    }
    res.push_back({nx, ny});
  }

  return res;
}

bool compareState(const State &a, const State &b) {
  return a.effortFromStart > b.effortFromStart;
}

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    vector<vector<int>> efforts;
    efforts.resize(heights.size());
    for (auto &effort : efforts) {
      effort.resize(heights[0].size(), INT_MAX);
    }

    efforts[0][0] = 0;

    priority_queue<State, vector<State>, decltype(compareState) *> pq(
        compareState);

    pq.push({0, 0, 0});

    while (!pq.empty()) {
        State curState = pq.top();
        pq.pop();

        int curX = curState.x;
        int curY = curState.y;
        int curEffortFromStart = curState.effortFromStart;

        if (curX == heights.size() - 1 && curY == heights[0].size() - 1) {
            return curEffortFromStart;
        }

        if (curEffortFromStart > efforts[curX][curY]) {
            continue;
        }

        for (auto &vec : adj(heights, curX, curY)) {
          int nextX = vec[0];
          int nextY = vec[1];

          int effortToNextNode = max(efforts[curX][curY], abs(heights[curX][curY] - heights[nextX][nextY]));
          if (effortToNextNode < efforts[nextX][nextY])
          {
              efforts[nextX][nextY] = effortToNextNode;
              pq.push({nextX, nextY, effortToNextNode});
          }
          
        }
    }
    return -1;
  }
};
