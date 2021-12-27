package main

import "fmt"

func main() {
	var T, n, i, j, k, temp int32
	fmt.Scanln(&T)
	var flag []bool = make([]bool, T)
	for i = 0; i < T; i++ {
		fmt.Scanln(&n)
		for j = 0; j < n; j++ {
			for k = 0; k < n-1; k++ {
				fmt.Scanf("%d", &temp)
				if (k < j) && (temp != 0) {
					flag[i] = true
				}
			}
			fmt.Scanln(&temp)
		}

	}
	for _, v := range flag {
		if v {
			fmt.Println("NO")
		} else {
			fmt.Println("YES")
		}
	}
}
