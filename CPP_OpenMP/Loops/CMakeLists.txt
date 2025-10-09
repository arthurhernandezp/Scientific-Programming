cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

add_executable(Loops main.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(Loops PUBLIC OpenMP::OpenMP_CXX)
endif()

target_link_libraries(Loops PUBLIC fmt::fmt)
