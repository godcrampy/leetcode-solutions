/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode() {}
 * ListNode(int val) { this.val = val; } ListNode(int val, ListNode next) { this.val = val;
 * this.next = next; } }
 */
class Solution {
  public ListNode partition(ListNode head, int x) {
    ListNode left = new ListNode();
    ListNode right = new ListNode();
    ListNode leftI = left;
    ListNode rightI = right;

    while (head != null) {
      if (head.val < x) {
        leftI.next = head;
        leftI = leftI.next;
      } else {
        rightI.next = head;
        rightI = rightI.next;
      }
      head = head.next;
    }

    rightI.next = null;
    leftI.next = right.next;
    return left.next;
  }
}
