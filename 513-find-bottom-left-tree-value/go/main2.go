package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findBottomLeftValue(root *TreeNode) int {
	q := []*TreeNode{root}

	for len(q) != 0 {
		root = q[0]
		q = q[1:]

		if root.Right != nil {
			q = append(q, root.Right)
		}

		if root.Left != nil {
			q = append(q, root.Left)
		}
	}

	return root.Val
}
