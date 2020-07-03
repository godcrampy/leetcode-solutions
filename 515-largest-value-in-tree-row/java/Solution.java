/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode left; TreeNode
 * right; TreeNode() {} TreeNode(int val) { this.val = val; } TreeNode(int val, TreeNode left,
 * TreeNode right) { this.val = val; this.left = left; this.right = right; } }
 */
class Solution {
  public List<Integer> largestValues(TreeNode root) {
    List<Integer> res = new ArrayList<>();
    if (root == null) {
      return res;
    }
    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);

    while (!q.isEmpty()) {
      List<TreeNode> temp = new ArrayList<>();
      while (!q.isEmpty()) {
        temp.add(q.remove());
      }

      int maxNum = temp.get(0).val;

      for (TreeNode t : temp) {
        maxNum = Math.max(maxNum, t.val);
        if (t.left != null) {
          q.add(t.left);
        }

        if (t.right != null) {
          q.add(t.right);
        }
      }

      res.add(maxNum);
    }

    return res;
  }
}
