#include <cstddef>
#include <queue>

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
  bool check(TreeNode *left, TreeNode *right) {
    queue<TreeNode *> p, q;
    p.push(left);
    q.push(right);

    while (!p.empty()) {
      TreeNode *node1 = p.front();
      p.pop();
      TreeNode *node2 = q.front();
      q.pop();

      if (node1 == nullptr && node2 == nullptr)
        continue;
      if ((node1 && !node2) || (!node1 && node2))
        return false;
      if ((node1 && node2) && node1->val != node2->val)
        return false;

      p.push(node1->left);
      p.push(node1->right);

      q.push(node2->right);
      q.push(node2->left);
    }

    return true;
  }

public:
  bool isSymmetric(TreeNode *root) { return check(root, root); }
};
