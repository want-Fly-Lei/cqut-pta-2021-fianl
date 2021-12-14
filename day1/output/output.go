package main
import "fmt"
func main(){
	var num1,num2 int
	fmt.Scanln(&num1,&num2)
	var i,j int 
	for i = 0; i < num1; i++ {
		for j = 0; j < num2; j++ {
			fmt.Printf("*")
		}
		if i != num1 {
			fmt.Println()
		}
		
	}
}