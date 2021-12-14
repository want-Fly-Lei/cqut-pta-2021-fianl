package main

import "fmt"

func main() {
	var n, i int32
	fmt.Scanln(&n)
	for i = 0; i <= n/2; i++ {
		fmt.Printf("%d+%d=%d\n", i, n-i, n)
	}
}
