#include <climits>
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
  //左开右闭区间
  TreeNode *constructMaximumBinaryTree(int left, int right, vector<int> &nums) {
    if (left >= right) {
      return nullptr;
    }

    int maxVal = INT_MIN;
    int index = -1;
    for (int i = left; i < right; ++i) {
      if (nums[i] > maxVal) {
        maxVal = nums[i];
        index = i;
      }
    }

    TreeNode *node = new TreeNode(nums[index]);
    //递归调用左右子树
    node->left = constructMaximumBinaryTree(left, index, nums);
    node->right = constructMaximumBinaryTree(index + 1, right, nums);
    return node;
  }

public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return constructMaximumBinaryTree(0, nums.size(), nums);
  }
};
