package main

import "fmt"

func showResult(num int16) {
	var j int16
	fmt.Printf("%d=", num)
	for j = 2; j <= num; {
		if num%j == 0 {
			fmt.Print(j)
			if num != j {
				fmt.Printf("*")
			}
			num /= j
		} else {
			j++
		}
	}
}

func main() {
	var a, b, i int16
	fmt.Scanln(&a, &b)
	for i = a; i <= b; i++ {
		showResult(i)
		fmt.Println()
	}
}
