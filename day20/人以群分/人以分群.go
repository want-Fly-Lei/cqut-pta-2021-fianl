package main
//我丢这个都要超时,没办法go语言一般的读写太慢了
import (
	"fmt"
	"sort"
)

func main() {
	var i, n, sum int
	fmt.Scanln(&n)
	var sli []int = make([]int, n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &sli[i])
	}
	sort.Ints(sli)
	for i = 0; i < n/2; i++ {
		sum -= sli[i]
	}
	for i < n {
		sum += sli[i]
		i++
	}
	fmt.Println("Outgoing #:", n/2+n%2)
	fmt.Println("Introverted #:", n/2)
	fmt.Println("Diff =", sum)
}
