package main

import "fmt"

var i int
var index int = -1

func main() {
	var len, num int
	fmt.Scanln(&len, &num)
	var arr [20]int
	for i = 0; i < len; i++ {
		fmt.Scanf("%d", &arr[i])
	}

	for i = 0; i < len; i++ {
		if arr[i] == num {
			index = i
			break
		}
	}

	if index != -1 {
		fmt.Printf("Found %d at %d", num, index)
	} else {
		fmt.Printf("Not found %d", num)
	}
}
