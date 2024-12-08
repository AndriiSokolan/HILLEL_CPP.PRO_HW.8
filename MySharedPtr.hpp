#include "MySharedPtr.h"

// Конструктор
template<typename T>
MySharedPtr<T>::MySharedPtr(T* ptr) : data(ptr), ref_count(new int(1)) {
    std::cout << "MySharedPtr created, ref_count = " << *ref_count << std::endl;
}

// Копирующий конструктор
template<typename T>
MySharedPtr<T>::MySharedPtr(const MySharedPtr& other)
    : data(other.data), ref_count(other.ref_count) {
    ++(*ref_count);
    std::cout << "MySharedPtr copied, ref_count = " << *ref_count << std::endl;
}

// Move-конструктор
template<typename T>
MySharedPtr<T>::MySharedPtr(MySharedPtr&& other) noexcept
    : data(other.data), ref_count(other.ref_count) {
    other.data = nullptr;
    other.ref_count = nullptr;
    std::cout << "MySharedPtr moved" << std::endl;
}

// Оператор присваивания (копирование)
template<typename T>
MySharedPtr<T>& MySharedPtr<T>::operator=(const MySharedPtr& other) {
    if (this != &other) {
        if (--(*ref_count) == 0) {
            delete data;
            delete ref_count;
            std::cout << "MySharedPtr data deleted" << std::endl;
        }
        data = other.data;
        ref_count = other.ref_count;
        ++(*ref_count);
    }
    std::cout << "MySharedPtr assigned (copy), ref_count = " << *ref_count << std::endl;
    return *this;
}

// Оператор присваивания (перемещение)
template<typename T>
MySharedPtr<T>& MySharedPtr<T>::operator=(MySharedPtr&& other) noexcept {
    if (this != &other) {
        if (--(*ref_count) == 0) {
            delete data;
            delete ref_count;
        }
        data = other.data;
        ref_count = other.ref_count;
        other.data = nullptr;
        other.ref_count = nullptr;
    }
    std::cout << "MySharedPtr assigned (move)" << std::endl;
    return *this;
}

// Оператор разыменования
template<typename T>
T& MySharedPtr<T>::operator*() const {
    assert(data != nullptr);
    return *data;
}

// Оператор ->
template<typename T>
T* MySharedPtr<T>::operator->() const {
    assert(data != nullptr);
    return data;
}

// Оператор ==
template<typename T>
bool MySharedPtr<T>::operator==(const MySharedPtr& other) const {
    return data == other.data;
}

// Деструктор
template<typename T>
MySharedPtr<T>::~MySharedPtr() {
    if (ref_count && --(*ref_count) == 0) {
        delete data;
        delete ref_count;
        std::cout << "MySharedPtr fully destroyed" << std::endl;
    }
    else if (ref_count) {
        std::cout << "MySharedPtr destroyed, ref_count = " << *ref_count << std::endl;
    }
}

// Шаблон std::hash для MySharedPtr
namespace std {
    template<typename T>
    struct hash<MySharedPtr<T>> {
        std::size_t operator()(const MySharedPtr<T>& ptr) const {
            return std::hash<T*>()(ptr.data); // Хешируем адрес
        }
    };
}
