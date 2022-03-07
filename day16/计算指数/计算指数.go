package main

import (
	"fmt"
	"math"
)

func main() {
	var num int
	fmt.Scanln(&num)
	fmt.Printf("2^%d = %d", num, int(math.Pow(2, float64(num))))
}
