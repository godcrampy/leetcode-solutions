package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	d := &ListNode{Val: 0, Next: head}
	a := d
	b := d.Next

	for b != nil && b.Next != nil {
		a.Next = b.Next
		b.Next = a.Next.Next
		a.Next.Next = b
		a = a.Next.Next
		b = b.Next
	}

	return d.Next
}
