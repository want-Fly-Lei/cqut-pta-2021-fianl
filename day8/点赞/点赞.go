package main

import "fmt"

type zan struct {
	shuXing int32
	count   int32
	num     int32
}

func main() {
	var n, i, j, k, temp, index int32
	fmt.Scanln(&n)
	var list int32
	var d [10000]zan
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &list)
		for j = 0; j < list-1; j++ {
			fmt.Scanf("%d", &temp)
			if index == 0 {
				d[0].num = temp
				d[0].shuXing = list
				index++
				continue
			}
			for k = 0; k < index; k++ {
				if d[k].num == temp {
					d[k].count++
					break
				}
			}
			if k == index {
				d[k].num = temp
				d[k].shuXing = list
				index++
			}
		}
		fmt.Scanln(&temp)
		for k = 0; k < index; k++ {
			if d[k].num == temp {
				d[k].count++
				break
			}
		}
		if k == index {
			d[k].num = temp
			d[k].shuXing = list
			index++
		}
	}
	var maxIndex int32
	for i = 1; i < index; i++ {
		if d[i].count > d[maxIndex].count {
			maxIndex = i

		} else if d[i].count == d[maxIndex].count {
			if d[i].num > d[maxIndex].num {
				maxIndex = i
			}
		}
	}
	//第二个输出我看成列号了，去你的
	fmt.Println(d[maxIndex].num, d[maxIndex].count+1)
}
