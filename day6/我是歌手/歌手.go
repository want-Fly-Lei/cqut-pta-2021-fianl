package main

import "fmt"

var (
	T, m, n, i, j, k int8
	arr              [20]int8
	num              [10]int32
	temp             int32
)

func main() {
	fmt.Scanln(&T)
	for i = 0; i < T; i++ {
		fmt.Scanf("%d", &m)
		fmt.Scanln(&n)
		for j = 0; j < m; j++ {
			num[j] = 0
		}
		for j = 0; j < n; j++ {
			for k = 0; k < m-1; k++ {
				fmt.Scanf("%d",&temp)
				num[k] += temp
			}
			fmt.Scanln(&temp)
				num[k] += temp
		}
		for j = 1; j < m; j++ {
			if num[j] < num[arr[i]] {
				arr[i] = j
			}
		}
	}
	for i = 0; i < T; i++ {
		fmt.Println(arr[i] + 1)
	}
}
