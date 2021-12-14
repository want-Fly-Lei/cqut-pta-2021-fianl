package main
import "fmt"
func main(){
	var n int
	fmt.Scanf("%d",&n)
	var i,j int = 0,0
	for i = 0; i < n; i++ {
		for j = i; j < n - 1; j++ {
			fmt.Printf(" ")
		}
		for j = -1; j < 2 * i; j++ {
			fmt.Printf("*")
		}
		if i != n {
			fmt.Println()
		}
	}
}