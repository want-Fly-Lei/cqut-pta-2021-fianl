package main

import "fmt"

func main() {
	var n, i, j, sum, temp int32
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		for j = 0; j < n-1; j++ {
			fmt.Scanf("%d", &temp)
			if (i+j != n-1) && (i != n-1){
				sum += temp
			}

		}
		fmt.Scanln(&temp)
	}
	fmt.Println(sum)
}
