package main

import "fmt"

var (
	size                       int16 = 23
	num                        [23]int32
	i, j, k, num1, leng, leng1 int32
	str                        byte
)

func inItNum() {
	num[0] = 0
	j = 1
	for i = 1; i < int32(size); i++ {
		num[j] = i*i*2 - 1
		j++
	}
}

func printIt(s byte) {
	if num1 >= num[size-1] {
		i = int32(size)
		leng1 = num[i-1]
		leng = num1 - leng1

	} else {
		for i = 0; i < int32(size); i++ {
			if num[i] > num1 {
				leng1 = num[i-1]
				leng = num1 - leng1
				break
			}
		}
	}
	i--
	for j = 0; j < i; j++ {
		for k = 0; k < j; k++ {
			fmt.Printf(" ")
		}
		for k = 0; k < 2*(i-j)-1; k++ {
			fmt.Printf("%c", s)
		}
		fmt.Println()
	}
	for j = 0; j < i-1; j++ {
		for k = 1; k < i-j-1; k++ {
			fmt.Printf(" ")
		}
		for k = 0; k < 2*j+3; k++ {
			fmt.Printf("%c", s)
		}
		fmt.Println()
	}

	fmt.Printf("%d\n", leng)
}

func main() {
	inItNum()
	fmt.Scanf("%d %c", &num1, &str)
	printIt(str)
}
