package main

import (
	"fmt"
	"math/big"
)

const (
	MAXSIZE int = 1000
)

var (
	fibs []big.Int//储存大数的bigint
	res *big.Int
	n, i, temp int
)

func main() {
	fmt.Scanln(&n)
	fibs = make([]big.Int, MAXSIZE)
	fibs[0] = *big.NewInt(1)
	fibs[1] = *big.NewInt(1)
	for i = 2; i < MAXSIZE; i++ {
		res = new(big.Int)
		fibs[i] = *res.Add(&fibs[i- 1],&fibs[i - 2])
	}
	for i = 0; i < n; i++ {
		fmt.Scanln(&temp)
		fmt.Println(&fibs[temp - 1])
	}
}