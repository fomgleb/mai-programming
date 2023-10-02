#pragma once

#include <iostream>

template <typename T>
class List {
    struct Node {
        Node* next;
        T data;
    }* head = nullptr;
};
