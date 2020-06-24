/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  public List<Integer> preorder(Node root) {
    List<Integer> res = new ArrayList<>();

    if (root == null) {
      return res;
    }

    Stack<Node> stk = new Stack<>();
    stk.push(root);

    while (!stk.isEmpty()) {
      Node n = stk.pop();
      res.add(n.val);

      for (int i = n.children.size() - 1; i >= 0; --i) {
        stk.push(n.children.get(i));
      }
    }

    return res;
  }
}
