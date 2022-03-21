package main

import "fmt"

func main() {
	const rate float64 = 1.09
	var i, n int
	var height float64
	var temp byte
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%c %f",&temp,&height)
		if temp == 'F' {
			fmt.Printf("%.2f\n",height * rate)
		} else {
			fmt.Printf("%.2f\n",height / rate)
		}
	}
}