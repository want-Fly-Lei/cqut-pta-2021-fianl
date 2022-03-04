package main

import (
	"fmt"
	"math"
)

func main() {
	var num, i, j, res, start, end int32
	fmt.Scanln(&num)
	end = -1
	var sq int32 = int32(math.Sqrt(float64(num)))
	//应该加到开方就应该停止了，不然运行超时
	for i = 2; i <= sq; i++ {
		if num%i == 0 {
			res = i
			for j = i + 1; j <= (num / i); j++ {
				if (num%(res*j) != 0) || (res*j > num) {
					break
				} else {
					res *= j
				}
			}
			if (j - i - 1) > (end - start) {
				end = j - 1
				start = i
			}
		}
	}
	if start == 0 {
		start = num
		end = num
	}
	fmt.Println(end - start + 1)
	i = start
	for ; i < end; i++ {
		fmt.Printf("%d*", i)
	}
	fmt.Printf("%d\n", i)
}
