package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pruneTree(root *TreeNode) *TreeNode {
	if pruneTreeAndReturn(root) {
		return root
	}
	return nil
}

func pruneTreeAndReturn(root *TreeNode) bool {
	if root == nil {
		return false
	}

	self := root.Val == 1
	left := pruneTreeAndReturn(root.Left)
	right := pruneTreeAndReturn(root.Right)

	if !left {
		root.Left = nil
	}

	if !right {
		root.Right = nil
	}

	return self || left || right
}
