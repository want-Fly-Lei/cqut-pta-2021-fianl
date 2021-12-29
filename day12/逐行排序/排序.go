package main

import (
	"fmt"
	"sort"
)

func main() {
	var T, i int32
	var n, j, k int8
	var sli []int
	fmt.Scanln(&T)
	for i = 0; i < T; i++ {
		fmt.Scanln(&n)
		for j = 0; j < n; j++ {
			sli = make([]int, n)
			for k = 0; k < n-1; k++ {
				fmt.Scanf("%d", &sli[k])
			}
			fmt.Scanln(&sli[k])
			sort.Ints(sli)
			for k = 0; k < n-1; k++ {
				fmt.Print(sli[k])
				fmt.Print(" ")
			}
			fmt.Println(sli[k])
		}
	}
}
