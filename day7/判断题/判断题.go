package main

import "fmt"

func main() {
	var n, m, i, j, temp int8
	fmt.Scanf("%d", &n)
	fmt.Scanln(&m)
	var sco []int32 = make([]int32, m)
	for i = 0; i < m-1; i++ {
		fmt.Scanf("%d", &sco[i])
	}
	fmt.Scanln(&sco[i])
	var an []int8 = make([]int8, m)
	for i = 0; i < m-1; i++ {
		fmt.Scanf("%d", &an[i])
	}
	fmt.Scanln(&an[i])
	var grade []int32 = make([]int32, n)
	for i = 0; i < n; i++ {
		for j = 0; j < m-1; j++ {
			fmt.Scanf("%d", &temp)
			if temp == an[j] {
				grade[i] += sco[j]
			}
		}
		fmt.Scanln(&temp)
		if temp == an[j] {
			grade[i] += sco[j]
		}
	}
	for _, v := range grade {
		fmt.Println(v)
	}
}
