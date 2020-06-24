package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil || (*head).Next == nil {
		return head
	}

	a := head
	b := (*head).Next
	c := (*b).Next

	(*a).Next = nil

	for b != nil {
		(*b).Next = a
		a = b
		b = c
		if c != nil {
			c = (*c).Next
		}
	}

	return a
}
