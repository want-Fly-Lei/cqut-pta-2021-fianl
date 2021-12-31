package main

import "fmt"

func main() {
	const size int8 = 26
	var letter byte
	var key int32
	fmt.Scanf("%c", &letter)
	fmt.Scanln(&key)
	letter -= 'a'
	key %= int32(size)
	if key < 0 {
		key += int32(size)
	}
	letter = (letter + byte(key)) % byte(size)
	fmt.Printf("%c\n", letter+'a')
}
