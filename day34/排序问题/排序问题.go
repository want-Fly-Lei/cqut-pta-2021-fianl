package main

import (
	"fmt"
	"sort"
)

func main() {
	var i, n int
	fmt.Scanln(&n)
	var sli []int = make([]int, n)
	for i = 0; i < n; i++ {
		fmt.Scan(&sli[i])
	}
	sort.Ints(sli)
	for i = 0; i < n; i++ {
		fmt.Print(sli[i]," ")
	}
}