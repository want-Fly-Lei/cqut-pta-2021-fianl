package main

import "fmt"

var (
	num, i, j int
)

func printIt() {
	for i = 0; i < num; i++ {
		if i <= num/2 {
			for j = 0; j < num/2-i; j++ {
				fmt.Printf(" ")
			}
			fmt.Printf("*")
			if i != 0 {
				for j = 0; j < 2*i-1; j++ {
					fmt.Printf(" ")
				}
				fmt.Printf("*")
			}
		} else {
			for j = 0; j < i-num/2; j++ {
				fmt.Printf(" ")
			}
			fmt.Printf("*")
			if i != num-1 {
				for j = 0; j < 2 * (num-i - 1) - 1; j++ {
					fmt.Printf(" ")
				}
				fmt.Printf("*")
			}
		}
		fmt.Println()
	}
}
func main() {
	fmt.Scanln(&num)
	if num%2 == 0 || num < 0 {
		fmt.Println("Error")
	} else {
		printIt()
	}
}
