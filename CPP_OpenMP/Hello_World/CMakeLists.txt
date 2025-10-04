cmake_minimum_required(VERSION 3.31)

set(CMAKE_CXX_STANDARD 26)

add_executable(Hello_World main.cpp)

find_package(OpenMP )
if(OpenMP_CXX_FOUND)
    target_link_libraries(Hello_World PUBLIC OpenMP::OpenMP_CXX)
endif()
