package main

func backspaceCompare(S string, T string) bool {
	l := len(S) - 1
	r := len(T) - 1
	s_skips := 0
	t_skips := 0

	for l >= 0 || r >= 0 {

		for (l >= 0) && (rune(S[l]) == '#' || s_skips > 0) {
			if rune(S[l]) == '#' {
				s_skips++
			} else {
				s_skips--
			}
			l--
		}

		for (r >= 0) && (rune(T[r]) == '#' || t_skips > 0) {
			if rune(T[r]) == '#' {
				t_skips++
			} else {
				t_skips--
			}
			r--
		}

		if l < 0 && r < 0 {
			return true
		}

		if l < 0 || r < 0 {
			return false
		}

		if S[l] != T[r] {
			return false
		}

		l--
		r--
	}

	return true
}
