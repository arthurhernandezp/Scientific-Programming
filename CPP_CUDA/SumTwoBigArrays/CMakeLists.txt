cmake_minimum_required(VERSION 3.10)

add_executable(SumTwoArrays main.cu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CUDA_STANDARD 17)

target_link_libraries(SumTwoArrays PUBLIC fmt::fmt)

target_link_libraries(SumTwoArrays
    PRIVATE
        Benchmark
)
