package main

import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)
	var num [1000]int
	var i int
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &num[i])
	}
	var min int = -1
	for i = 0; i < n; i++ {
		if num[i] > 0 {
			if min == -1 {
			if num[i] > 0 {
				min = num[i]
			}
		} else {
			if num[i] < min {
				min = num[i]
			}
		}
		}
	}
	if min != -1 {
		fmt.Printf("%d", min)
	} else {
		fmt.Printf("not found")
	}
}