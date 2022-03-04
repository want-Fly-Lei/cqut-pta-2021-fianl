package main

import "fmt"

func main() {
	var i, n int
	fmt.Scanln(&n)
	var arr [][2]int = make([][2]int, n)
	var maxR, maxI int
	var tempR, tempI int
	for i = 0; i < n; i++ {
		fmt.Scanln(&tempR, &tempI)
		arr[i][0] = tempR
		arr[i][1] = tempI
		if tempR > maxR {
			maxR = tempR
			maxI = tempI
		}
	}
	var flag bool = true
	for flag {
		flag = false
		for i = 0; i < n; i++ {
			if maxI % arr[i][0] != arr[i][1] {
				flag = true
				break
			}
		}
		maxI += maxR
	}

	fmt.Println(maxI - maxR)
}
