#ifndef MY_SHARED_PTR_H
#define MY_SHARED_PTR_H

#include <iostream>
#include <cassert>
#include <functional>

// ��������� ����� MySharedPtr

template<typename T>
class MySharedPtr {
private:
    T* data;          // ��������� �� ����������� ������
    int* ref_count;   // ��������� �� ������� ������

public:
    explicit MySharedPtr(T* ptr = nullptr); // �����������
    MySharedPtr(const MySharedPtr& other);  // ���������� �����������
    MySharedPtr(MySharedPtr&& other) noexcept; // Move-�����������
    MySharedPtr& operator=(const MySharedPtr& other); // �������� ������������ (�����������)
    MySharedPtr& operator=(MySharedPtr&& other) noexcept; // �������� ������������ (�����������)
    ~MySharedPtr();

    T& operator*() const; // �������� �������������
    T* operator->() const; // �������� ->

    bool operator==(const MySharedPtr& other) const; // �������� ��������� ==

    // ��� �����������
    friend struct std::hash<MySharedPtr>;
};

#include "MySharedPtr.hpp" // �������� ����������

#endif // MY_SHARED_PTR_H
