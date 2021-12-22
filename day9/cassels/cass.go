package main

import "fmt"

func isRight(a, b, c int16) bool {
	if (a*a + b*b + c*c) == (3 * a * b * c) {
		return true
	} else {
		return false
	}
}

func main() {
	var n, i int8
	fmt.Scanln(&n)
	var x, y, z int16
	var isOk []bool = make([]bool, n)
	for i = 0; i < n; i++ {
		fmt.Scanln(&x, &y, &z)
		isOk[i] = isRight(x, y, z)
	}
	for _, v := range isOk {
		if v {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
