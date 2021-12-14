package main

import "fmt"

func main() {
	var arr [20]int32
	var size, num, i int32
	fmt.Scanf("%d", &size)
	fmt.Scanln(&num)
	for i = 0; i < size; i++ {
		fmt.Scanf("%d", &arr[i])
	}
	for i = 0; i < size; i++ {
		if num == arr[i] {
			break
		}
	}
	if i == size {
		fmt.Printf("Not found %d\n", num)
	} else {
		fmt.Printf("Found %d at %d\n", num, i)
	}
}
