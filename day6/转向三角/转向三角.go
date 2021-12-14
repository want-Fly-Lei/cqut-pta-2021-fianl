package main

import "fmt"

var (
	T, i    int8
	j, k, n int32
)

func main() {
	fmt.Scanln(&T)
	for i = 0; i < T; i++ {
		fmt.Scanln(&n)
		for j = 0; j < n; j++ {
			for k = 0; k <= j; k++ {
				fmt.Printf("%d", j+1)
			}
			fmt.Println()
		}
		j -= 2
		for ; j >= 0; j-- {
			for k = 0; k <= j; k++ {
				fmt.Printf("%d", j+1)
			}
			fmt.Println()
		}
	}
}
