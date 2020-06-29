package main

const UintMax = ^uint(0)
const IntMax = int(UintMax >> 1)

func sortedSquares(A []int) []int {
	positive := 0
	res := []int{}

	for positive < len(A) && A[positive] < 0 {
		positive++
	}

	negative := positive - 1

	for positive < len(A) || negative >= 0 {
		a := IntMax
		b := IntMax

		if positive < len(A) {
			a = A[positive] * A[positive]
		}

		if negative >= 0 {
			b = A[negative] * A[negative]
		}

		if a < b {
			res = append(res, a)
			positive++
		} else {
			res = append(res, b)
			negative--
		}
	}

	return res
}
