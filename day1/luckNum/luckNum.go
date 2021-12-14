package main

import "fmt"

var num int = 59084709587505
var luckNum [3]int = [3]int{3, 5, 7}
var arr [2000]int

func main() {
	arr[0] = 3
	arr[1] = 5
	arr[2] = 7
	arr[3] = 9
	arr[4] = 15
	arr[5] = 21
	arr[6] = 25
	arr[7] = 27
	arr[8] = 35
	arr[9] = 45
	arr[10] = 49
	var min int
	var temp int
	for i := 11; i <= 2000; i++ {
		min = arr[i-1] * 3
		for j := 0; j < i-1; j++ {
			for k := 0; k < 3; k++ {
				temp = arr[j] * luckNum[k]
				if (temp > arr[i-1]) && (temp < min) {
					min = temp
				}
			}
		}
		arr[i] = min
		if min == num {
			fmt.Printf("%d", i+1)
			break
		}
	}
}
