#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  //  vector<vector<string>> groupAnagrams(vector<string> &strs) {
  //    vector<vector<string>> res;
  //    vector<map<char, int>> map_vec;
  //
  //    for (auto &str : strs) {
  //      map<char, int> tmp_map;
  //      for (auto &ch : str) {
  //        tmp_map[ch]++;
  //      }
  //
  //      int index = -1;
  //      for (int i = 0; i < map_vec.size(); ++i) {
  //        if (tmp_map == map_vec[i]) {
  //          index = i;
  //          break;
  //        }
  //      }
  //
  //      if (index == -1) {
  //        map_vec.push_back(tmp_map);
  //        vector<string> s_vec;
  //        s_vec.push_back(str);
  //        res.push_back(s_vec);
  //      } else {
  //        res[index].push_back(str);
  //      }
  //    }
  //
  //    return res;
  //  }

  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;
    map<string, vector<string>> str_map;

    for (auto &str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      str_map[key].push_back(str);
    }
    
    for(auto it = str_map.begin(); it != str_map.end(); ++it) {
       res.push_back(it->second); 
    }

    return res;
  }
};

int main(int argc, char **argv) {

  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution s;
  for (auto &strs : s.groupAnagrams(strs)) {
    for (auto &str : strs) {
      cout << str << " ";
    }
    cout << endl;
  }

  return 0;
}
