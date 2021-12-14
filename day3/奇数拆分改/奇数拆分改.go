package main

import (
	"fmt"
	"math"
)

var (
	n               int8
	i, j, k, arrLen int32
	arr             [20]int32
	zhisu           [200]int32
	flag            bool
	count           int
)

func inItArr() {
	for j = 2; j < 1000; j++ {
		flag = true
		for k = 2; k <= int32(math.Sqrt(float64(j))); k++ {
			if j%k == 0 {
				flag = false
				break
			}
		}
		if flag {
			zhisu[i] = j
			i++
		}
	}
	arrLen = i
}

func getResult(num int32) {
	var maxIndex int32
	count = 0
	for j = 0; j < arrLen; j++ {
		if zhisu[j] > num {
			maxIndex = j
			break
		}
	}
	if num > zhisu[arrLen-1] {
		maxIndex = arrLen
	}
	for j = 0; j < maxIndex; j++ {
		for k = 0; k < maxIndex; k++ {
			for m := 0; m < int(maxIndex); m++ {
				if num == zhisu[j]+zhisu[k]+zhisu[m] {
					count++
				}
			}
		}
	}
	fmt.Printf("%d", count)
}

func main() {
	fmt.Scanln(&n)
	inItArr()
	var temp int32
	for i = 0; i < int32(n); i++ {
		fmt.Scanln(&temp)
		if temp > 0 && temp < 1000 && temp%2 != 0 {
			arr[i] = temp
		}
	}
	for i = 0; i < int32(n); i++ {
		getResult(arr[i])
		fmt.Println()

	}
}
