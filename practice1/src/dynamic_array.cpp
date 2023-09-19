#include "dynamic_array.hpp"

DynamicArray::DynamicArray(size_t size) : size(size) {
    array = new int8_t[size];
}

DynamicArray::~DynamicArray() {
    delete[] array;
}

void DynamicArray::print() {
    std::cout << "(";
    for (size_t i = 0; i < size; i++) {
        std::cout << array[i];
        if (i >= size - 1) continue;
        std::cout << ", ";
    }
    if (size == 0) {
        std::cout << "empty";
    }
    std::cout << ")" << std::endl;
}
