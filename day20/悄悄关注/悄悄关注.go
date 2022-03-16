package main

import (
	"fmt"
	"sort"
)

type person struct {
	name string
	zan int
}
type pesli []person
//go语言的结构体排序好麻烦
var sli pesli

func (pe pesli) Len() int {
	return len(pe)
}
func (pe pesli) Less(i, j int) bool {
	return pe[i].name < pe[j].name
}

func (pe pesli) Swap(i, j int) {
	pe[i],pe[j] = pe[j],pe[i]
}

func main() {
	var i, n, temp int
	fmt.Scanf("%d",&n)
	var str string
	var myMap map[string]int = make(map[string]int)
	for i = 1; i < n; i++ {
		fmt.Scanf("%v",&str)
		myMap[str] = 1
	}
	fmt.Scanln(&str)
	myMap[str] = 1
	fmt.Scanln(&n)
	var p person
	sli = make(pesli, 0)
	for i = 0; i < n; i++ {
		fmt.Scanln(&p.name,&p.zan)
		if _,ok := myMap[p.name]; !ok {
			sli = append(sli, p)
		}
		temp += p.zan
	}
	sort.Sort(sli)
	var flag bool = true
	for i = 0; i < len(sli); i++ {
		if sli[i].zan * n > temp {
			fmt.Println(sli[i].name)
			flag = false
		}
	}
	if flag {
		fmt.Println("Bing Mei You")
	}
}