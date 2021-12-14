package main

import "fmt"

var (
	n1, n2, i, j int32
	arr          [1024][1024]int32
)

func main() {
	fmt.Scanf("%d", &n1)
	fmt.Scanln(&n2)
	for i = 0; i < n1; i++ {
		for j = 0; j < n2-1; j++ {
			fmt.Scanf("%d", &arr[i][j])
		}
		fmt.Scanln(&arr[i][j])
	}
	for i = 0; i < n2; i++ {
		for j = n1 - 1; j > -1; j-- {
			fmt.Printf("%d ", arr[j][i])
		}
		fmt.Println()
	}
}
