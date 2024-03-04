#include <string>
#include <vector>

using namespace std;

class UF {
private:
  int count;
  vector<int> parent;

  int find(int p) {

    while (p != parent[p]) {
      parent[p] = parent[parent[p]];
      p = parent[p];
    }

    return p;
  }

public:
  UF(int n) {
    count = n;
    parent.resize(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  void union_twopoint(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB) {
      return;
    }

    parent[rootA] = rootB;
    count--;
    return;
  }

  bool isConnected(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    return rootA == rootB;
  }

  int getCount() { return count; }
};

class Solution {
public:
  bool equationsPossible(vector<string> &equations) {
    UF uf(26);

    for (auto &s : equations) {
      if (s[1] == '=') {
        uf.union_twopoint(s[0] - 'a', s[3] - 'a');
      }
    }

    for (auto &s : equations) {
      if (s[1] == '!') {
        if (uf.isConnected(s[0] - 'a', s[3] - 'a')) {
          return false;
        }
      }
    }

    return true;
  }
};
