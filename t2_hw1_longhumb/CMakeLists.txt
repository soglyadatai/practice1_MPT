cmake_minimum_required(VERSION 3.20)

project(long_number_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBRARY long_number)

add_library(${LIBRARY})

add_subdirectory(src)
add_subdirectory(test)