package main

import "fmt"

func main() {
	var mood [24]int8
	var i, temp int8
	for i = 0; i < 23; i++ {
		fmt.Scanf("%d", &mood[i])
	}
	fmt.Scanln(&mood[i])
	fmt.Scanln(&temp)
	for (0 <= temp) && (temp < 24) {
		fmt.Printf("%d ", mood[temp])
		if mood[temp] > 50 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
		fmt.Scanln(&temp)
	}
}
