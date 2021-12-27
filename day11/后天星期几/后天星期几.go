package main

import "fmt"

func main() {
	var day int8
	fmt.Scanln(&day)
	fmt.Println((day+1)%7 + 1)
}
