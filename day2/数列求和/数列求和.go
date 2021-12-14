package main

import "fmt"

var (
	sum, temp int
)

func main() {
	fmt.Scanf("%d", &temp)
	for  temp != 0 {
		if temp > 0 {
			sum += temp
		}
	}
	fmt.Printf("%d",sum)
}
