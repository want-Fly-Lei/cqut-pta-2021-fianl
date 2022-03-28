package main

import "fmt"

func main() {
	const max, start, end int = 14, 2, 14
	var str []string = make([]string, max)
	var i int
	for i = 0; i < max; i++ {
		fmt.Scanln(&str[i])
		if str[i] == "." {
			break
		}
	}
	if str[start-1] == "" || str[start-1] == "." {
		fmt.Println("Momo... No one is for you ...")
	} else if str[end-1] == "" || str[end-1] == "." {
		fmt.Println(str[start-1], "is the only one for you...")
	} else {
		fmt.Printf("%v and %v are inviting you to dinner...\n", str[start-1], str[end-1])
	}
}
