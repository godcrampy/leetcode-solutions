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
  vector<int> postorder(Node* root) {
    if (root == NULL) {
      return {};
    }
    stack<Node*> one, two;
    one.push(root);

    while (!one.empty()) {
      auto node = one.top();
      two.push(node);
      one.pop();

      for (auto n : node->children) {
        one.push(n);
      }
    }

    vector<int> res;
    while (!two.empty()) {
      res.push_back(two.top()->val);
      two.pop();
    }

    return res;
  }

  // Alternative Solution
  void postorderRecursive(Node* root, vector<int>& res) {
    if (root == NULL) {
      return;
    }

    for (auto n : root->children) {
      postorderRecursive(n, res);
    }

    res.push_back(root->val);
  }
};
