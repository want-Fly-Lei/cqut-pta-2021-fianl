package main

import (
	"fmt"
)

type str struct {
	s     []byte
	leng  int8
	count int8
}

var S [1024]str

var (
	n, i, j int
	cou     int8
)

func getCount() {
	cou = 0
	S[i].leng = int8(len(S[i].s))
	for j = 0; j < int(S[i].leng); j++ {
		if S[i].s[j] >= '0' && S[i].s[j] <= '9' {
			cou++
		}
	}
	S[i].count = cou
}

func main() {
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		fmt.Scanln(&S[i].s)
		getCount()
	}
	for i = 0; i < n; i++ {
		fmt.Printf("%d", S[i].count)
		if i != n-1 {
			fmt.Println()
		}
	}
}
