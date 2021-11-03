package main

import "fmt"

type test struct {
	a string
	b string
}

func main() {
	t := test{"hello", "fuck"}
	var i interface{} = t

	s, ok := i.(test)
	fmt.Println(ok)
	fmt.Printf("%v", s)

}
