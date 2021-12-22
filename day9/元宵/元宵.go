package main

import "fmt"

func isOk5(num int32) bool {
	if num%5 == 0 {
		return true
	} else {
		return false
	}
}

func isOk7(num int32) bool {
	if num%7 == 2 {
		return true
	} else {
		return false
	}
}

// func isOk9(num int32) bool {
// 	if num % 9 == 4 {
// 		return true
// 	} else {
// 		return false
// 	}
// }

func main() {
	var n, i int8
	var num int32 = 4
	fmt.Scanln(&n)
	for i = 0; i < n; {
		for {
			num += 9
			if isOk5(num) && isOk7(num) {
				i++
				fmt.Printf("%d", num)
				if i != n {
					fmt.Printf(" ")
				}
				break
			}

		}
	}
}
