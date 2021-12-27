package main

import "fmt"

func main() {
	var n, i, j int8
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			if i == (n - j - 1) {
				fmt.Printf("1 ")
			} else if j >= (n - i) {
				fmt.Printf("2 ")
			} else {
				fmt.Printf("0 ")
			}
		}
		fmt.Println()
	}
}
