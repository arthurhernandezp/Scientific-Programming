#include <iostream>
#include <mpi.h>

int main(int argc, char** argv) {
    // Inicializa o ambiente MPI
    MPI_Init(&argc, &argv);

    // Obtém o número total de processos (o "tamanho do mundo")
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Obtém o rank (ID) do processo atual
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Obtém o nome do processador
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Imprime a mensagem de "Olá"
    std::cout << "Olá do processador " << processor_name
              << ", rank " << world_rank
              << " de " << world_size << " processos." << std::endl;

    // Finaliza o ambiente MPI
    MPI_Finalize();

    return 0;
}
