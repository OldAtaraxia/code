#include<iostream>
#include<algorithm>
#include<string>

class HasPtr {
public:
    // 构造函数
    explicit HasPtr(const std::string& s) : ps_(new std::string(s)) {}
    // 拷贝构造函数
    HasPtr(const HasPtr& p) : ps_(new std::string(*p.ps_)) {
        printf("copy constructor\n");
    }
    // 移动构造函数
    HasPtr(HasPtr&& rhs) noexcept : ps_(rhs.ps_) {
        rhs.ps_ = nullptr;
        printf("move constructor");
    }
    // 析构函数
    ~HasPtr() {
        delete ps_;
    }

    // swap
    friend void swap(HasPtr& lhs, HasPtr& rhs) {
        std::swap(lhs.ps_, rhs.ps_);
    }

    // 拷贝并交换运算符
    HasPtr& operator= (HasPtr rhs) {
        swap(*this, rhs);
        return *this;
    }
private:
    std::string* ps_;

};

int main() {
    HasPtr a("sword"), b("sunlight");
    a = b;
    a = std::move(b);

    return 0;
}