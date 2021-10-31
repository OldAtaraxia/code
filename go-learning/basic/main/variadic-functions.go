package main

import "fmt"

// 接受任意数量的int
func sum(nums ...int) {
	fmt.Print(nums, " ")
	total := 0
	for _, num := range nums {
		total += num
	}
	fmt.Println(total)
}

func main() {

	sum(1, 2)
	sum(1, 2, 3)

	// 把slices作为参数时要用func(slice...)
	nums := []int{1, 2, 3, 4}
	sum(nums...)
}
