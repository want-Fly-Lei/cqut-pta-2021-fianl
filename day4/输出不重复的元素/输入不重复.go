package main

import "fmt"

func main() {
	var num [20]int32
	var i, j, n int32
	fmt.Scanln(&n)
	for i = 0; i < n-1; i++ {
		fmt.Scanf("%d", &num[i])
	}
	fmt.Scanln(&num[i])
	for i = 0; i < n; i++ {
		for j = i + 1; j < n; {
			if num[i] == num[j] {
				num[j] ^= num[n-1]
				num[n-1] ^= num[j]
				num[j] ^= num[n-1]
				n--
			} else {
				j++
			}
		}
	}
	for i = 0; i < n-1; i++ {
		fmt.Printf("%d ", num[i])
	}
	fmt.Printf("%d", num[i])
}
