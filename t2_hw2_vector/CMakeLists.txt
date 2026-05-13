cmake_minimum_required(VERSION 3.20)

project(vector_list)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CONTAINERS_LIB containers_lib)
add_library(${CONTAINERS_LIB})
add_subdirectory(src)
enable_testing()
add_subdirectory(test)