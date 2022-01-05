package main

import "fmt"

func main() {
	var i, T int32
	var n, j, k int8
	var sli [][]int32
	var flag bool
	fmt.Scanln(&T)
	for i = 0; i < T; i++ {
		flag = true
		fmt.Scanln(&n)
		sli = make([][]int32, n)
		for j = 0; j < n; j++ {
			sli[j] = make([]int32, n)
			for k = 0; k < n-1; k++ {
				fmt.Scanf("%d", &sli[j][k])
			}
			fmt.Scanln(&sli[j][k])
		}
		for j = 0; j < n; j++ {
			for k = 0; k < n; k++ {
				if (sli[j][k] != sli[j][n-k-1]) || (sli[j][k] != sli[n-j-1][k]) {
					flag = false
					break
				}
			}
			if !flag {
				break
			}
		}
		if flag {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}
