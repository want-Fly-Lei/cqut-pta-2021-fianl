package main

import "fmt"

func main() {
	var n, length, i, j int
	var ch byte
	fmt.Scanf("%d %c", &n, &ch)
	length = n/2 + n%2
	for i = 0; i < length; i++ {
		for j = 0; j < n; j++ {
			fmt.Printf("%c", ch)
		}
		fmt.Println()
	}
}
