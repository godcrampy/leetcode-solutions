package main

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func threeSumClosest(nums []int, target int) int {
	res := nums[0] + nums[1] + nums[2]
	sort.Ints(nums)

	for l := 0; l < len(nums); l++ {
		r := len(nums) - 1
		m := l + 1

		for m < r {
			sum := nums[l] + nums[m] + nums[r]
			diff := abs(res - target)
			currentDiff := abs(sum - target)
			if currentDiff < diff {
				res = sum
			}

			if sum > target {
				r--
			} else {
				m++
			}
		}
	}

	return res
}
