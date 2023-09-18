#include "foo_string.h"
#include <iostream>

#define ASSERT(condition) \
    do { \
        if (!(condition)) { \
            std::cout << "Assertion failed: (" #condition "), function " << __FUNCTION__ \
                        << ", file " << __FILE__ << ", line " << __LINE__ << "." << std::endl; \
            std::abort(); \
        } \
    } while (false)

#define ASSERT_LENGTH(str, len) \
    do { \
        FooString foo_string = FooString((char *)str); \
        ASSERT(foo_string.length() == len); \
    } while (false)

int main() {
    ASSERT_LENGTH("Hello world", 12);
    ASSERT_LENGTH(" ", 2);
    ASSERT_LENGTH("", 1);

    return 0;
}
