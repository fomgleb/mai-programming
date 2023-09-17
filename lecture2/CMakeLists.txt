cmake_minimum_required(VERSION 3.27)
project(lecture2)
set(CMAKE_CXX_STANDARD 17)
enable_testing()

set(SOURCE_DIR src)
set(HEADER_DIR inc)
set(TESTS_DIR test)

include_directories(${HEADER_DIR})
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp" "${HEADER_DIR}/*.h")

add_executable(fooStringTest "${TESTS_DIR}/test_foo_string.cpp" ${SOURCES})
add_test(NAME fooStringTest COMMAND fooStringTest)
