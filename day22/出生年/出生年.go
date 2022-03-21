package main
//我也不知道为什么go语言有一个过不了，但是改成c后，就过了，而且逻辑是一样的呀。简直就是离谱的妈给离谱开门
import (
	"fmt"
)

func main() {
	var i, j, year, n, w, temp int
	fmt.Scanln(&year,&n)
	const max,length int = 10000,4
	var sli []int = make([]int, length)
	for i = year; i < max; i++ {
		temp = i
		for j = 0; j < length; j++ {
			sli[j] = temp % 10
			temp /= 10
		}

		temp = length
		for j = 0; j < length - 1; j++ {
			for w = j + 1; w < length; w++ {
				if sli[w] == sli[j] {
					temp--
					break
				}
			}
		}

		if temp == n {
			break
		}
	}
	
	fmt.Printf("%d %04d",i - year,i)
}