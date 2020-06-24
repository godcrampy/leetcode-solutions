/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
  vector<int> preorder(Node* root) {
    if (root == NULL) {
      return {};
    }
    stack<Node*> stk;
    vector<int> res;
    stk.push(root);

    while (!stk.empty()) {
      auto node = stk.top();
      stk.pop();

      for (auto i = node->children.rbegin(); i != node->children.rend(); ++i) {
        stk.push(*i);
      }

      res.push_back(node->val);
    }

    return res;
  }
};