package main
import (
	"fmt"
)

var (
	sgNum, GsNum, n, i, sg, gs int
)

func main() {

	for {
		fmt.Scanln(&n)
		if n == 0 {
			break
		}
		for i = 0; i < n; i++ {
			fmt.Scanf("%d", &sg)
			fmt.Scanln(&gs)

			if sg > gs {
				sgNum++
			} else if sg < gs {
				GsNum++
			}
		}
		if sgNum > GsNum {
			fmt.Println("Sg")
		} else if sgNum < GsNum {
			fmt.Println("Gs")
		} else {
			fmt.Println("CONTINUE")
		}
	}

}
