package main

import (
	"fmt"
	"math"
)

func main() {
	var i, j, n, num, num2 int
	var flag bool
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		fmt.Scanln(&num)
		flag = true
		if num < 2 {
			flag = false
		} else {
			num2 = int(math.Sqrt(float64(num)))
			for j = 2; j <= num2; j++ {
				if num % j == 0 {
					flag = false
					break
				}
			}
		}
		if flag {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}