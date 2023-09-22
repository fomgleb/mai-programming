#include "dynamic_array.hpp"

DynamicArray::DynamicArray(size_t size) : size(size) {
    array = new int8_t[size]();
}

DynamicArray::DynamicArray(std::initializer_list<int8_t> init) : size(init.size()) {
    array = new int8_t[size]();
    auto it = init.begin();
    for (size_t i = 0; i < size; ++i, ++it) {
        set(i, *it);
    }
}

DynamicArray::~DynamicArray() {
    delete[] array;
}

DynamicArray::DynamicArray(const DynamicArray &dynamic_array) {
    size = dynamic_array.size;
    array = new int8_t[size];
    std::copy(dynamic_array.array, dynamic_array.array + size * sizeof(int8_t), array);
}

void DynamicArray::set(size_t index, int8_t value) {
    if (index >= size) {
        throw out_of_range("Index " + to_string(index) + " is out of range. Array size is " + to_string(size) + ".");
    }
    if (value < -100 || value > 100) {
        throw out_of_range("Value " + to_string(value) + "is out of range (-100, 100).");
    }
    array[index] = value;
}

int8_t DynamicArray::get(size_t index) const {
    if (index >= size) {
        throw out_of_range("Index " + to_string(index) + " is out of range. Array size is " + to_string(size) + ".");
    }
    return array[index];
}

size_t DynamicArray::getSize() const {
    return size;
}

void DynamicArray::print() const {
    for (size_t i = 0; i < size; i++) {
        std::cout << static_cast<int>(array[i]);
        if (i >= size - 1) continue;
        std::cout << " ";
    }
    std::cout << std::endl;
}

void DynamicArray::pushBack(int8_t value) {
    if (value < -100 || value > 100) {
        throw out_of_range("Value " + to_string(value) + "is out of range (-100, 100).");
    }
    int8_t* extended_array = new int8_t[size + 1];
    std::copy(array, array + size * sizeof(int8_t), extended_array);
    extended_array[size++] = value;
    delete[] array;
    array = extended_array;
}

void DynamicArray::add(const DynamicArray &adding_array) {
    for (size_t i = 0; i < size && i < adding_array.size; i++) {
        array[i] += adding_array.get(i);
    }
}

void DynamicArray::subtract(const DynamicArray &subtracing_array) {
    for (size_t i = 0; i < size && i < subtracing_array.size; i++) {
        array[i] -= subtracing_array.get(i);
    }
}
