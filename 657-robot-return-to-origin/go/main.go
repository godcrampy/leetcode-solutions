package main

func judgeCircle(moves string) bool {
	x := 0
	y := 0
	for _, c := range moves {
		switch move := rune(c); move {
		case 'U':
			y++
		case 'D':
			y--
		case 'L':
			x++
		case 'R':
			x--
		}
	}

	return x == 0 && y == 0
}
