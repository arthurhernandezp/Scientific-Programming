cmake_minimum_required(VERSION 3.31)

add_executable(SumTwoArrays main.cpp)

target_link_libraries(SumTwoArrays PUBLIC fmt::fmt)

target_link_libraries(SumTwoArrays
    PRIVATE
        Benchmark
)
