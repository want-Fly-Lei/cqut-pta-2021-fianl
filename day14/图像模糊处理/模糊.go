package main

import "fmt"

func main() {
	var i, j, m, n int8
	var sum int16
	fmt.Scanln(&m, &n)
	var sli [][]int16 = make([][]int16, m)
	for i = 0; i < m; i++ {
		sli[i] = make([]int16, n)
		for j = 0; j < n-1; j++ {
			fmt.Scanf("%d", &sli[i][j])
		}
		fmt.Scanln(&sli[i][j])
	}
	for i = 0; i < m; i++ {
		for j = 0; j < n-1; j++ {
			if (i == 0) || (j == 0) || (i == m-1) {
				fmt.Print(sli[i][j])
			} else {
				sum = sli[i-1][j] + sli[i+1][j] + sli[i][j-1] + sli[i][j+1] + sli[i][j]
				if sum%5 > 2 {
					sum = sum/5 + 1
				} else {
					sum /= 5
				}
				fmt.Print(sum)
			}
			fmt.Print(" ")
		}
		fmt.Println(sli[i][j])
	}
}
