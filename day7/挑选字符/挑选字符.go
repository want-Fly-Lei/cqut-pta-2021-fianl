package main

import "fmt"

func main() {
	var str string
	fmt.Scanln(&str)
	sli := []byte(str)
	for _, v := range sli {
		if (v >= '0') && (v <= '9') {
			fmt.Printf("%c", v)
		}
	}
}
