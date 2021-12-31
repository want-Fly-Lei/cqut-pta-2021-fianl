package main

import (
	"fmt"
	"math/big"
)

func main() {
	var n, i, num int16
	const size int16 = 1001
	var sli []big.Int = make([]big.Int, size)
	sli[0] = *big.NewInt(1)
	sli[1] = *big.NewInt(1)
	var res *big.Int
	for i = 2; i < size; i++ {
		//学艺不精，不知道为什么每一次下面这个必须放在循环里面
		res = new(big.Int)
		sli[i] = *res.Add(&sli[i - 1],&sli[i - 2])
	}
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		fmt.Scanln(&num)
		fmt.Println(&sli[num-1])
	}
}
