package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func largestValues(root *TreeNode) []int {
	q := []*TreeNode{}
	res := []int{}

	if root == nil {
		return res
	}

	q = append(q, root)

	for len(q) != 0 {
		temp := []*TreeNode{}

		for len(q) != 0 {
			temp = append(temp, q[0])
			q = q[1:]
		}

		maxVal := temp[0].Val

		for _, node := range temp {
			if node.Val > maxVal {
				maxVal = node.Val
			}
			if node.Left != nil {
				q = append(q, node.Left)
			}

			if node.Right != nil {
				q = append(q, node.Right)
			}
		}

		res = append(res, maxVal)
	}

	return res
}
