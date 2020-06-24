/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode() {} TreeNode(int val) { this.val = val; } TreeNode(int val, TreeNode left,
 * TreeNode right) { this.val = val; this.left = left; this.right = right; } }
 */
class Solution {
  public List<Integer> inorderTraversal(TreeNode root) {
    Stack<TreeNode> one = new Stack<>(), two = new Stack<>();
    List<Integer> res = new ArrayList<>();

    if (root == null) {
      return res;
    }

    one.push(root);

    while (!one.isEmpty() || !two.isEmpty()) {
      if (one.isEmpty()) {
        TreeNode n = two.pop();
        res.add(n.val);
        if (n.right != null) {
          one.push(n.right);
        }
      } else {
        TreeNode n = one.pop();
        two.push(n);

        if (n.left != null) {
          one.push(n.left);
        }
      }
    }

    return res;
  }
}
