cmake_minimum_required(VERSION 3.31)
project(Data_Problems)

set(CMAKE_CXX_STANDARD 26)

add_executable(Data_Problems main.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(Data_Problems PUBLIC OpenMP::OpenMP_CXX)
endif()