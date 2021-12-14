package main

import "fmt"
//这个傻逼数据量，根本跑不动go，只能用c了
func main() {
	var i, j, n, temp, count int32
	var res []int32 = make([]int32, 1000000)
	fmt.Scanf("%d", &n)
	for n != 0 {
		if n == 1 {
			fmt.Scanln(&temp)
			j = temp
		} else {
			fmt.Scanf("%d", &temp)
			j = temp
			for i = 1; i < n-1; i++ {
				fmt.Scanf("%d", &temp)
				j ^= temp
			}
			fmt.Scanln(&temp)
			j ^= temp
		}
		res[count] = j
		count++
		fmt.Scanf("%d", &n)
	}

	for i = 0; i < count; i++ {
		fmt.Println(res[i])
	}
}
