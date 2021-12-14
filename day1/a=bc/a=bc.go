package main
import "fmt"
var i,j int

func showRusult(num int){
	fmt.Printf("%d=",num)
	var flage int = 1
	for j = 2; j <= num; {
		if num % j == 0 {
			if flage != 1 {
				fmt.Printf("*")
			}
			fmt.Printf("%d",j)
			num /= j
			j = 2
			flage++
		} else {
			j++
		}
	}
}

func main(){
	var numStart,numend int
	fmt.Scanln(&numStart,&numend)
	for i = numStart; i <= numend; i++ {
		showRusult(i)
		if i != numend {
			fmt.Println()
		}
	}
}