cmake_minimum_required(VERSION 3.10)

add_executable(Count_Primos main.cpp)

find_package(OpenMP)

if(OpenMP_CXX_FOUND)
    target_link_libraries(Count_Primos PUBLIC OpenMP::OpenMP_CXX)
endif()

target_link_libraries(Count_Primos PUBLIC fmt::fmt)
