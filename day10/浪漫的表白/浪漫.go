package main

import (
	"fmt"
	"time"
)

func main() {
	var temp string
	fmt.Scanln(&temp)
	boy, _ := time.Parse("2006-01-02", temp)
	fmt.Scanln(&temp)
	girl, _ := time.Parse("2006-01-02", temp)
	day := int32(boy.Sub(girl).Hours() / 24)
	if day < 0 {
		day = -day
	}
	if day%2 == 0 {
		fmt.Printf("我们生日相差%d天\n", day)
		fmt.Print("傻瓜,我心仪的人其实是你呀!")
	} else {
		fmt.Printf("我们生日相差%d天\n", day)
		fmt.Print("对不起,我们有缘无份")
	}
}
