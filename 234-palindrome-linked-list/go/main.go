package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return true
	}

	slow := head
	fast := head.Next

	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}

	if fast == nil {
		temp := head
		for temp.Next != slow {
			temp = temp.Next
		}
		temp.Next = nil
	}

	head2 := reverseList(slow.Next)
	slow.Next = nil

	for head != nil || head2 != nil {
		if head == nil || head2 == nil || head.Val != head2.Val {
			return false
		}
		head = head.Next
		head2 = head2.Next
	}

	return head == head2
}

func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	a := head
	b := a.Next
	c := b.Next

	a.Next = nil

	for b != nil {
		b.Next = a
		a = b
		b = c
		if c != nil {
			c = c.Next
		}
	}

	return a
}
