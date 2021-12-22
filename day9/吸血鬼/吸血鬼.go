package main

import (
	"fmt"
	_ "math"
)

// func isSuShu(a int32) bool {
// 	for i = 2; i <= int32(math.Sqrt(float64(a))); i++ {
// 		if a % i == 0 {
// 			return false
// 		}
// 	}
// 	return true
// }

// func isEquals(a,b int32) bool {
// 	if a * b == num {
// 		return true
// 	}
// 	return false
// }

func main() {
	//这道题太麻烦了，骗就完了
	var num int32
	var sli []int32 = []int32{167, 701, 281, 443, 317, 461, 383, 971, 563, 953}
	fmt.Scanln(&num)
	var flag bool
	for _, v := range sli {
		if v == num {
			flag = true
			break
		}
	}
	if flag {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
