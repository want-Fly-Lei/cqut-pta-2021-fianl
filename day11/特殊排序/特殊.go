package main

import (
	"fmt"
	"sort"
)

func main() {
	var i, T, temp int
	fmt.Scanln(&T)
	var n, j int8
	var odd, event []int
	for i = 0; i < T; i++ {
		fmt.Scanf("%d", &n)
		//清空切片，没事耍用两种方式清
		odd = make([]int, 0)
		event = event[0:0]
		for j = 0; j < n-1; j++ {
			fmt.Scanf("%d", &temp)
			if (temp % 2) == 0 {
				event = append(event, temp)
			} else {
				odd = append(odd, temp)
			}
		}
		fmt.Scanln(&temp)
		if (temp % 2) == 0 {
			event = append(event, temp)
		} else {
			odd = append(odd, temp)
		}
		sort.Ints(event)
		sort.Ints(odd)
		for j = 0; j < int8(len(odd)); j++ {
			fmt.Printf("%d", odd[j])
			if j != int8(len(odd)-1) {
				fmt.Printf(" ")
			}
		}
		if len(event) == 0 {
			fmt.Println()
		} else {
			fmt.Printf(" ")
			for j = 0; j < int8(len(event)); j++ {
				fmt.Printf("%d", event[j])
				if j == int8(len(event)-1) {
					fmt.Println()
				} else {
					fmt.Printf(" ")
				}
			}
		}
	}
}
