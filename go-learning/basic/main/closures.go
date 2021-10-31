package main

import "fmt"

func intSeq() func() int {
	i := 0
	// 定义并返回一个匿名函数
	// 它会保存自己的i值
	return func() int {
		i++
		return i
	}
}

func main() {

	nextInt := intSeq()

	fmt.Println(nextInt())
	fmt.Println(nextInt())
	fmt.Println(nextInt())

	newInts := intSeq()
	fmt.Println(newInts())
}

/*
1
2
3
1
*/
