cmake_minimum_required(VERSION 3.27)
project(practice1)
set(CMAKE_CXX_STANDARD 17)
enable_testing()

set(SOURCE_DIR src)
set(HEADER_DIR inc)
set(TESTS_DIR test)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Updating submodules")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

include_directories(${HEADER_DIR})
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp" "${HEADER_DIR}/*.h")
