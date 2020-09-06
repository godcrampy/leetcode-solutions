# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head

        a = head
        b = head.next
        c = head.next.next
        a.next = None

        while b is not None:
            b.next = a
            a = b
            b = c

            if c is not None:
                c = c.next

        return a
