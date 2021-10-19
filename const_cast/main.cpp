#include<iostream>
#include<algorithm>

int main() {
    const int N = 10;
    const int* c_ptr = &N;
    int* ptr = const_cast<int*>(c_ptr);
    *ptr = 0;
    // 我知道了, 因为N会自动被展开成10
    std::cout << (*c_ptr) << std::endl;
    std::cout << N << std::endl;
    std::cout << *(&N) << std::endl;
    return 0;
}