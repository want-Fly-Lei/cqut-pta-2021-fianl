package main

import (
	"fmt"
	"math"
)
var (
	num,n,i,temp int
	count [1024]int
)
func main(){
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		temp = 0
		fmt.Scanln(&num)
		for num > 1 {
			num = int(math.Ceil(float64(num) / 2))
			temp++
		}
		count[i] = temp
	}
	for i = 0; i < n; i++ {
		fmt.Println(count[i])
	}
}