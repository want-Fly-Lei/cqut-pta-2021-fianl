package main

import "fmt"

func main() {
	var s, m int16
	var smin, smax, ymin int16 = 90, 140, 60
	var n, i, j, count, temp int8
	var ok [100]bool
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &s)
		fmt.Scanln(&m)
		if (s >= smin) && (s <= smax) && (m >= ymin) && (m <= smin) {
			ok[i] = true
		}
	}
	count = 0
	for i = 0; i < n; i++ {
		if ok[i] == false {
			continue
		}
		temp = 0
		for j = i + 1; j < n; j++ {
			if ok[j] == true {
				temp++
				if j == n-1 {
					if temp > count {
						count = temp
					}
				}
			} else {
				if temp > count {
					count = temp
				}
				i = j - 1
				break
			}
		}
	}
	count++
	fmt.Printf("%d\n", count)
}
