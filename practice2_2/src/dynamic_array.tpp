#pragma once

#include "dynamic_array.hpp"

template <typename T>
DynamicArray<T>::DynamicArray(size_t size) : size(size) {
    array = new T[size]();
}

template <typename T>
DynamicArray<T>::DynamicArray(std::initializer_list<T> init) : size(init.size()) {
    array = new T[size]();
    auto it = init.begin();
    for (size_t i = 0; i < size; ++i, ++it) {
        set(i, *it);
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] array;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &dynamic_array) {
    size = dynamic_array.size;
    array = new T[size];
    std::copy(dynamic_array.array, dynamic_array.array + size * sizeof(T), array);
}

template <typename T>
void DynamicArray<T>::set(size_t index, T value) {
    if (index >= size) {
        throw out_of_range("Index " + to_string(index) + " is out of range. Array size is " + to_string(size) + ".");
    }
    if constexpr (std::is_integral_v<T>) {
        if (value < -100 || value > 100) {
            throw invalid_argument("Value " + to_string(value) + "is out of range (-100, 100).");
        }
    }
    array[index] = value;
}

template <typename T>
T DynamicArray<T>::get(size_t index) const {
    if (index >= size) {
        throw out_of_range("Index " + to_string(index) + " is out of range. Array size is " + to_string(size) + ".");
    }
    return array[index];
}

template <typename T>
size_t DynamicArray<T>::getSize() const {
    return size;
}

template <typename T>
void DynamicArray<T>::print() const {
    for (size_t i = 0; i < size - 1; i++) {
        std::cout << array[i];
        std::cout << " ";
    }
    std::cout << array[size - 1] << std::endl;
}

template <typename T>
void DynamicArray<T>::pushBack(T value) {
    if constexpr (std::is_integral_v<T>) {
        if (value < -100 || value > 100) {
            throw invalid_argument("Value " + to_string(value) + "is out of range (-100, 100).");
        }
    }
    T* extended_array = new T[size + 1];
    std::copy(array, array + size * sizeof(T), extended_array);
    extended_array[size++] = value;
    delete[] array;
    array = extended_array;
}

template <typename T>
void DynamicArray<T>::add(const DynamicArray &adding_array) {
    for (size_t i = 0; i < size && i < adding_array.size; i++) {
        array[i] += adding_array.array[i];
    }
}

template <typename T>
void DynamicArray<T>::subtract(const DynamicArray &subtracing_array) {
    for (size_t i = 0; i < size && i < subtracing_array.size; i++) {
        array[i] -= subtracing_array.array[i];
    }
}
