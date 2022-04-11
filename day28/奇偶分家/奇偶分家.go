package main

import "fmt"

func main() {
	var odd, event, n, i, temp int
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &temp)
		if temp%2 == 0 {
			odd++
		} else {
			event++
		}
	}
	fmt.Println(event, odd)
}
