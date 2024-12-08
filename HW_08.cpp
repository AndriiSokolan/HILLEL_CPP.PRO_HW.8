#include <iostream>
#include <unordered_set>
#include "MySharedPtr.h"

int main() {
    // Создание и копирование указателя
    MySharedPtr<int> ptr1(new int(42));
    MySharedPtr<int> ptr2 = ptr1; // Копирование

    // Перемещение указателя
    MySharedPtr<int> ptr3 = std::move(ptr1); // Перемещение

    // Сравнение указателей
    std::cout << "ptr2 == ptr3: " << (ptr2 == ptr3 ? "true" : "false") << std::endl;

    // Использование в unordered_set
    std::unordered_set<MySharedPtr<int>> my_set;
    my_set.insert(ptr2);
    my_set.insert(ptr3);

    std::cout << "Size of unordered_set: " << my_set.size() << std::endl;

    return 0;
}
