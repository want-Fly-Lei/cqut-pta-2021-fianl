package main

import "fmt"

func main() {
	var n, temp, i, length, j int32
	fmt.Scanln(&n)
	var sli []int32
	for i = 0; i < n; i++ {
		sli = make([]int32, 0)
		for {
			fmt.Scanf("%d", &temp)
			if temp != -1 {
				sli = append(sli, temp)
			} else {
				break
			}
		}
		length = int32(len(sli))
		for j = length - 1; j > 0; j-- {
			fmt.Printf("%d ", sli[j])
		}
		fmt.Println(sli[0])
	}
}
