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
  TreeNode* pruneTree(TreeNode* root) {
    if (containsOneAndPrune(root)) {
      return root;
    }
    return NULL;
  }

  bool containsOneAndPrune(TreeNode* root) {
    if (root == NULL) {
      return false;
    }
    bool contains = root->val == 1;
    bool left = containsOneAndPrune(root->left);
    bool right = containsOneAndPrune(root->right);

    if (!left) {
      root->left = NULL;
    }

    if (!right) {
      root->right = NULL;
    }

    return contains || left || right;
  }
};
