package main

import "fmt"

func main() {
	var n, m, k, i, count, countM, countK uint8
	fmt.Scanln(&n, &m, &k)
	var sli []bool = make([]bool, n)
	for count < n {
		countM = 0
		for  {
			if !sli[i] {
				countM++
			}
			if countM == m {
				break
			}
			i = (i + 1) % n
		}
		count++
		if count == n {
			break
		}
		//fmt.Print("剔除", i+1, " ")
		sli[i] = true
		countK = 0
		for {
			if !sli[i] {
				countK++
			}
			if countK == k {
				break;
			}
			i = (i - 1 + n) % n
		}
		count++
		sli[i] = true
		//fmt.Print("剔除", i+1, " ")
	}
	fmt.Println(i + 1)
}
