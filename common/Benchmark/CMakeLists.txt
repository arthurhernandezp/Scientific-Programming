cmake_minimum_required(VERSION 3.16) # 3.31 ainda é muito nova, use algo mais comum
project(BenchmarkLib LANGUAGES CXX)

# Arquivos da lib
set(SOURCE_FILES
    src/Benchmark.cpp
    include/Benchmark.hpp
)

# Criar biblioteca estática
add_library(Benchmark STATIC ${SOURCE_FILES})

# Definir pasta de headers públicos
target_include_directories(Benchmark
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Benchmark PUBLIC fmt::fmt)
