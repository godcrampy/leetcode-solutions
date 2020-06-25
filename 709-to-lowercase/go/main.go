package main

func toLowerCase(str string) string {
	b := []byte(str)
	for i, c := range str {
		if c >= 'A' && c <= 'Z' {
			b[i] = uint8(c + 'a' - 'A')
		}
	}
	return string(b)
}
