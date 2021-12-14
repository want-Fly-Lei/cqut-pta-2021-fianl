package main

import "fmt"

var (
	arr       [6][6]int
	i, j      int8
	n         int8
	flag      bool = false
	row, line int8
	value     int
)

func getResult(o int8, p int8, q int8) bool {
	value = arr[o][p]
	for line = 0; line < q; line++ {
		if arr[o][line] > value {
			return false
		}
	}
	for row = 0; row < q; row++ {
		if arr[row][p] < value {
			return false
		}
	}
	flag = true
	fmt.Printf("(%d,%d)", o, p)
	return true
}

func main() {
	fmt.Scanln(&n)
	for i = 0; i < n-1; i++ {
		for j = 0; j < n; j++ {
			fmt.Scanf("%d", &arr[i][j])
		}
		//最后一行是换行输入
		fmt.Scanln(&arr[i][j]) //读取下一行的换行输入，go没有重载真的烦
	}
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			if getResult(i, j, n) {
				fmt.Println()
			}
		}
	}
	if !flag {
		fmt.Printf("NONE")
	}
}
