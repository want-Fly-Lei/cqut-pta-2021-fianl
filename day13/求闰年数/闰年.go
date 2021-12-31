package main

import "fmt"

func main() {
	var year, count int32
	fmt.Scanln(&year)
	count = year / 4
	count -= (year / 100)
	count += (year / 400)
	fmt.Println(count)
}
