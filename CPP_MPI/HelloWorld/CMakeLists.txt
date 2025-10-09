cmake_minimum_required(VERSION 3.10)
# Define as linguagens C e C++ (CXX) para o projeto
project(OpenMPI_Project C CXX)

# Garante um padrão C++ moderno e obrigatório
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 1. Localiza a implementação MPI instalada (Open MPI)
# O FindMPI procurará o Open MPI no ambiente WSL.
# Pedimos suporte a C e C++ (apenas a API C é usada em C++ moderno)
find_package(MPI REQUIRED COMPONENTS C CXX)

# 2. Adiciona o executável
add_executable(meu_programa main.cpp)

# 3. Vincula o executável com as bibliotecas MPI
# O CMake usará as variáveis definidas pelo find_package
target_link_libraries(meu_programa PRIVATE ${MPI_LIBRARIES})

# 4. Adiciona os includes (geralmente não é estritamente necessário no WSL, mas é uma boa prática)
target_include_directories(meu_programa PRIVATE ${MPI_INCLUDE_PATH})
