#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  string up(string s, int j) {
    if (s[j] == '9') {
        s[j] = '0';
    }else {
        s[j] += 1;
    }

    return s;
  }
  string down(string s, int j) {
    if (s[j] == '0') {
        s[j] = '9';
    }else {
        s[j] -= 1;
    }

    return s;
  }

public:
  int openLock(vector<string> &deadends, string target) {

    set<string> deads;

    for (auto &dead : deadends) {
      deads.insert(dead);
    }

    queue<string> q;
    set<string> visited;

    q.push("0000");
    visited.insert("0000");

    int step = 0;

    while (!q.empty()) {

      int sz = q.size();

      for (int i = 0; i < sz; ++i) {
        string s = q.front();
        q.pop();

        if (deads.count(s))
          continue;

        if (target == s)
          return step;

        for (int j = 0; j < 4; ++j) {
            string up_str = up(s, j);
            if(visited.count(up_str) == 0) {
                q.push(up_str);
                visited.insert(up_str);
            }

            string down_str = down(s, j);
            if(visited.count(down_str) == 0) {
                q.push(down_str);
                visited.insert(down_str);
            }
        }
      }

      step++;
    }

    return -1;
  }
};
