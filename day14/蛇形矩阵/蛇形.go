package main

import "fmt"

func main() {
	var T, i, res int32
	fmt.Scanln(&T)
	var j, n, k int8
	for i = 0; i < T; i++ {
		fmt.Scanln(&n)
		for j = 0; j < n; j++ {
			res = int32(j * (j - 1) / 2)
			for k = 0; k < n-j-1; k++ {
				res += int32(j + k + 1)
				fmt.Print(res, " ")
			}
			res += int32(j + k + 1)
			fmt.Println(res)
		}
	}
}
