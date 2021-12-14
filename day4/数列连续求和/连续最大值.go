package main

import "fmt"

func main() {
	var num [10000]int32
	var n, i, j, sum, sindex, eindex int32
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &num[i])
	}
	for i = 0; i < n; i++ {
		if num[i] >= 0 {
			sindex = i
			break
		}
	}
	if i == n { //说明全是复数
		sum = num[0]
		for i = 1; i < n; i++ {
			if num[i] > sum {
				sum = num[i]
			}
		}
		fmt.Printf("MAX Sum= %d, MAX K= 1", sum)
	} else {
		for i = n - 1; i >= sindex; i-- {
			if num[i] >= 0 {
				eindex = i
				break
			}
		}
		var temp int32
		for i = sindex; i <= eindex; i++ {
			sum += num[i]
		}
		var s, e int32 = sindex, eindex
		for i = s; i <= e; i++ {
			temp = 0
			for j = i; j <= e; j++ {
				if num[j] < 0 {
					if temp > sum {
						sum = temp
						sindex = i
						eindex = j - 1
					} else if temp == sum {
						if eindex-sindex < j-i-1 {
							sindex = i
							eindex = j - 1
						}
					}
				}
				temp += num[j]
				if j == e {
					if temp > sum {
						sum = temp
						sindex = i
						eindex = j
					} else if temp == sum {
						if eindex-sindex < j-i-1 {
							sindex = i
							eindex = j
						}
					}
				}
			}
		}
		fmt.Printf("MAX Sum= %d, MAX K= %d", sum, eindex-sindex+1)
	}

}
