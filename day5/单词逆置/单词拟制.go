package main
//真的搞不懂这些垃圾低版本go怎么还怎么多服务器跑
import (
	"bufio"
	"fmt"
	"os"
)

var (
	str                             [10240][]byte
	j, length, sindex, eindex, k, w int8
	n, i                            int64
	temp                            byte
)

func getInput() []byte {
	in := bufio.NewReader(os.Stdin)
	str, _, err := in.ReadLine()
	if err != nil {
		return []byte(err.Error())
	}
	return []byte(str)
}

func main() {
	fmt.Scanln(&n)
	for i = 0; i < n; i++ {
		str[i] = getInput()
		length = int8(len(str[i]))
		if length > 80 {
			return
		}
		sindex = 0
		eindex = 0
		for j = 0; j < length; j++ {
			if str[i][j] == ' ' {
				continue
			} else {
				sindex = j
				eindex = j
				for k = sindex + 1; k < length; k++ {
					if str[i][k] != ' ' {
						eindex++
					} else {
						break
					}
				}
				w = 0
				for k = sindex; k <= (eindex+sindex)/2; k++ {
					temp = str[i][k]
					str[i][k] = str[i][eindex-w]
					str[i][eindex-w] = temp
					w++
				}

				j = eindex + 1
			}
		}
	}
	for i = 0; i < n; i++ {
		for j = 0; j < int8(len(str[i])); j++ {
		//for j = int8(len(str[i])) - 1; j > -1; j-- {
			fmt.Printf("%c", str[i][j])
		}
		fmt.Println()
	}

}
