package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type NodeDepth struct {
	Node  *TreeNode
	Depth int
}

func findBottomLeftValue(root *TreeNode) int {
	return findBottomLeftAndDepth(root, 0).Node.Val
}

func findBottomLeftAndDepth(root *TreeNode, depth int) NodeDepth {
	left := false
	right := false
	leftDepth := 0
	rightDepth := 0
	var leftNode *TreeNode
	var rightNode *TreeNode

	if root.Left != nil {
		left = true
		nd := findBottomLeftAndDepth(root.Left, depth+1)
		leftDepth = nd.Depth
		leftNode = nd.Node
	}

	if root.Right != nil {
		right = true
		nd := findBottomLeftAndDepth(root.Right, depth+1)
		rightDepth = nd.Depth
		rightNode = nd.Node
	}

	if left && right {
		if rightDepth > leftDepth {
			return NodeDepth{Node: rightNode, Depth: rightDepth}
		} else {
			return NodeDepth{Node: leftNode, Depth: leftDepth}
		}
	}

	if left {
		return NodeDepth{Node: leftNode, Depth: leftDepth}
	}

	if right {
		return NodeDepth{Node: rightNode, Depth: rightDepth}
	}

	return NodeDepth{Node: root, Depth: depth}
}
