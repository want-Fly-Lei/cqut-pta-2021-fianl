package main

import "fmt"

var (
	arr    [100]int64
	beishu [8]int64 = [8]int64{2, 3, 4, 5, 6, 7, 8, 9}
	size   int64
	i      int64
)

func sum(num int64) (sumNum int64) {
	sumNum = 0
	for num > 0 {
		sumNum += num % 10
		num /= 10
	}
	return
}

func showRuselt(num int64) {
	var num1 int64 = sum(num)
	var flage int16 = 0
	for j := 0; j < 8; j++ {
		if num1 == sum(num*beishu[j]) {
			flage++
		} else {
			break
		}
	}
	if flage < 8 {
		fmt.Printf("NO\n")
	} else {
		fmt.Printf("%d\n", num1)
	}
}

func main() {
	fmt.Scanln(&size)
	for i = 0; i < size; i++ {
		fmt.Scanf("%d\n", &arr[i])
	}
	for i = 0; i < size; i++ {
		showRuselt(arr[i])
	}
}
