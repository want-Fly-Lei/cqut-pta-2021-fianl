package main

import (
	"fmt"
	"strconv"
)

func main() {
	var i, n int32
	var temp int
	var str string
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		fmt.Scanln(&temp)
		str = strconv.Itoa(temp)
		fmt.Println(str)
	}
}
