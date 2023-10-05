#pragma once

#include <iostream>
#include <string>

using std::to_string;
using std::out_of_range;
using std::invalid_argument;

class DynamicArray {
    int8_t* array = nullptr;
    size_t size = 0;
public:
    DynamicArray(size_t);
    DynamicArray(std::initializer_list<int8_t> init);
    ~DynamicArray();
    DynamicArray(const DynamicArray &dynamic_array);
    void set(size_t index, int8_t value);
    int8_t get(size_t index) const;
    size_t getSize() const;
    void print() const;
    void pushBack(int8_t value);
    void add(const DynamicArray &array);
    void subtract(const DynamicArray &array);
};
