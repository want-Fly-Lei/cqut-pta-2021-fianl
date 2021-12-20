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
	var st []byte = getInput()
	var n = len(st)
	n--
	for n > -1 {
		fmt.Printf("%c", st[n])
		n--
	}
}
