package main

import "fmt"

func main() {
	var N, M, K, index int16
	var count, countM, countK int16
	fmt.Scanln(&N, &M, &K)
	var sli []bool = make([]bool, N)
	for count < N {
		countM = 0
		for {
			if countM == M - 1 {
				sli[index] = true
				break
			}
			index = (index - 1 + N) % N
			if !sli[index] {
				countM++
			}

		}
		fmt.Printf("%d ", index+1)
		count++
		countK = 0
		for {
			if countK == K - 1 {
				sli[index] = true
				break
			}
			index = (index + 1) % N
			if !sli[index] {
				countK++
			}
		}
		fmt.Printf("%d ", index+1)
		count++
	}
}
