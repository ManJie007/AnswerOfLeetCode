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

  void union_twopoint(int x, int y) {
    int parentA = find(x);
    int parentB = find(y);

    if (parentA == parentB) {
      return;
    } else {
      parent[parentA] = parentB;
      count--;
    }
  }

  bool connected(int x, int y) {
    int parentA = find(x);
    int parentB = find(y);

    return parentA == parentB;
  }

  int getCount() { return count; }
};

vector<vector<int>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

class Solution {
public:
  void solve(vector<vector<char>> &board) {

    int m = board.size(), n = board[0].size();
    UF uf(m * n + 1);

    int dummy = m * n;

    //连通dummy和第0列和第n-1列的'0'
    for (int i = 0; i < m; ++i) {
      if (board[i][0] == 'O') {
        uf.union_twopoint(dummy, i * n + 0);
      }
      if (board[i][n - 1] == 'O') {
        uf.union_twopoint(dummy, i * n + n - 1);
      }
    }

    //连通dummy和第0行和第m-1行的'0'
    for (int i = 0; i < n; ++i) {
      if (board[0][i] == 'O') {
        uf.union_twopoint(dummy, 0 * n + i);
      }
      if (board[m - 1][i] == 'O') {
        uf.union_twopoint(dummy, (m - 1) * n + i);
      }
    }

    //连接边界上的‘0’
    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        if (board[i][j] == 'O') {
          for (int k = 0; k < d.size(); ++k) {
            int x = i + d[k][0];
            int y = j + d[k][1];

            if (board[x][y] == 'O') {
              uf.union_twopoint(i * n + j, x * n + y);
            }
          }
        }
      }
    }
    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        if (!uf.connected(dummy, i * n + j)) {
          board[i][j] = 'X';
        }
      }
    }
  }
};
