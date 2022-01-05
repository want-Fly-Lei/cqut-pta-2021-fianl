package main

import "fmt"

func main() {
	const size int8 = 46
	var n, i int32
	fmt.Scanln(&n)
	var temp,j int8
	var sli []uint64 = make([]uint64, size)
	sli[0] = 1
	sli[1] = 1
	for j = 2; j < size; j++ {
		sli[j] = sli[j - 1] + sli[j - 2]
	}
	for i = 0; i < n; i++ {
		fmt.Scanln(&temp)
		fmt.Println(sli[temp-1])
	}
}