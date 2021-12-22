package main

import "fmt"

type num struct {
	Num   int32
	count int16
}

func main() {
	var n, i int16
	var temp int32
	fmt.Scanln(&n)
	fmt.Scanf("%d", &temp)
	var max, min num
	max.Num = temp
	min.Num = temp
	for i = 1; i < n-1; i++ {
		fmt.Scanf("%d", &temp)
		if temp > max.Num {
			max.count = 0
			max.Num = temp
		} else if temp == max.Num {
			max.count++
		}
		if temp < min.Num {
			min.count = 0
			min.Num = temp
		} else if temp == min.Num {
			min.count++
		}
	}
	if n > 1 {
		fmt.Scanln(&temp)
		if temp > max.Num {
			max.Num = temp
			max.count = 0
		} else if temp == max.Num {
			max.count++
		}
		if temp < min.Num {
			min.count = 0
			min.Num = temp
		} else if temp == min.Num {
			min.count++
		}
	}

	fmt.Println(min.Num, min.count+1)
	fmt.Println(max.Num, max.count+1)
}
