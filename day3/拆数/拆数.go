package main
import "fmt"
func main(){
	var num,i,j,sum,SC int32
	SC = 1
	j = 0
	fmt.Scanln(&num)
	for num > 0 {
		i = num % 10
		sum += i
		j = 1
		SC *= i
		num /= 10
	}
	fmt.Printf("%d ",sum)
	if j == 1 {
		fmt.Printf("%d",SC)
	} else {
		fmt.Printf("0")
	}
}