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
  vector<int> inorderTraversal(TreeNode* root) {
    if (root == NULL) {
      return {};
    }
    stack<TreeNode*> left, right;
    left.push(root);
    vector<int> res;

    while (!left.empty() || !right.empty()) {
      if (left.empty()) {
        res.push_back(right.top()->val);
        if (right.top()->right != NULL) {
          left.push(right.top()->right);
        }
        right.pop();
      } else {
        right.push(left.top());
        left.pop();
        if (right.top()->left != NULL) {
          left.push(right.top()->left);
        }
      }
    }

    return res;
  }
};