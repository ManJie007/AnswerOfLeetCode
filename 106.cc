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
  TreeNode *build(vector<int> &inorder, int inStart, int inEnd,
                  vector<int> &postorder, int postStart, int postEnd) {
    if (inStart > inEnd) {
      // base case
      return nullptr;
    }

    int rootVal = postorder[postEnd];
    int index = val2Index[rootVal];
    int leftSize = index - inStart;

    TreeNode *root = new TreeNode(rootVal);
    root->left = build(inorder, inStart, index - 1, postorder, postStart,
                       postStart + leftSize - 1);
    root->right = build(inorder, index + 1, inEnd, postorder,
                        postStart + leftSize, postEnd - 1);

    return root;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      val2Index[inorder[i]] = i;
    }
    return build(inorder, 0, inorder.size() - 1, postorder, 0,
                 postorder.size() - 1);
  }
};
