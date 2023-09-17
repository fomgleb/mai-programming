cmake_minimum_required(VERSION 3.27)
project(lecture2)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_DIR src)
set(HEADER_DIR inc)

include_directories(${HEADER_DIR})
file(GLOB SOURCES
    "${SOURCE_DIR}/*.cpp"
    "${HEADER_DIR}/*.h")
