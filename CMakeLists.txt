cmake_minimum_required(VERSION 3.10)
project(Scientific-Programming LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)

add_subdirectory(common)
add_subdirectory(CPP_MPI)
add_subdirectory(CPP_OpenMP)
# add_subdirectory(CPP_CUDA)
