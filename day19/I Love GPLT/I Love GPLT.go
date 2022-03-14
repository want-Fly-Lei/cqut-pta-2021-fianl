package main

import "fmt"

var str string = "I Love GPLT"

func main() {
	for _, v := range str {
		fmt.Printf("%c\n",v)
	}
}