cmake_minimum_required(VERSION 3.31)
project(Loops)

set(CMAKE_CXX_STANDARD 26)

add_executable(Loops main.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(Loops PUBLIC OpenMP::OpenMP_CXX)
endif()
