package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

const MaxUint = ^uint(0)
const MaxInt = int(MaxUint >> 1)

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	d := &ListNode{Val: 0, Next: nil}
	i := d

	for l1 != nil || l2 != nil {
		a := MaxInt
		b := MaxInt

		if l1 != nil {
			a = l1.Val
		}

		if l2 != nil {
			b = l2.Val
		}

		if a < b {
			i.Next = l1
			l1 = l1.Next
		} else {
			i.Next = l2
			l2 = l2.Next
		}

		i = i.Next
	}

	return d.Next
}
