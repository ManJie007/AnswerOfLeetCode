 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int res = 0, count = 0;
    void traverse(TreeNode* root, int k) {
        if (root == nullptr) {
            return;
        }

        traverse(root->left, k);
        count++;
        if (count == k) {
            res = root->val;
            return;
        }
        traverse(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return res;
    }
};
