#include <map>
#include <utility>
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

  TreeNode *build(vector<int> &preorder, int preStart, int preEnd,
                  vector<int> &postorder, int postStart, int postEnd) {
    if (preStart > preEnd) {
      return nullptr;
    }
    if (preStart == preEnd) {
      return new TreeNode(preorder[preStart]);
    }

    int rootVal = preorder[preStart];
    int leftRootVal = preorder[preStart + 1];
    int index = val2Index[leftRootVal];
    int leftSize = index - postStart + 1;

    TreeNode *root = new TreeNode(rootVal);
    root->left = build(preorder, preStart + 1, preStart + leftSize, postorder, postStart, index);
    root->right = build(preorder, preStart + leftSize + 1, preEnd, postorder, index + 1, postEnd - 1);

    return root;
  }

public:
  TreeNode *constructFromPrePost(vector<int> &preorder,
                                 vector<int> &postorder) {
    for (int i = 0; i < postorder.size(); ++i) {
      val2Index.insert(std::make_pair(postorder[i], i));
    }
    return build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
  }
};
