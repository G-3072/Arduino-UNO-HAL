cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

option(BUILD_TESTING "build the module tests" OFF)

project(Arduino-HAL VERSION 1.0 LANGUAGES C ASM)

add_subdirectory(HAL)
if(BUILD_TESTING)
    add_subdirectory(main)
    add_subdirectory(tests)
endif()