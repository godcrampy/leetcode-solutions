package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
	smallHead := &ListNode{Val: 0, Next: nil}
	bigHead := &ListNode{Val: 0, Next: nil}
	s := smallHead
	b := bigHead
	for head != nil {
		if head.Val < x {
			s.Next = head
			s = s.Next
		} else {
			b.Next = head
			b = b.Next
		}
		head = head.Next
	}

	s.Next = bigHead.Next
	b.Next = nil
	return smallHead.Next
}
