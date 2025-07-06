cmake_minimum_required(VERSION 3.31)
project(Soma_Vector)

set(CMAKE_CXX_STANDARD 26)

add_executable(Soma_Vector main.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(Soma_Vector PUBLIC OpenMP::OpenMP_CXX)
endif()