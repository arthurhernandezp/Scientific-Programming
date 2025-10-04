cmake_minimum_required(VERSION 3.31)

add_executable(Calcula_PI main.cpp)

find_package(OpenMP)

if(OpenMP_CXX_FOUND)
    target_link_libraries(Calcula_PI PUBLIC OpenMP::OpenMP_CXX)
endif()

target_link_libraries(Calcula_PI PUBLIC fmt::fmt)
