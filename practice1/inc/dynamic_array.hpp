#pragma once

#include <iostream>
#include <string>

using std::to_string;
using std::out_of_range;

class DynamicArray {
    int8_t* array = nullptr;
    size_t size = 0;
public:
    DynamicArray(size_t);
    ~DynamicArray();
    DynamicArray(const DynamicArray &dynamic_array);
    void set(size_t index, int8_t value);
    int8_t get(size_t index);
    size_t getSize();
    void print();
};
