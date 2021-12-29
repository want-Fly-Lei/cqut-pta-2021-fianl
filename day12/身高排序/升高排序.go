package main

import (
	"fmt"
	"sort"
)

func main() {
	var i, n int8
	fmt.Scanln(&n)
	var sli []int = make([]int, n)
	for i = 0; i < n-1; i++ {
		fmt.Scanf("%d", &sli[i])
	}
	fmt.Scanln(&sli[i])
	sort.Ints(sli)
	for index, v := range sli {
		fmt.Print(v)
		if index != int(n) {
			fmt.Print(" ")
		} else {
			fmt.Println()
		}
	}
}
