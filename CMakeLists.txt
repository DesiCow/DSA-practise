cmake_minimum_required(VERSION 4.3)
project(HelloDSA)

set(CMAKE_CXX_STANDARD 20)

add_executable(patterns patterns.cpp)
add_executable(sorting sorting.cpp
        codeforcesSolution.cpp)
add_executable(stl stl.cpp)
add_executable(codeforces codeforcesSolution.cpp)
add_executable(recursion recursion.cpp)
