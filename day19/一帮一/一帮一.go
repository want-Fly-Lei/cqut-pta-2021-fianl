package main

import "fmt"

type student struct {
	male int
	str  string
}

func main() {
	var n, i, j, status int
	fmt.Scanln(&n)
	var st []student = make([]student, n)
	for i = 0; i < n; i++ {
		fmt.Scanln(&st[i].male, &st[i].str)
	}
	for i = 0; i < n/2; i++ {
		status = st[i].male
		for j = n - 1; j >= n/2; j-- {
			if st[j].male != -1 && st[j].male != status {
				fmt.Println(st[i].str, st[j].str)
				st[j].male = -1
				break
			}
		}
	}

}
