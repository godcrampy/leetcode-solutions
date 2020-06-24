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
  public List<Integer> postorder(Node root) {
    Stack<Node> stk = new Stack<>();
    List<Integer> res = new ArrayList<>();

    if (root == null) {
      return res;
    }

    stk.push(root);

    while (!stk.isEmpty()) {
      Node n = stk.pop();

      for (Node i : n.children) {
        stk.push(i);
      }
      res.add(n.val);
    }

    Collections.reverse(res);
    return res;
  }
}
