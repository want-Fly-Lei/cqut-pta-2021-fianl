package main

import "fmt"

var (
	i, j, n, m, temp int
)

const max int = 1001

func main() {
	var sli [max]int
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d",&m)
		for j = 1; j < m; j++ {
			fmt.Scanf("%d",&temp)
			sli[temp]++
		} 
		fmt.Scanln(&temp)
		sli[temp]++
	}
	var maxLove,maxIdex int = 0, max - 1
	for i = max - 1; i >= 0; i-- {
		if sli[i] > maxLove {
			maxLove = sli[i]
			maxIdex = i
		}
	}
	fmt.Println(maxIdex,maxLove)
}