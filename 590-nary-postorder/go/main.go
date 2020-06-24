package main

/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func postorder(root *Node) []int {
	if root == nil {
		return []int{}
	}
	stack := []*Node{root}
	res := []int{}

	for len(stack) != 0 {
		n := stack[len(stack)-1]
		stack = stack[:len(stack)-1]

		for _, i := range n.Children {
			stack = append(stack, i)
		}

		res = append(res, n.Val)
	}

	// reverse
	l := 0
	r := len(res) - 1
	for l < r {
		res[l], res[r] = res[r], res[l]
		l++
		r--
	}

	return res
}
