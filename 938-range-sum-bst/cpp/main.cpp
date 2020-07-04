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
  int rangeSumBST(TreeNode* root, int L, int R) {
    if (root == NULL) {
      return 0;
    }
    int val = root->val;
    int sum = val >= L && val <= R ? val : 0;

    if (val > L) {
      sum += rangeSumBST(root->left, L, R);
    }

    if (val < R) {
      sum += rangeSumBST(root->right, L, R);
    }

    return sum;
  }
};
