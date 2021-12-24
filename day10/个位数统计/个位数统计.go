package main

import (
	"bufio"
	"fmt"
	"os"
)

func getInput() []byte {
	in := bufio.NewReader(os.Stdin)
	str, _, err := in.ReadLine()
	if err != nil {
		return []byte(err.Error())
	}
	return []byte(str)
}
func main() {
	str := getInput()
	var numCount [10]int32
	for _, v := range str {
		numCount[v-'0']++
	}
	for v,w := range numCount {
		if w != 0 {
			fmt.Printf("%d:%d\n", v, w)
		}
	}
}
