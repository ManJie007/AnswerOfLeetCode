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
  bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max) {
    if(root == nullptr) return true;

    if(min != nullptr && min->val >= root->val)return false;
    if(max != nullptr && max->val <= root->val)return false;

    return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
  }
public:
  bool isValidBST(TreeNode *root) {
    return isValidBST(root, nullptr, nullptr);
  }
};
