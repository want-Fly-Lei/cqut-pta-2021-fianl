package main

import "fmt"

func main() {
	var num int
	fmt.Scanln(&num)
	for i := 1; i <= num; i++ {
		fmt.Printf("%d.太平洋足够大，容得下中美两国发展。\n", i)
	}
}
