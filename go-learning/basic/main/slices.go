package main

import "fmt"

// slice: go中重要的数据类型, 有比数组更强大的序列交互方式
// 创建: make函数. 例子里创建了长度为3的string类型的slice
//
// https://go.dev/blog/slices-intro
func main() {
	s := make([]string, 3)
	fmt.Println("empty slice: ", s)

	s[0] = "a"
	s[1] = "b"
	s[2] = "c"
	fmt.Println("set:", s)
	fmt.Println("get", s)
	fmt.Println("len:", len(s))

	s = append(s, "d")
	s = append(s, "e", "f")
	fmt.Println("append:", s)

	c := make([]string, len(s))
	copy(c, s)
	fmt.Println("copy:", c)

	l := s[2:5]
	fmt.Println("s[2:5]:", l)

	l = s[2:]
	fmt.Println("s[2:]", l)

	// 直接声明slice
	t := []string{"g", "h", "i"} // 与数组的声明是不一样的, 这里是大括号
	fmt.Println("dcl:", t)

	twoD := make([][]int, 3)
	for i := 0; i < 3; i++ {
		innerLen := i + 1
		twoD[i] = make([]int, innerLen)
		for j := 0; j < innerLen; j++ {
			twoD[i][j] = i + j
		}
	}
	fmt.Println("2d: ", twoD)
}

/*
empty slice:  [  ]
set: [a b c]
get [a b c]
len: 3
append: [a b c d e f]
copy: [a b c d e f]
s[2:5]: [c d e]
s[2:] [c d e f]
dcl: [g h i]
2d:  [[0] [1 2] [2 3 4]]
*/
