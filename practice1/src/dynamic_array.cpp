#include "dynamic_array.hpp"

DynamicArray::DynamicArray(size_t size) : size(size) {
    array = new int8_t[size];
}

DynamicArray::~DynamicArray() {
    delete[] array;
}
