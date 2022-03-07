package main

import (
	"fmt"
	"sort"
)

func main() {
	var arr []int = make([]int, 3)
	var i int
	for i = 0; i < 2; i++ {
		fmt.Scanf("%d", &arr[i])
	}
	fmt.Scanln(&arr[i])
	sort.Ints(arr)
	for i = 0; i < 2; i++ {
		fmt.Printf("%d->", arr[i])
	}
	fmt.Print(arr[i])
}
