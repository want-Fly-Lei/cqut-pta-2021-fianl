package main

import "fmt"

func main() {
	const size int8 = 10
	var n, i, j, value int8
	fmt.Scanln(&n)
	var sli [][]int8 = make([][]int8, n)
	for i = 0; i < n; i++ {
		sli[i] = make([]int8, n-i)
		for j = 0; j < n-i; j++ {
			sli[i][j] = value
			value = (value + 1) % size
		}
	}
	//fmt.Println(sli)
	for i = 0; i < n; i++ {
		for j = 0; j <= i; j++ {
			fmt.Printf("%d ", sli[j][n-i-1])
		}
		fmt.Println()
	}
}
