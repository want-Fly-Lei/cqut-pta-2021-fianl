package main

import "fmt"

func main() {
	var m, n, i, sum, num int32
	fmt.Scanln(&m, &n)
	for i = 0; i < m-1; i++ {
		fmt.Scanf("%d", &num)
		num %= n
		sum += num
	}
	fmt.Scanln(&num)
	num %= n
	sum += num
	sum %= n
	fmt.Println(sum)
}
