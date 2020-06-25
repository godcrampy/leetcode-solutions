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
  // iterative solution
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) {
      return false;
    }

    stack<TreeNode*> s;
    stack<int> sumStack;

    s.push(root);
    sumStack.push(0);

    while (!s.empty()) {
      auto node = s.top();
      s.pop();
      auto sumSoFar = sumStack.top();
      sumStack.pop();

      if (node->left == NULL && node->right == NULL &&
          node->val + sumSoFar == sum) {
        return true;
      }

      if (node->left != NULL) {
        s.push(node->left);
        sumStack.push(node->val + sumSoFar);
      }

      if (node->right != NULL) {
        s.push(node->right);
        sumStack.push(node->val + sumSoFar);
      }
    }

    return false;
  }
};