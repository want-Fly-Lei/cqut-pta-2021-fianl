package main

import (
	"fmt"
)

func main() {
	var grade [50]int8
	var i, j, n int8
	var flag bool
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &grade[i])
	}
	for i = 0; i < n-1; i++ {
		flag = true
		for j = 0; j < n-i-1; j++ {
			if grade[j+1] > grade[j] {
				grade[j+1] ^= grade[j]
				grade[j] ^= grade[j+1]
				grade[j+1] ^= grade[j]
				flag = false
			}
		}
		if flag {
			break
		}
	}
	for i = 0; i < n; i++ {
		fmt.Printf("%d", grade[i])
		if i != n-1 {
			fmt.Printf(" ")
		}
	}
}
