package main

import "fmt"

func main() {
	var min, temp, max int
	fmt.Scanf("%d", &temp)
	min = temp
	max = temp
	for temp >= 0 {
		if temp > max {
			max = temp
		}
		if temp < min {
			min = temp
		}
		fmt.Scanf("%d", &temp)
	}
	fmt.Printf("max=%d,min=%d", max, min)
}
