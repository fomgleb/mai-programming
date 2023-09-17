#include "foo_string.h"
#include <iostream>
#include <string.h>

FooString::FooString(char* tbuf) {
    size_t tbuf_size = strlen(tbuf);
    buf = new char[tbuf_size + 1];
    strcpy_s(buf, tbuf_size + 1, tbuf);
}

FooString::~FooString() {
    delete buf;
}

void FooString::show() {
    std::cout << buf;
}

int FooString::length() {
    int string_length = 0;
    for (; buf[string_length] != '\0'; string_length++) { }
    return string_length + 1;
}
