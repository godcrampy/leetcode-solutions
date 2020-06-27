/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode() {}
 * ListNode(int val) { this.val = val; } ListNode(int val, ListNode next) { this.val = val;
 * this.next = next; } }
 */
class Solution {
  public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    ListNode d = new ListNode();
    ListNode i = d;

    while (l1 != null || l2 != null) {
      int a = l1 == null ? Integer.MAX_VALUE : l1.val;
      int b = l2 == null ? Integer.MAX_VALUE : l2.val;

      if (a < b) {
        i.next = l1;
        l1 = l1.next;
      } else {
        i.next = l2;
        l2 = l2.next;
      }
      i = i.next;
    }

    return d.next;
  }
}
