package main

import "fmt"

var (
	arr            [10][100]int32
	n, i, j, count int32
	num            [10]int32
	flag           int8
)

func com(a, b int32) int8 {
	if a > b {
		return -1
	} else if a == b {
		return 0
	} else {
		return 1
	}
}
func getCount() {
	for i = 0; i < n; i++ {
		count = 0
		if num[i] != 1 {
			flag = com(arr[i][0], arr[i][1])
			j = 1
			if flag == 0 {
				for ; j < num[i]-1; j++ {
					if com(arr[i][j], arr[i][j+1]) != 0 {
						flag = com(arr[i][j], arr[i][j+1])
						j++
						break
					}
				}
			}
			for ; j < num[i]-1; j++ {
				if com(arr[i][j], arr[i][j+1]) != 0 {
					if com(arr[i][j], arr[i][j+1]) != flag {
						flag = -flag
						count++
					}
				}
			}
		}
		num[i] = count
	}
}

func main() {
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		fmt.Scanln(&num[i])
		for j = 0; j < num[i]-1; j++ {
			fmt.Scanf("%d", &arr[i][j])
		}
		if j != 1 {
			fmt.Scanln(&arr[i][j])
		}
	}
	getCount()
	for i = 0; i < n; i++ {
		fmt.Println(num[i])
	}
}
