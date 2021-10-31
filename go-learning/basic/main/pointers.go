package main

import "fmt"

// 值传递()
func zeroval(ival int) {
	ival = 0
}

//引用/指针传递
func zeroptr(iptr *int) {
	*iptr = 0
}

// 就是指针
func main() {
	i := 1
	fmt.Println("initial:", i)

	zeroval(i)
	fmt.Println("zeroval:", i)

	zeroptr(&i)
	fmt.Println("zeroptr:", i)

	fmt.Println("pointer:", &i)
}

/*
initial: 1
zeroval: 1
zeroptr: 0
pointer: 0x11ca2058
*/
