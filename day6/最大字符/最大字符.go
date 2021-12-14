package main
import (
	"fmt"
	"bufio"
	"os"
)
func getInput() []byte {
	in := bufio.NewReader(os.Stdin)
	str, _, err := in.ReadLine()
	if err != nil {
		return []byte(err.Error())
	}
	return []byte(str)
}

func main(){
	var i int8
	str := getInput()
	var max byte
	max = str[0]
	for i = 1; i < int8(len(str)); i++ {
		if str[i] > max {
			max = str[i]
		}
	}
	fmt.Printf("%c",max)
}