package main

import "fmt"

func main() {
	var num, i, j int32
	fmt.Scanln(&num)
	var sli [][]int32 = make([][]int32, num)
	//为了不浪费空间
	for i = 0; i < num; i++ {
		sli[i] = make([]int32, i+1)
	}
	for i = 0; i < num; i++ {
		for j = 0; j <= i; j++ {
			if (j == 0) || (i == j) {
				sli[i][j] = 1
			} else {
				sli[i][j] = sli[i-1][j] + sli[i-1][j-1]
			}
			fmt.Printf("%-4d", sli[i][j])
		}
		fmt.Println()
	}
}
