package main

import "fmt"

func printSpaceNum(num int) {
	for i := 0; i < num; i++ {
		fmt.Print(" ")
	}
}
func printNum(num int) {
	fmt.Printf("%4d", num)
}

func main() {
	var i, j, n int
	var sli [6][6]int
	for i = 0; i < 6; i++ {
		sli[i][0] = 1
		sli[i][i] = 1
	}
	sli[2][1] = 2
	sli[3][1] = 3
	sli[3][2] = 3
	sli[4][1] = 4
	sli[4][2] = 6
	sli[4][3] = 4
	sli[5][1] = 5
	sli[5][2] = 10
	sli[5][3] = 10
	sli[5][4] = 5
	n = 6
	for i = 0; i < n; i++ {
		printSpaceNum(2*(n - i - 1))
		for j = 0; j <= i; j++ {
			printNum(sli[i][j])
			//fuck 不是说中间空三个格子吗，我*******
			//printSpaceNum(3)
		}
		fmt.Println()
	}
}
