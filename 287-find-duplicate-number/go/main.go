package main

func findDuplicate(nums []int) int {
	s := 0
	f := 0
	s = nums[s]
	f = nums[nums[f]]

	for s != f {
		s = nums[s]
		f = nums[nums[f]]
	}

	s = 0

	for s != f {
		s = nums[s]
		f = nums[f]
	}

	return f
}
