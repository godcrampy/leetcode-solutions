package main

func isNStraightHand(hand []int, W int) bool {
	n := len(hand)

	if n%W != 0 {
		return false
	}

	size := n / W
	grid := make([][]int, size)
	sort.Ints(hand)

	for _, c := range hand {
		i := 0
		for ; i < size; i++ {
			if len(grid[i]) == W {
				continue
			}
			last := len(grid[i]) - 1
			if last == -1 || grid[i][last]+1 == c {
				grid[i] = append(grid[i], c)
				break
			}
		}
		if i == size {
			return false
		}
	}

	return true
}
