/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode() {} TreeNode(int val) { this.val = val; } TreeNode(int val, TreeNode left,
 * TreeNode right) { this.val = val; this.left = left; this.right = right; } }
 */
class Solution2 {
  public boolean hasPathSum(TreeNode root, int sum) {
    if (root == null) {
      return false;
    }

    Stack<TreeNode> nodes = new Stack<>();
    Stack<Integer> sums = new Stack<>();

    nodes.add(root);
    sums.add(0);

    while (!nodes.isEmpty()) {
      TreeNode node = nodes.pop();
      int sumSoFar = sums.pop();

      if (node.left == null && node.right == null && node.val + sumSoFar == sum) {
        return true;
      }

      if (node.left != null) {
        nodes.add(node.left);
        sums.add(sumSoFar + node.val);
      }

      if (node.right != null) {
        nodes.add(node.right);
        sums.add(sumSoFar + node.val);
      }
    }

    return false;
  }
}
