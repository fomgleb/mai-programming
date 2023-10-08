#include "dynamic_array.hpp"

int get_num() {
    int num;
    std::cin >> num;
    return num;
}

DynamicArray<int8_t>* getArray() {
    size_t arr_length = get_num();
    DynamicArray<int8_t>* arr = new DynamicArray<int8_t>(arr_length);
    for (size_t i = 0; i < arr_length; ++i) {
        int8_t element = get_num();
        arr->set(i, element);
    }
    return arr;
}

int main() {
    DynamicArray<int8_t>* arrays[] = {getArray(), getArray()};

    size_t commands_count = get_num();
    for (size_t i = 0; i < commands_count; i++) {
        int command = get_num();
        switch (command) {
        case 1:
            try {
                std::cout << static_cast<int>(arrays[get_num() - 1]->get(get_num())) << std::endl;
            } catch (std::out_of_range) {
                std::cout << "std:out_of_range" << std::endl;
            }
            break;
        case 2: {
            size_t array_index = get_num() - 1;
            size_t index = get_num();
            int8_t value = get_num();
            try {
                arrays[array_index]->set(index, value);
            } catch (std::out_of_range) {
                std::cout << "std:out_of_range" << std::endl;
            } catch (std::invalid_argument) {
                std::cout << "std:invalid_argument" << std::endl;
            }
            break;
        }
        case 3:
            try {
                arrays[get_num() - 1]->pushBack(get_num());
            } catch (std::invalid_argument) {
                std::cout << "std:invalid_argument" << std::endl;
            }
             break;
        case 4:
            arrays[get_num() - 1]->print(); break;
        case 5:
            if (get_num() - 1 == 0) arrays[0]->add(*arrays[1]);
            else arrays[1]->add(*arrays[0]);
            break;
        case 6:
            if (get_num() - 1 == 0) arrays[0]->subtract(*arrays[1]);
            else arrays[1]->subtract(*arrays[0]);
            break;
        }
    }

    delete arrays[0];
    delete arrays[1];

    return 0;
}
