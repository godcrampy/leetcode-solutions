package main

func reverse(x int) int {
	var rev int64 = 0
	for x != 0 {
		rev = rev*10 + int64(x)%10
		x /= 10
	}

	if rev <= math.MaxInt32 && rev >= math.MinInt32 {
		return int(rev)
	}
	return 0
}
