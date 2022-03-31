package main

import "fmt"

var (
	Duang     string = "Dang"
	hour, min int
)

func duangTimes(times int) {
	for i := 0; i < times; i++ {
		fmt.Print(Duang)
	}
}
func main() {

	fmt.Scanf("%d:%d", &hour, &min)
	if 0 <= hour && hour < 12 {
		fmt.Printf("Only %02d:%02d.  Too early to Dang.\n", hour, min)
	} else if hour == 12 && min == 0 {
		fmt.Println("Only 12:00.  Too early to Dang.")
	} else {
		if min == 0 {
			duangTimes(hour - 12)
		} else {
			duangTimes(hour - 11)
		}

	}
}
