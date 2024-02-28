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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
      return nullptr;

    if (root->val == key) {
      if (root->left == nullptr && root->right == nullptr) {
        delete root;
        return nullptr;
      }

      if (root->left == nullptr && root->right != nullptr) {
        TreeNode *tmp = root->right;
        delete root;
        return tmp;
      }

      if (root->right == nullptr && root->left != nullptr) {
        TreeNode *tmp = root->left;
        delete root;
        return tmp;
      }

      // last case 左右子树都不为空
      TreeNode *slow = root, *fast = root->left;
      while (fast->right != nullptr) {
        slow = fast;
        fast = fast->right;
      }
      root->val = fast->val;
      if (slow == root) {
        root->left = fast->left;
      } else {
        if (fast->left != nullptr) {
          slow->right = fast->left;
        } else {
          slow->right = nullptr;
        }
      }
      delete fast;
      return root;
    }

    if (root->val > key) {
      root->left = deleteNode(root->left, key);
    }

    if (root->val < key) {
      root->right = deleteNode(root->right, key);
    }

    return root;
  }
};
