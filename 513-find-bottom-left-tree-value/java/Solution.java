/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode() {} TreeNode(int val) { this.val = val; } TreeNode(int val, TreeNode left,
 * TreeNode right) { this.val = val; this.left = left; this.right = right; } }
 */
class Solution {
  public class NodeDepth {
    public final TreeNode node;
    public final int depth;

    public NodeDepth(TreeNode node, int depth) {
      this.node = node;
      this.depth = depth;
    }
  }

  public int findBottomLeftValue(TreeNode root) {
    return (findBottomLeftAndDepth(root, 0).node.val);
  }

  public NodeDepth findBottomLeftAndDepth(TreeNode root, int depth) {
    boolean left = root.left != null;
    boolean right = root.right != null;
    TreeNode leftNode = null;
    TreeNode rightNode = null;
    int leftDepth = 0;
    int rightDepth = 0;

    if (left) {
      NodeDepth nd = findBottomLeftAndDepth(root.left, depth + 1);
      leftNode = nd.node;
      leftDepth = nd.depth;
    }

    if (right) {
      NodeDepth nd = findBottomLeftAndDepth(root.right, depth + 1);
      rightNode = nd.node;
      rightDepth = nd.depth;
    }

    if (!left && !right) {
      return new NodeDepth(root, depth);
    }

    if (!left) {
      return new NodeDepth(rightNode, rightDepth);
    }

    if (!right) {
      return new NodeDepth(leftNode, leftDepth);
    }

    if (rightDepth > leftDepth) {
      return new NodeDepth(rightNode, rightDepth);
    }
    return new NodeDepth(leftNode, leftDepth);
  }
}
