#include "MySharedPtr.h"

int main() {
    MySharedPtr<int> ptr1(new int(42));
    {
        MySharedPtr<int> ptr2 = ptr1;
        std::cout << "Value from ptr2: " << *ptr2 << std::endl;
        *ptr2 = 100;
        std::cout << "Value from ptr1 after modification: " << *ptr1 << std::endl;
    }
    std::cout << "Back in main, value from ptr1: " << *ptr1 << std::endl;
    return 0;
}
