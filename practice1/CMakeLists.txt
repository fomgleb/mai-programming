cmake_minimum_required(VERSION 3.27)
project(practice1)
set(CMAKE_CXX_STANDARD 17)
enable_testing()

set(SOURCE_DIR src)
set(HEADER_DIR inc)
set(TESTS_DIR test)

option(GIT_SUBMODULE "Check submodules during build" ON)
if(GIT_SUBMODULE)
    message(STATUS "Updating submodules")
    find_package(Git REQUIRED)
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
        message(FATAL_ERROR "Command `${GIT_EXECUTABLE} submodule update --init --recursive` failed with `${GIT_SUBMOD_RESULT}`")
    endif()
endif()

include_directories(${HEADER_DIR})
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp" "${HEADER_DIR}/*.hpp")

add_subdirectory(libs/googletest)
include(GoogleTest)

add_executable(test_dynamic_array ${TESTS_DIR}/test_dynamic_array.cpp ${SOURCES})
target_link_libraries(test_dynamic_array gtest_main)
gtest_discover_tests(test_dynamic_array)
