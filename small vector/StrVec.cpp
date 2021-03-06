#include "StrVec.h"
#include <memory>
#include <utility>

void StrVec::push_back(const std::string &s){
    chk_n_alloc();
    //  构造s的副本
    alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string* b, const std::string* e){
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free(){
    // 必须检查指针是否为空
    if(elements){
        for(auto p = first_free; p != elements; p--){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s){
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec(){
    free();
}

StrVec& StrVec::operator=(const StrVec &rhs){
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate(){
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i != size(); i++){
        alloc.construct(dest++, std::move(*elem++));
    }
    free(); // 释放旧内存
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}




