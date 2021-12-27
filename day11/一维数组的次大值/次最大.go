package main

import (
	"fmt"
)

func main() {
	var n int8
	fmt.Scanln(&n)
	var sli []int32 = make([]int32, n)
	var i int8
	for i = 0; i < n-1; i++ {
		fmt.Scanf("%d", &sli[i])
	}
	fmt.Scanln(&sli[i])
	var max, two int32
	max = sli[0]
	for i = 1; i < n; i++ {
		if sli[i] > max {
			two = max
			max = sli[i]
		} else if sli[i] > two && sli[i] != max{
			two = sli[i]
		}
	}
	fmt.Println(two)
}
