#include <map>
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
  map<int, int> val2Index;

  //左闭右闭区间
  TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                  vector<int> &inorder, int inStart, int inEnd) {
    if (preStart > preEnd) {
      // base case
      return nullptr;
    }

    int rootVal = preorder[preStart];
    int index = val2Index[rootVal];
    int leftSize = index - inStart;

    TreeNode *root = new TreeNode(rootVal);
    root->left = build(preorder, preStart + 1, preStart + leftSize, inorder,
                       inStart, index - 1);
    root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder,
                        index + 1, inEnd);

    return root;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      val2Index[inorder[i]] = i;
    }
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }
};
