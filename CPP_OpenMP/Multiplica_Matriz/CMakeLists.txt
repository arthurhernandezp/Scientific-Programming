cmake_minimum_required(VERSION 3.10)

add_executable(MultiplicaMatrix main.cpp)

find_package(OpenMP)

if(OpenMP_CXX_FOUND)
    target_link_libraries(MultiplicaMatrix PUBLIC OpenMP::OpenMP_CXX)
endif()

target_link_libraries(MultiplicaMatrix PUBLIC fmt::fmt Benchmark)
