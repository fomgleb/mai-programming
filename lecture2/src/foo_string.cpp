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
