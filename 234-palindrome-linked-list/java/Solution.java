/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode() {}
 * ListNode(int val) { this.val = val; } ListNode(int val, ListNode next) { this.val = val;
 * this.next = next; } }
 */
class Solution {
  public boolean isPalindrome(ListNode head) {
    if (head == null || head.next == null) {
      return true;
    }
    ListNode slow = head;
    ListNode fast = head.next;

    while (fast != null && fast.next != null) {
      slow = slow.next;
      fast = fast.next.next;
    }

    if (fast == null) {
      // slow
      ListNode temp = head;
      while (temp.next != slow) {
        temp = temp.next;
      }
      temp.next = null;
    }

    ListNode head2 = reverseList(slow.next);
    slow.next = null;

    while (head != null || head2 != null) {
      if (head == null || head2 == null || head.val != head2.val) {
        return false;
      }
      head = head.next;
      head2 = head2.next;
    }

    return head == null && head2 == null;
  }

  public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) {
      return head;
    }

    ListNode a = head;
    ListNode b = head.next;
    ListNode c = head.next.next;

    a.next = null;

    while (b != null) {
      b.next = a;
      a = b;
      b = c;
      if (c != null) {
        c = c.next;
      }
    }

    return a;
  }
}
