拷贝运算符rhs要进行拷贝初始化, 根据参数的类型调用拷贝构造函数或者移动构造函数 -- 左值被拷贝, 右值被移动. 这一个函数就实现了拷贝赋值运算符和移动赋值运算符两种功能
与`swap`无关, 主要是`rhs`初始化时启用了哪种构造函数, 如果参数是右值引用那么`rhs`就会用移动构造函数初始化, 经过`swap`之后变相相当于实现了原来正统的移动赋值运算符
```C++
HasPtr& HasPtr::operator=(HasPtr&& rhs) noexcept {
    // 直接检测自赋值
    if (this != &rhs) {
        delete ps_;
        ps_ = rhs.ps_;
        // 将rhs置于可析构的状态
        rhs.ps_ = nullptr;
    }
    return *this;
}
```