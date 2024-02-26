#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
  unordered_map<string, TreeNode *> seen;
  unordered_set<TreeNode *> repet;

  string dfs(TreeNode *root) {
    if (root == nullptr) {
      return "";
    }

    string serial = to_string(root->val) + "(" + dfs(root->left) + ")(" +
                    dfs(root->right) + ")";

    auto it = seen.find(serial);
    if (it != seen.end()) {
      repet.insert(it->second);
    } else {
      seen[serial] = root;
    }

    return serial;
  }

public:
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    dfs(root);
    return {repet.begin(), repet.end()};
  }
};

