#pragma once

#include <iostream>

template <typename T>
class List {
    size_t size = 0;
    struct Node {
        Node* next = nullptr;
        T data = T();
    }* head = nullptr;
public:
    ~List() {
        Node* nextNode = nullptr;
        for (Node* node = head; node != nullptr; node = nextNode) {
            nextNode = node->next;
            delete node;
        }
    }
    size_t GetSize() { return size; }
    struct iterator {
        Node* current;
        iterator(Node* node) : current(node) {}
        bool operator!=(const iterator& other) { return current != other.current; }
        void operator++() { current = current->next; }
        T& operator*() { return current->data; }
    };
    iterator begin() { return iterator(head); }
    iterator end() { return iterator(nullptr); }
};
