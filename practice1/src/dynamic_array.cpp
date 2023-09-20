#include "dynamic_array.hpp"

DynamicArray::DynamicArray(size_t size) : size(size) {
    array = new int8_t[size]();
}

DynamicArray::~DynamicArray() {
    delete[] array;
}

void DynamicArray::set(size_t index, int8_t value) {
    if (index >= size) {
        throw out_of_range("Index " + to_string(index) + " is out of range. Array size is " + to_string(size) + ".");
    }
    if (value < -100 || value > 100) {
        throw out_of_range("Value " + to_string(index) + "is out of range (-100, 100).");
    }
    array[index] = value;
}

int8_t DynamicArray::get(size_t index) {
    if (index >= size) {
        throw out_of_range("Index " + to_string(index) + " is out of range. Array size is " + to_string(size) + ".");
    }
    return array[index];
}

size_t DynamicArray::getSize() {
    return size;
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
