package main

import (
	"fmt"
	"math/big"
)

func main() {
	var i, n int32
	fmt.Scanln(&n)
	var str1, str2 string
	var num1, num2, res, sum *big.Int
	num1 = new(big.Int)
	num2 = new(big.Int)
	for i = 0; i < n; i++ {
		fmt.Scanln(&str1, &str2)
		res = new(big.Int)
		num1.SetString(str1, 10)
		num2.SetString(str2, 10)
		sum = res.Add(num1, num2)
		fmt.Println(sum)
	}
}
