package main

import "fmt"

var (
	num1, num2, count, i, j, sum int32
)

func isOk(a int32) bool {
	sum = 0
	for j = 1; j <= a/2; j++ {
		if a%j == 0 {
			sum += j
		}
	}
	if sum == a {
		return true
	} else {
		return false
	}
}
func main() {
	fmt.Scanf("%d", &num1)
	fmt.Scanln(&num2)
	for i = num1; i <= num2; i++ {
		if isOk(i) {
			count++
		}
	}
	fmt.Println(count)
}
