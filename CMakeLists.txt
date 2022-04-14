cmake_minimum_required(VERSION 3.4...3.18)
project(market_py2cpp)

#set(CMAKE_VERBOSE_MAKEFILE ON)

# Propagates to bitfinex_cpp
add_compile_options(-march=native -mtune=native) # core-avx2

add_subdirectory(extern/pybind11)
pybind11_add_module(market_py2cpp src/py_quotes.cpp)

add_subdirectory(extern/bitfinex_cpp)
target_link_libraries(market_py2cpp LINK_PUBLIC bitfinex)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(market_py2cpp
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
