#pragma once

#include "unique_ptr.hpp"

template <typename T>
UniquePtr<T>::UniquePtr(T* ptr) : ptr(ptr) { }

template <typename T>
UniquePtr<T>::~UniquePtr() { delete ptr; }

template <typename T>
UniquePtr<T>::UniquePtr(UniquePtr&& other) : ptr(other.ptr) { other.ptr = nullptr; }

template <typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr&& other) {
    if (this != &other) {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

template <typename T>
T& UniquePtr<T>::operator*() const { return *ptr; }

template <typename T>
T* UniquePtr<T>::operator->() const { return ptr; }
