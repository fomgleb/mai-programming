#include <iostream>
#include <thread>
#include <mutex>

// Посмотреть каким образом можно сделать поток при помощи стандартной библиотеки поток если мы хотим в качестве функции потока, метод класса.
// Реализовать программу в которой будет 2 потока. В 1 инкрементируем глобальную переменную float, а во втором выводим на экран.

float global_variable = 0;
std::mutex global_variable_mutex;

void increment_global_variable() {
    for (int i = 0; i < 100000; i++) {
        global_variable_mutex.lock();
        global_variable++;
        global_variable_mutex.unlock();
    }
}

void print_global_variable() {
    for (int i = 0; i < 100; i++) {
        global_variable_mutex.lock();
        std::cout << global_variable << std::endl;
        global_variable_mutex.unlock();
    }
}

int main() {
    std::thread incrementing_global_variable_thread(increment_global_variable);
    std::thread printing_global_variable_thread(print_global_variable);

    incrementing_global_variable_thread.join();
    printing_global_variable_thread.join();

    return 0;
}
