#include "foo_string.h"
#include <iostream>
#include <string.h>

FooString::FooString(char* tbuf) {
    size_t tbuf_size = strlen(tbuf);
    buf = new char[tbuf_size + 1];
    strcpy_s(buf, tbuf_size + 1, tbuf);
}

FooString::~FooString() {
    delete[] buf;
}

void FooString::show() {
    std::cout << buf << std::endl;
}

int FooString::length() {
    int string_length = 0;
    for (; buf[string_length] != '\0'; string_length++) { }
    return string_length + 1;
}

bool FooString::compare(FooString& str) {
    return compare(str.buf);
}

bool FooString::compare(char* str) {
    if (str == NULL) {
        return false;
    }

    size_t str_length = strlen(str);
    size_t i = 0;
    for (; str[i] == buf[i] && i < str_length; i++) { }
    if (str_length == i) {
        return true;
    }
    return false;
}

void FooString::add(char* str) {
    if (str == NULL || strlen(str) == 0) {
        return;
    }

    int current_str_length = length() - 1;
    size_t adding_str_length = strlen(str);
    size_t new_str_length = current_str_length + adding_str_length;

    char* new_str = new char[new_str_length + 1];
    for (size_t i = 0; i < current_str_length; i++) {
        new_str[i] = buf[i];
    }
    for (size_t i = 0; i < adding_str_length; i++) {
        new_str[i + current_str_length] = str[i];
    }
    new_str[new_str_length] = '\0';

    delete[] buf;
    buf = new_str;
}
