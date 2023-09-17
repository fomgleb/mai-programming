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
