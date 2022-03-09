package main

import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)
    fmt.Println((n + 1) % 7 + 1)
}
