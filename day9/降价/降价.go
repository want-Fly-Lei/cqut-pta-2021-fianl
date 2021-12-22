package main

import "fmt"

func main() {
	var n, m, i int16
	fmt.Scanln(&n, &m)
	var wantPrice = float64(m)
	var price float64
	for i = 0; i < n; i++ {
		fmt.Scanln(&price)
		if price < wantPrice {
			fmt.Printf("On Sale! %.1f\n", price)
		}
	}
}
