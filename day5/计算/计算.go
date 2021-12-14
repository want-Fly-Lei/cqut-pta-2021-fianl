package main

import "fmt"

var (
	i, j, n, k,num int32
	arr        [10][10]int32
	flag       bool
)

func main() {
	fmt.Scanln(&n)

	for i = 0; i < n; i++ {
		for j = 0; j < n-1; j++ {
			fmt.Scanf("%d", &arr[i][j])
		}
		fmt.Scanln(&arr[i][j])
	}
	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			num = arr[i][j]
			for k = 0; k < n; k++ {
				if (num > arr[i][k] || (k == j)) && (arr[k][j] > num || (k == i)) {
					continue
				} else {
					break
				}
			}
			if k == n {
					flag = true
					fmt.Println(i+1,j+1,num)
				}
		}
	}
	if !flag {
		fmt.Println("not found")
	}
}
