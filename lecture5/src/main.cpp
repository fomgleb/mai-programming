#include "iostream"
#include "unique_ptr.hpp"

int main() {
    UniquePtr<int> ptr = UniquePtr<int>(new int);
    *ptr = 123;

    std::cout << *ptr << std::endl;
    return 0;
}
