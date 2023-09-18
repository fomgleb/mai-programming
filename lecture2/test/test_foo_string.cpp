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

#define ASSERT_COMPARE_STR(string_1, string_2, is_identical) \
    do { \
        FooString foo_string = FooString((char *)string_1); \
        ASSERT(foo_string.compare((char*)string_2) == is_identical); \
    } while (false)

int main() {
    ASSERT_LENGTH("Hello world", 12);
    ASSERT_LENGTH(" ", 2);
    ASSERT_LENGTH("", 1);

    ASSERT_COMPARE_STR("Hello word", "Hello word", true);
    ASSERT_COMPARE_STR("1", "2", false);
    ASSERT_COMPARE_STR("32", NULL, false);
    ASSERT_COMPARE_STR("", "", true);

    return 0;
}
