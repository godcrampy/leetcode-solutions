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
  vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> q;  // bfs
    if (root == NULL) {
      return res;
    }
    q.push(root);

    while (!q.empty()) {
      vector<TreeNode*> level;
      while (!q.empty()) {
        level.push_back(q.front());
        q.pop();
      }
      int maxVal = level[0]->val;
      for (auto i : level) {
        maxVal = max(maxVal, i->val);
        if (i->left != NULL) {
          q.push(i->left);
        }
        if (i->right != NULL) {
          q.push(i->right);
        }
      }
      res.push_back(maxVal);
    }

    return res;
  }
};
