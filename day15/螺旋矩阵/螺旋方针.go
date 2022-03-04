package main

import "fmt"

var (
	n, j, k, w, temp int32
	arr              [20][20]int32
)

func showResult(n1 int32) {
	temp = 1
	for j = 0; j < n1; j++ {
		for k = 0; k < n1; k++ {
			arr[j][k] = 0
		}
	}
	k = 0
	w = -1
	for j = 1; j < n1*2; j++ {
		if j%4 == 1 {
			w++
			for ; w < n1; w++ {
				if arr[k][w] != 0 {
					break
				}
				arr[k][w] = temp
				temp++
			}
			w--
		} else if j%4 == 2 {
			k++
			for ; k < n1; k++ {
				if arr[k][w] != 0 {
					break
				}
				arr[k][w] = temp
				temp++
			}
			k--
		} else if j%4 == 3 {
			w--
			for ; w > -1; w-- {
				if arr[k][w] != 0 {
					break
				}
				arr[k][w] = temp
				temp++
			}
			w++
		} else {
			k--
			for ; k > 0; k-- {
				if arr[k][w] != 0 {
					break
				}
				arr[k][w] = temp
				temp++
			}
			k++
		}
	}
	for j = 0; j < n1; j++ {
		for k = 0; k < n1; k++ {
			fmt.Printf("%4d", arr[j][k])
		}
		fmt.Println()
	}
}
func main() {
	fmt.Scanln(&n)
	showResult(n)
}
