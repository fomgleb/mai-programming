cmake_minimum_required(VERSION 3.0)
project(lecture1)
set(SOURCE_DIR src)
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
