package main
//我丢有超时
import (
	"fmt"
	"sort"
)

func main() {
	var i, j, m, n, k, sum, temp, min, max int
	fmt.Scanln(&n, &k, &m)
	var sli []float64 = make([]float64, n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &min)
		max = min
		sum = min
		for j = 1; j < k; j++ {
			fmt.Scanf("%d", &temp)
			if temp > max {
				max = temp
			} else if min > temp {
				min = temp
			}
			sum += temp
		}
		sli[i] = float64(sum-min-max) / float64(k-2)
	}

	sort.Float64s(sli)
	for i = n - m; i < n-1; i++ {
		fmt.Printf("%.3f ", sli[i])
	}
	fmt.Printf("%.3f", sli[i])
}
