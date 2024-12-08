template<typename T>
MySharedPtr<T>::MySharedPtr(T* ptr)
    : data(ptr), ref_count(new int(1)) {
    std::cout << "MySharedPtr created, ref_count = " << *ref_count << std::endl;
}

template<typename T>
MySharedPtr<T>::MySharedPtr(const MySharedPtr& other)
    : data(other.data), ref_count(other.ref_count) {
    ++(*ref_count);
    std::cout << "MySharedPtr copied, ref_count = " << *ref_count << std::endl;
}

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
    std::cout << "MySharedPtr assigned, ref_count = " << *ref_count << std::endl;
    return *this;
}

template<typename T>
MySharedPtr<T>::~MySharedPtr() {
    if (--(*ref_count) == 0) {
        delete data;
        delete ref_count;
        std::cout << "MySharedPtr fully destroyed" << std::endl;
    } else {
        std::cout << "MySharedPtr destroyed, ref_count = " << *ref_count << std::endl;
    }
}

template<typename T>
T& MySharedPtr<T>::operator*() const {
    assert(data != nullptr);
    return *data;
}

template<typename T>
T* MySharedPtr<T>::operator->() const {
    assert(data != nullptr);
    return data;
}
