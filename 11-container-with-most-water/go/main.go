package main

func maxArea(height []int) int {
	l := 0
	r := len(height) - 1
	maxVolume := 0

	for l < r {
		minHeight := height[l]

		if height[r] < height[l] {
			minHeight = height[r]
		}

		currentVolume := (r - l) * minHeight

		if maxVolume < currentVolume {
			maxVolume = currentVolume
		}

		if height[l] < height[r] {
			l++
		} else {
			r--
		}
	}

	return maxVolume
}
