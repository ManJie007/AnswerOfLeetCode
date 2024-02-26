#include <cstddef>
#include <deque>
#include <string>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {

private:
  void rserialize(TreeNode *root, string &str) {
    if (root == nullptr) {
      str += "None,";
      return;
    }

    str += to_string(root->val) + ",";
    rserialize(root->left, str);
    rserialize(root->right, str);
  }

  TreeNode *rdeserialize(deque<string> &res) {
    if (res.front() == "None") {
      res.erase(res.begin());
      return nullptr;
    }

    TreeNode *root = new TreeNode(stoi(res.front()));
    res.erase(res.begin());
    root->left = rdeserialize(res);
    root->right = rdeserialize(res);

    return root;
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string ret;
    rserialize(root, ret);
    return ret;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    deque<string> res;
    string str;

    for (auto &chr : data) {
      if (chr == ',') {
        res.push_back(str);
        str.clear();
      } else {
        str.push_back(chr);
      }
    }

    if (!str.empty()) {
      res.push_back(str);
    }

    return rdeserialize(res);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
