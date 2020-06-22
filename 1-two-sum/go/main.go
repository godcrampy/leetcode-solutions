package main

func twoSum(nums []int, target int) []int {
	m := make(map[int]int) // number: index

	for i, n := range nums {
		// find if complement exists
		c := target - n
		if val, ok := m[c]; ok {
			return []int{val, i}
		}
		m[n] = i
	}

	return []int{0, 0}
}
