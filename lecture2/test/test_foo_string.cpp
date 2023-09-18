#include "foo_string.h"
#include <iostream>
#include <string>
#include <sstream>

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

#define ASSERT_COMPARE_FOOSTR(string_1, string_2, is_identical) \
    do { \
        FooString foo_string_1 = FooString((char*)string_1); \
        FooString foo_string_2 = FooString((char*)string_2); \
        ASSERT(foo_string_1.compare(foo_string_2) == is_identical); \
    } while (false)

#define ASSERT_ADD_STR(initial_string, adding_string, new_string) \
    do { \
        FooString foo_string = FooString((char*)initial_string); \
        foo_string.add(adding_string); \
        ASSERT(get_foo_string_buf(foo_string) == std::string(new_string)); \
    } while (false)

#define ASSERT_ADD_FOOSTR(initial_string, adding_string, new_string) \
    do { \
        FooString foo_string = FooString((char*)initial_string); \
        FooString adding_foo_string = FooString((char*)adding_string); \
        foo_string.add(adding_foo_string); \
        ASSERT(get_foo_string_buf(foo_string) == std::string(new_string)); \
    } while (false)

std::string get_foo_string_buf(FooString&);

int main() {
    ASSERT_LENGTH("Hello world", 12);
    ASSERT_LENGTH(" ", 2);
    ASSERT_LENGTH("", 1);

    ASSERT_COMPARE_STR("Hello word", "Hello word", true);
    ASSERT_COMPARE_STR("1", "2", false);
    ASSERT_COMPARE_STR("32", NULL, false);
    ASSERT_COMPARE_STR("", "", true);

    ASSERT_COMPARE_FOOSTR("Hello word", "Hello word", true);
    ASSERT_COMPARE_FOOSTR("1", "2", false);
    ASSERT_COMPARE_FOOSTR("", "", true);

    ASSERT_ADD_STR("Hello", " world!", "Hello world!");
    ASSERT_ADD_STR("asdf", NULL, "asdf");
    ASSERT_ADD_STR("world", "", "world");
    ASSERT_ADD_STR("", "asd", "asd");
    ASSERT_ADD_STR("", NULL, "");

    ASSERT_ADD_FOOSTR("Hello", " world!", "Hello world!");
    ASSERT_ADD_FOOSTR("world", "", "world");
    ASSERT_ADD_FOOSTR("", "asd", "asd");

    return 0;
}

std::string get_foo_string_buf(FooString& foo_string) {
    std::streambuf* coutStream = std::cout.rdbuf();
    std::ostringstream tempStream;
    std::cout.rdbuf(tempStream.rdbuf());

    foo_string.show();

    std::cout.rdbuf(coutStream);

    std::string output = tempStream.str();
    return output.substr(0, output.size() - 1);
}
