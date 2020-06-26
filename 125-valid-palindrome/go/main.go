package main

func isPalindrome(s string) bool {
	l := 0
	r := len(s) - 1

	for l <= r {
		for (l < len(s)-1) && !isAlphaNum(rune(s[l])) {
			l++
		}

		for (r >= 0) && !isAlphaNum(rune(s[r])) {
			r--
		}

		if l < r && toLower(rune(s[l])) != toLower(rune(s[r])) {
			return false
		}

		l++
		r--
	}

	return true
}

func isAlphaNum(c rune) bool {
	if (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') {
		return true
	}
	return false
}

func toLower(c rune) rune {
	if c >= 'A' && c <= 'Z' {
		return c + 'a' - 'A'
	}
	return c
}
