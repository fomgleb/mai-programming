#pragma once

#include <iostream>

class DynamicArray {
    int8_t* array = nullptr;
    size_t size = 0;
public:
    DynamicArray(size_t);
    ~DynamicArray();
    void print();
};
