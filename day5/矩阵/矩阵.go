package main

import "fmt"

var (
	n, i, j int32
	arr     [20][20]int32
)

func main() {
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		for j = 0; j < n-1; j++ {
			fmt.Scanf("%d", &arr[i][j])
		}
		fmt.Scanln(&arr[i][j])
	}
	for i = 0; i < n-1; i++ {
		for j = i + 1; j < n; j++ {
			arr[i][j] ^= arr[j][i]
			arr[j][i] ^= arr[i][j]
			arr[i][j] ^= arr[j][i]
		}
	}
	for i = 0; i < n; i++ {
		for j = 0; j < n-1; j++ {
			fmt.Printf("%d ", arr[i][j])
		}
		fmt.Println(arr[i][j])
	}
}
