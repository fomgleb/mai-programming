#pragma once

#include <type_traits>
#include <iostream>
#include <string>

using std::to_string;
using std::out_of_range;
using std::invalid_argument;

template<typename T>
class DynamicArray {
    T* array = nullptr;
    size_t size = 0;
public:
    DynamicArray(size_t);
    DynamicArray(std::initializer_list<T> init);
    ~DynamicArray();
    DynamicArray(const DynamicArray &dynamic_array);
    void set(size_t index, T value);
    T get(size_t index) const;
    size_t getSize() const;
    void print() const;
    void pushBack(T value);
    void add(const DynamicArray &array);
    void subtract(const DynamicArray &array);
};

#include "dynamic_array.tpp"
