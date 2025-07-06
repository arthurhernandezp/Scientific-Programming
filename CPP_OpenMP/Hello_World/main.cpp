#include <iostream>
#include <print> // For std::println
#include <omp.h>
int main(int argc, char** argv)
{
    //  Forma alternativa de determinar o número de threads que o openmp pode paralelizar
    //  Outra forma é usar a variavel de ambiente OMP_NUM_THREADS
    omp_set_num_threads(5);

    #pragma omp parallel
    {
        int threads_num = 0;

        #if _OPENMP
            threads_num = omp_get_thread_num();
        #endif
        std::println("Hello World from thread: {}",threads_num);
    }

    return 0;
}

