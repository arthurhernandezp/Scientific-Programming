cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_STANDARD 26)

add_executable(Soma_Vector main.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(Soma_Vector PUBLIC OpenMP::OpenMP_CXX)
endif()

target_link_libraries(Soma_Vector PUBLIC fmt::fmt)
