package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}

	left := []*TreeNode{root}
	right := []*TreeNode{}
	res := []int{}

	for len(left) != 0 || len(right) != 0 {
		if len(left) == 0 {
			top := right[len(right)-1]
			right = right[:len(right)-1]
			res = append(res, top.Val)
			if top.Right != nil {
				left = append(left, top.Right)
			}
		} else {
			top := left[len(left)-1]
			left = left[:len(left)-1]
			right = append(right, top)
			if top.Left != nil {
				left = append(left, top.Left)
			}
		}
	}

	return res
}
