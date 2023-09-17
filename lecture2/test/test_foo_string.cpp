#include "cassert"
#include "foo_string.h"

void assert_length(const char *const, const int);

int main() {
    assert_length("Hello world", 12);
    assert_length(" ", 2);
    assert_length("", 1);

    return 0;
}

void assert_length(const char *const string, const int length) {
    FooString foo_string = FooString((char *)string);
    assert(foo_string.length() == length);
}
