package main

import "fmt"

func main() {
	var n, i, temp int32
	fmt.Scanln(&n)
	var arr [30][2]int32
	var flag [30]bool
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &arr[i][0])
		fmt.Scanln(&arr[i][1])
		temp = arr[i][0] & arr[i][1]
		if temp != 0 {
			flag[i] = true
		}
	}
	for i = 0; i < n; i++ {
		if flag[i] {
			fmt.Println("No")
		} else {
			fmt.Println("Yes")
		}
	}
}
