package main

import (
	"fmt"
	"time"
)

type st struct {
	year  int32
	month int8
	day   int8
}

var ST [1024]st
var (
	n, i     int
	timeStr  string
	monthDay [12]int8 = [12]int8{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	Cd, Cm   int8
	Cy       int32
)

func isRunYear(num1 int32) bool {
	if (num1%4 != 0) || ((num1%100 == 0) && (num1%400 != 0)) {
		return false
	} else {
		return true
	}
}

func isNotAdd(d int8, m int8, y int32) bool {
	if (m == 2) && (d == 28) && (isRunYear(y)) {
		return true
	} else {
		return false
	}
}

func showResult(num int) {
	Cd = ST[num].day
	Cm = ST[num].month
	Cy = ST[num].year
	if (Cd < monthDay[Cm-1]) || (isNotAdd(Cd, Cm, Cy)) {
		ST[num].day++
	} else {
		ST[num].day = 1
		if Cm == 12 {
			ST[num].month = 1
			ST[num].year++
		} else {
			ST[num].month++
		}
	}
}

func main() {
	fmt.Scanln(&n)

	for i = 0; i < n; i++ {
		fmt.Scanln(&timeStr)
		t1, _ := time.Parse("2006-01-02", timeStr)
		ST[i].year = int32(t1.Year())
		ST[i].month = int8(t1.Month())
		ST[i].day = int8(t1.Day())
	}
	for i = 0; i < n; i++ {
		showResult(i)
		fmt.Printf("%04d-%02d-%02d", ST[i].year, ST[i].month, ST[i].day)
		if i != n-1 {
			fmt.Println()
		}
	}
}
