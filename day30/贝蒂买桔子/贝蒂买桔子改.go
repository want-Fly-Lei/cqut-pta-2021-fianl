package main

//我tm连并发都用了,还没用普通的print函数，太难了

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	count, MAXSIZE  int
	n, i     byte
	strSli   []string
	myStr    chan string
	stop     chan bool
)



func nuBuy(str string, ch byte) {
	if ch+1 < 'a'+n {
		nuBuy(str, ch+1)
		toBuy(str, ch+1)
	} else {
		myStr <- str
	}
}

func toBuy(str string, ch byte) {
	str += "," + string(ch)
	if ch+1 < 'a'+n {
		nuBuy(str, ch+1)
		toBuy(str, ch+1)
	} else {
		myStr <- str
	}
}

func baseToBuy(ch byte) {
	var str string = string(ch)
	if ch + 1 < n + 'a' {
		nuBuy(str, ch+1)
		toBuy(str, ch+1)
	} else {
		myStr <- str
	}
}

//生产者模型
func produce() {
	for i = 0; i < n; i++ {
		baseToBuy(i + 'a')
	}
	close(myStr)
}

//消费者模型
func consume() {
	for {
		v, ok := <-myStr
		if !ok {
			break
		}
		strSli[count] = v
		count++
	}
	stop <- true
	close(stop)
}

func getPow() {
	MAXSIZE = 1
	for i = 0; i < n; i++ {
		MAXSIZE *= 2
	}
	MAXSIZE--
}

func main() {
	fmt.Println("{}")
	fmt.Scanln(&n)
	getPow()
	//fmt.Println(MAXSIZE)
	myStr = make(chan string, MAXSIZE)
	stop = make(chan bool, 1)
	go produce()
	strSli = make([]string, MAXSIZE)
	go consume()
	for {
		_, ok := <-stop
		if !ok {
			break
		}
	}
	
	sort.Strings(strSli)
	var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
	for _, v := range strSli {
		//太慢了
		//fmt.Println(("{" + v + "}"))
		writer.WriteString(("{" + v + "}\n"))
	}
	writer.Flush()
}
