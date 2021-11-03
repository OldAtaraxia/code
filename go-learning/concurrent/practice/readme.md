https://tour.go-zh.org/concurrency/7  
不同二叉树的叶节点上可以保存相同的值序列。例如，以下两个二叉树都保存了序列 `1，1，2，3，5，8，13`。


在大多数语言中，检查两个二叉树是否保存了相同序列的函数都相当复杂。 我们将使用 Go 的并发和信道来编写一个简单的解法。

本例使用了 tree 包，它定义了类型：
```go
type Tree struct {
    Left  *Tree
    Value int
    Right *Tree
}
```
二叉查找树: 左子树所有结点的值小于根节点, 右子树反之