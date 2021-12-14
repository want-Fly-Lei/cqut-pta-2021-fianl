package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	str                                                       []byte
	length, i, lsindex, leindex, llen, ssindex, seindex, slen int32
	tsindex, tlen                                             int32
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
	str = getInput()
	length = int32(len(str))
	for i = 0; i < length; i++ {
		if str[i] != ' ' && str[i] != ',' {
			leindex = i
			lsindex = i
			ssindex = i
			seindex = i
			break
		}
	}
	tlen = 0
	tsindex = i
	for ; i < length; i++ {
		if str[i] != ' ' && str[i] != ',' {
			tlen++
		} else {
			break
		}
	}
	leindex = tlen + tsindex
	llen = tlen
	seindex = tlen + tsindex
	slen = tlen
	tlen = 0
	for i = 0; i < length; i++ {
		if str[i] != ' ' && str[i] != ',' {
			break
		}
	}
	tsindex = i
	for ; i < length; i++ {
		if str[i] != ' ' && str[i] != ',' {
			tlen++
			if i == length-1 {
				if tlen > llen {
					llen = tlen
					lsindex = tsindex
					leindex = tlen + tsindex
				}
				if tlen < slen {
					slen = tlen
					ssindex = tsindex
					seindex = tlen + tsindex
				}
			}
		} else {
			if tlen > llen {
				llen = tlen
				lsindex = tsindex
				leindex = tlen + tsindex
			}
			if tlen < slen {
				slen = tlen
				ssindex = tsindex
				seindex = tlen + tsindex
			}
			for {
				if str[i] == ' ' || str[i] == ',' {
					i++
				} else {
					tsindex = i
					i--
					tlen = 0
					break
				}
			}
		}
	}
	for i = lsindex; i < leindex; i++ {
		fmt.Printf("%c", str[i])
	}
	fmt.Println()
		for i = ssindex; i < seindex; i++ {
		fmt.Printf("%c", str[i])
	}
	fmt.Println()
}
