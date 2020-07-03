/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode() {} TreeNode(int val) { this.val = val; } TreeNode(int val, TreeNode left,
 * TreeNode right) { this.val = val; this.left = left; this.right = right; } }
 */
class Solution {
  public TreeNode pruneTree(TreeNode root) {
    if (pruneAndFind(root)) {
      return root;
    }
    return null;
  }

  public boolean pruneAndFind(TreeNode root) {
    if (root == null) {
      return false;
    }

    boolean self = root.val == 1;
    boolean left = pruneAndFind(root.left);
    boolean right = pruneAndFind(root.right);

    if (!left) {
      root.left = null;
    }

    if (!right) {
      root.right = null;
    }

    return self || left || right;
  }
}
