cmake_minimum_required(VERSION 3.4...3.18)
project(bitfinex_quotes)

#set(CMAKE_VERBOSE_MAKEFILE ON)

# Propagates to bitfinex_cpp
add_compile_options(-march=native -mtune=native) # core-avx2

add_subdirectory(extern/pybind11)
pybind11_add_module(bitfinex_quotes src/main.cpp)

add_subdirectory(extern/bitfinex_cpp)
target_link_libraries(bitfinex_quotes LINK_PUBLIC bitfinex)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(bitfinex_quotes
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
