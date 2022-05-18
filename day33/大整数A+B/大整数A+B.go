package main

import (
	"fmt"
	"math/big"
)

func main() {
	var n, i int
	fmt.Scanln(&n)
	var str1, str2 string
	var temp1, temp2, sum *big.Int
	temp1 = new(big.Int)
	temp2 = new(big.Int)
	for i = 0; i < n; i++ {
		fmt.Scanln(&str1,&str2)
		fmt.Printf("Case %d:\n", i + 1)
		temp1.SetString(str1,10)
		temp2.SetString(str2,10)
		sum = new(big.Int)
		sum.Add(temp1,temp2)
		//fmt.Println(str1,"+",str2,"=",sum)
		fmt.Printf("%v + %v = %v\n",str1, str2,sum)
		if i != n - 1 { //真麻烦还要要求格式
			fmt.Print("\n")
		}
	}
}