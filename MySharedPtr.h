#ifndef MY_SHARED_PTR_H
#define MY_SHARED_PTR_H

#include <iostream>
#include <cassert>

template<typename T>
class MySharedPtr {
private:
    T* data;
    int* ref_count;

public:
    explicit MySharedPtr(T* ptr = nullptr);
    MySharedPtr(const MySharedPtr& other);
    MySharedPtr& operator=(const MySharedPtr& other);
    ~MySharedPtr();

    T& operator*() const;
    T* operator->() const;
};

#include "MySharedPtr.hpp" // ¬ключаем реализацию

#endif // MY_SHARED_PTR_H
