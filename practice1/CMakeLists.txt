cmake_minimum_required(VERSION 3.27)
project(practice1)
set(CMAKE_CXX_STANDARD 17)
enable_testing()

set(SOURCE_DIR src)
set(HEADER_DIR inc)
set(TESTS_DIR test)

include_directories(${HEADER_DIR})
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp" "${HEADER_DIR}/*.h")
