#include <iostream>
#include <omp.h>
#include <mutex>
#include <chrono>
#include <random>

// #define N 1500

// double a[N][N];
// double b[N][N];
// double c[N][N];

int main(int argc, char * argv[])
{
    int N;
    int i, j, k;

    if (argc > 1) N = atoi(argv[1]);
    else N = 4;

    int** a = new int*[N];
    int** b = new int*[N];
    int** c = new int*[N];

    for (int i = 0; i < N; ++i) {
        a[i] = new int[N];
        b[i] = new int[N];
        c[i] = new int[N];
    }
    const unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 generator(seed);

    for (i=0 ;i<N; i++)  
        for (j=0 ;j<N; j++) {
            std::uniform_real_distribution<double> distribution(0, 1);
            c[i][j] = 0;
            a[i][j] = distribution(generator); //drand48();
            b[i][j] = distribution(generator); //drand48();
    }

    const std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    #pragma omp parallel private(i,j,k)
    {
        #ifdef _OPENMP
        {
            #pragma omp single
            {    
                auto num_threads = omp_get_num_threads();

                std::cout << "Numero de threads: " << num_threads << '\n';
            }
        }
        #endif

        #pragma omp for
        for (i=0; i<N; i++) 
        {
            for (j=0; j<N; j++) 
                for (k=0; k<N; k++) 
                    c[i][j] = c[i][j] + a[i][k]*b[k][j];
        }
    } 
    
    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    const std::chrono::steady_clock::duration duration = end - start;


    // for (i=0; i<N; i++)
    //     for (j=0; j<N; j++)
    //         printf("C[%d][%d] = %f\n", i, j, c[i][j]);
    std::string modo_execucao = "sequencial";
    #ifdef _OPENMP
    {
        modo_execucao = "paralelo";
    }
    #endif
    std::cout << "Matriz["<< N << "][" << N << "]\n";
    std::cout << "Tempo para rodar a tarefa no modo " << modo_execucao << " " <<std::chrono::duration_cast<std::chrono::microseconds>(duration).count()<<" microseconds\n";
    std::cout << "Tempo para rodar a tarefa no modo " << modo_execucao << " " <<std::chrono::duration_cast<std::chrono::milliseconds>(duration).count()<<" milliseconds\n";

    delete[] a,b,c;
    return 0;
}
