package main

import "fmt"

func main() {
	var T, i int32
	var sli []int32
	var n, j, k, w int8
	fmt.Scanln(&T)
	for i = 0; i < T; i++ {
		fmt.Scanf("%d %d %d", &n, &j, &k)
		sli = make([]int32, n)
		for w = 0; w < n-1; w++ {
			fmt.Scanf("%d", &sli[w])
		}
		fmt.Scanln(&sli[w])
		//为什么不是下标，不从0开始算，之前一直报错
		j--
		k--
		for w = 0; w < n; w++ {
			if w >= j && w <= k {
				fmt.Print(sli[k-w+j])
			} else {
				fmt.Print(sli[w])
			}
			if w == n-1 {
				fmt.Println()
			} else {
				fmt.Print(" ")
			}
		}
	}
}
