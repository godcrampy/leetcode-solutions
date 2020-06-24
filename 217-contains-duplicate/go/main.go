package main

func containsDuplicate(nums []int) bool {
	s := make(map[int]bool)

	for _, val := range nums {
		if s[val] {
			return true
		}
		s[val] = true
	}

	return false
}
