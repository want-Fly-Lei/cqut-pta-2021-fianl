package main
import "fmt"

type Hello struct{
	Name string
}

func (h *Hello)sayHello() {
	fmt.Println("Hello",h.Name)
}

func main(){
	var h1 Hello
	fmt.Scanln(&(h1.Name))
	h1.sayHello()
}