#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) {
    // 1. Inicializa o ambiente MPI
    // Todos os processos chamam esta função para iniciar o MPI
    MPI_Init(&argc, &argv);

    // 2. Obtém o número total de processos (rank size)
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // 3. Obtém o rank (ID) do processo atual
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // 4. Obtém o nome do processador
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // 5. Imprime a mensagem de cada processo
    std::cout << "Hello World do Processo " << world_rank
              << " de " << world_size << " rodando em "
              << processor_name << std::endl;

    // 6. Finaliza o ambiente MPI
    // Todos os processos chamam esta função para encerrar o MPI
    MPI_Finalize();

    return 0;
}
