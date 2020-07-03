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
  int findBottomLeftValue(TreeNode* root) {
    return findLeftMostAndDepth(root, 0).first->val;
  }

  pair<TreeNode*, int> findLeftMostAndDepth(TreeNode* root, int depth) {
    bool left = false;
    bool right = false;
    TreeNode* leftNode = NULL;
    TreeNode* rightNode = NULL;
    int leftDepth = 0;
    int rightDepth = 0;

    if (root->left != NULL) {
      left = true;
      auto p = findLeftMostAndDepth(root->left, depth + 1);
      leftDepth = p.second;
      leftNode = p.first;
    }

    if (root->right != NULL) {
      right = true;
      auto p = findLeftMostAndDepth(root->right, depth + 1);
      rightDepth = p.second;
      rightNode = p.first;
    }

    if (left && right) {
      if (rightDepth > leftDepth) {
        return {rightNode, rightDepth};
      } else {
        return {leftNode, leftDepth};
      }
    }

    if (left) {
      return {leftNode, leftDepth};
    }

    if (right) {
      return {rightNode, rightDepth};
    }

    return {root, depth};
  }
};
