# General settings
cmake_minimum_required(VERSION 3.27)
project(practice2_2)
set(CMAKE_CXX_STANDARD 17)

# Git submodules updating
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

# Paths to directories
set(SOURCE_DIR src)
set(HEADER_DIR inc)
set(TESTS_DIR test)

# Creating a static library from sources
file(GLOB SOURCES "${SOURCE_DIR}/*cpp")
list(REMOVE_ITEM SOURCES "${SOURCE_DIR}/main.cpp")
add_library(sources_lib STATIC ${SOURCES})
target_include_directories(sources_lib PUBLIC ${HEADER_DIR})

# Creating executable file for main.cpp
add_executable(main ${SOURCE_DIR}/main.cpp)
target_link_libraries(main sources_lib)

option(USE_TESTING "Use testing" OFF)
if(USE_TESTING)
    # Testing settings
    enable_testing()
    add_subdirectory(libs/googletest)
    include(GoogleTest)

    # Creating executable files for tests
    file(GLOB TEST_SOURCES "${TESTS_DIR}/*.cpp")
    foreach(TEST_SRC ${TEST_SOURCES})
        get_filename_component(TEST_NAME ${TEST_SRC} NAME_WE)
        add_executable(${TEST_NAME} ${TEST_SRC})
        target_link_libraries(${TEST_NAME} sources_lib gtest_main)
        gtest_discover_tests(${TEST_NAME})
    endforeach()
endif()
