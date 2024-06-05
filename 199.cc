#include <cstddef>
#include <queue>
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
public:
  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    vector<int> res;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();

      for (int i = 0; i < size; ++i) {
        TreeNode *tmp = q.front();
        q.pop();

        if (i == size - 1) {
          res.push_back(tmp->val);
        }

        if(tmp->left)q.push(tmp->left);
        if(tmp->right)q.push(tmp->right);
      }
    }

    return res;
  }
};
