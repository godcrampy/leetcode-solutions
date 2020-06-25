package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func hasPathSum(root *TreeNode, sum int) bool {
	if root == nil {
		return false
	}

	nodeStack := []*TreeNode{}
	sumStack := []int{}

	nodeStack = append(nodeStack, root)
	sumStack = append(sumStack, 0)

	for len(nodeStack) != 0 {
		node := nodeStack[len(nodeStack)-1]
		nodeStack = nodeStack[:len(nodeStack)-1]

		sumSoFar := sumStack[len(sumStack)-1]
		sumStack = sumStack[:len(sumStack)-1]

		if node.Left == nil && node.Right == nil && sumSoFar+node.Val == sum {
			return true
		}

		if node.Left != nil {
			nodeStack = append(nodeStack, node.Left)
			sumStack = append(sumStack, sumSoFar+node.Val)
		}

		if node.Right != nil {
			nodeStack = append(nodeStack, node.Right)
			sumStack = append(sumStack, sumSoFar+node.Val)
		}
	}

	return false
}
