#ifndef MY_SHARED_PTR_H
#define MY_SHARED_PTR_H

#include <iostream>
#include <cassert>
#include <functional>

// Шаблонный класс MySharedPtr

template<typename T>
class MySharedPtr {
private:
    T* data;          // Указатель на управляемый ресурс
    int* ref_count;   // Указатель на счётчик ссылок

public:
    explicit MySharedPtr(T* ptr = nullptr); // Конструктор
    MySharedPtr(const MySharedPtr& other);  // Копирующий конструктор
    MySharedPtr(MySharedPtr&& other) noexcept; // Move-конструктор
    MySharedPtr& operator=(const MySharedPtr& other); // Оператор присваивания (копирование)
    MySharedPtr& operator=(MySharedPtr&& other) noexcept; // Оператор присваивания (перемещение)
    ~MySharedPtr();

    T& operator*() const; // Оператор разыменования
    T* operator->() const; // Оператор ->

    bool operator==(const MySharedPtr& other) const; // Оператор сравнения ==

    // Для хеширования
    friend struct std::hash<MySharedPtr>;
};

#include "MySharedPtr.hpp" // Включаем реализацию

#endif // MY_SHARED_PTR_H
