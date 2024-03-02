cmake_minimum_required(VERSION 3.5)
project(Sort)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_EXE main.cpp)
set(SOURCE_LIB sortAlgorithms.hpp)
set(CMAKE_CXX_FLAGS_RELEASE -O3)

add_library(sortLib INTERFACE ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main sortLib)