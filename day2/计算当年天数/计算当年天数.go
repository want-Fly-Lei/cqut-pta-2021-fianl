package main

import "fmt"

var (
	year  int32
	month int8
	day   int8
	sumDay int16
	monthDay [12]int8 = [12]int8{31,28,31,30,31,30,31,31,30,31,30,31}
)

func isRunYear(num1 int32) bool {
	if (num1 % 4 != 0) || ((num1 % 100 == 0) && (num1 % 400 != 0)){
		return false
	} else {
		return true
	}
}

func getSumDay() {
		var j int8
		for j = 0; j < month - 1; j++ {
			sumDay += int16(monthDay[j])
		}
		sumDay += int16(day)
		if month > 2 {
			if isRunYear(year) {
			sumDay++
		}
		}
		
	fmt.Printf("%d",sumDay)
}

func main() {
	fmt.Scanf("%d %d %d", &year, &month, &day)
	getSumDay()
}
