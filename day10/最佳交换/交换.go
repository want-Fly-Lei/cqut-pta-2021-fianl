package main

import (
	"fmt"
	"sort"
)

func main() {
	var m, n, i int8
	fmt.Scanln(&m, &n)
	var sli []int = make([]int, n)
	for i = 0; i < n-1; i++ {
		fmt.Scanf("%d", &sli[i])
	}
	fmt.Scanln(&sli[i])
	sort.Ints(sli)
	var sum int
	for i = 0; i < m; i++ {
		sum += sli[n-i-1] - sli[i]
	}
	fmt.Println(sum)
}
