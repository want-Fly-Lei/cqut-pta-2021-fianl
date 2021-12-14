package main

import "fmt"

var (
	num  int
	str  string
	st   []byte
	i, j int8
)

func showResult() {
	for i = int8(len(st)) - 1; i >= 0; i-- {
		j = int8(num % 10)
		st[i] += byte(j)
		num /= 10
	}
	for i = 0; i < int8(len(st)); i++ {
		fmt.Printf("%c", st[i])
	}
	fmt.Println()
}

func main() {
	for {
		fmt.Scanf("%d", &num)
		if num <= 0 {
			break
		}
		fmt.Scanln(&str)
		st = []byte(str)
		showResult()
	}
}
