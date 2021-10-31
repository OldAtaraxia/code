package main

import "fmt"

func main() {
	var a = "string"
	fmt.Println(a)

	var b, c int = 1, 2
	fmt.Println(b, c)

	var d = true
	fmt.Println(d)

	var e int // 惊了, 竟然有这种写法, 丑哭了...
	fmt.Println(e)

	f := "short"
	fmt.Println(f)
}
