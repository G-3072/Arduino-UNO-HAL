cmake_minimum_required(VERSION 3.14)

option(BUILD_TESTS "build test functions" OFF)

project(Arduino-HAL VERSION 1.0 LANGUAGES C)

add_subdirectory(HAL)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()