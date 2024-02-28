#include <algorithm>
#include <climits>

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
  struct SubTree {
    bool isBST;
    int minValue;
    int maxValue;
    int sum;
    SubTree(bool isBST, int minValue, int maxValue, int sum)
        : isBST(isBST), minValue(minValue), maxValue(maxValue), sum(sum) {}
  };
  int maxSumBST(TreeNode *root) {
    findMaxSum(root);
    return res;
  }

private:
  int res = 0;

  SubTree findMaxSum(TreeNode *root) {
    if (root == nullptr) {
      return SubTree(true, INT_MAX, INT_MIN, 0);
    }

    auto left = findMaxSum(root->left);
    auto right = findMaxSum(root->right);

    if (left.isBST && right.isBST && root->val > left.maxValue &&
        root->val < right.minValue) {
      int sum = root->val + left.sum + right.sum;
      res = std::max(sum, res);
      return SubTree(true, std::min(left.minValue, root->val),
                     std::max(right.maxValue, root->val), sum);
    } else {
      return SubTree(false, 0, 0, 0);
    }
  }
};
