package main
import "fmt"
var (
	x,y,z,num int
)
func getIt(){
	var i int = 1
	for num = x; ; {
		if (num % 5 == y) && (num % 7 == z) {
			break
		}
		num = i * 3 + x
		i++
	}
	fmt.Printf("%d",num)
}
func main(){
	fmt.Scanf("%d %d %d",&x,&y,&z)
	getIt()
}