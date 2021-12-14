package main

import (
	"fmt"
	"sort"
)

var (
	n, i int16
	arr  []int
)

func main() {
	fmt.Scanln(&n)
	arr = make([]int, n)
	for i = 0; i < n-1; i++ {
		fmt.Scanf("%d", &arr[i])
	}
	fmt.Scanln(&arr[i])
	sort.Ints(arr)
	for i = 0; i < n; i++ {
		if arr[i] <= 0 {
			continue
		}
		fmt.Printf("%d", arr[i])
		break
	}
	if i == n {
		fmt.Printf("not found")
	}
}
