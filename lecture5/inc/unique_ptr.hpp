#pragma once

template <typename T>
class UniquePtr {
    T* ptr;
public:
    explicit UniquePtr(T* ptr);
    ~UniquePtr();
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
    UniquePtr(UniquePtr&& other);
    UniquePtr& operator=(UniquePtr&& other);
    T& operator*() const;
    T* operator->() const;
};

#include "unique_ptr.tpp"
