package main

import "fmt"

func main() {
	var i, n int
	var sum uint64
	fmt.Scanln(&n)
	var sli []uint64 = make([]uint64, n)
	sli[0] = 1
	sum = 1
	for i = 1; i < n; i++ {
		sli[i] = sli[i-1] * uint64(i+1)
		sum += sli[i]
	}
	fmt.Println(sum)
}
