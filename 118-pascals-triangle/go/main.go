package main

func generate(numRows int) [][]int {
	if numRows == 0 {
		return [][]int{}
	}

	res := [][]int{{1}}

	for i := 2; i <= numRows; i++ {
		temp := []int{1}
		last := res[len(res)-1]

		for j := 1; j < i-1; j++ {
			temp = append(temp, last[j-1]+last[j])
		}

		temp = append(temp, 1)
		res = append(res, temp)
	}

	return res
}
