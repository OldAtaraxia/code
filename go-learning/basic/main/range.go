package main

import "fmt"

func main() {

	nums := []int{2, 3, 4}
	sum := 0

	// 遍历数组
	for _, num := range nums {
		sum += num
	}
	fmt.Println("sum: ", sum)

	for i, num := range nums {
		if num == 3 {
			fmt.Println("index:", i)
		}
	}

	// 遍历maps
	kvs := map[string]string{"a": "apple", "b": "banana"}
	for k, v := range kvs {
		fmt.Printf("%s -> %s\n", k, v)
	}

	for k := range kvs {
		fmt.Println("key:", k)
	}

	// 遍历string
	for i, c := range "go" {
		fmt.Println(i, c) // 输出字符位置, unicode码点
	}
}
