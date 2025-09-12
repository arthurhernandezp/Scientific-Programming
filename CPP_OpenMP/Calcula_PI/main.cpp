#include <stdio.h>
#include <omp.h>
#include <cstring>
#include <cmath>
#include <mutex>
#include <chrono>
#include <iostream>
int main(int argc, char *argv[])
{
    int N, id, num_threads, i = 0;
    double PI25DT = 3.141592653589793238462643;
    double mypi, h, sum, x;

    if (argc != 2) 
    {
        printf("Usage: a.out N\n");
        exit(0);
    }

    N = atoi(argv[1]);

    h   = 1.0 / (double) N;
    sum = 0.0;

    const std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    #pragma omp parallel private(x,i,id,num_threads) reduction(+:sum)
    {
        #ifdef _OPENMP
        {
            id = omp_get_thread_num();
            num_threads = omp_get_num_threads();
        }
        #else
            id = 0;
            num_threads = 1;
        #endif

        for (i = id*(N/num_threads) + 1; i <= (id+1)*(N/num_threads);i++) 
        {
            x = h * ((double)i - 0.5);
            sum += 4.0 / (1.0 + x*x);
        }
    }
    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    const std::chrono::steady_clock::duration duration = end - start;
    mypi = h * sum;
    printf("pi is approximately %.16f, Error is %.16f\n", mypi, fabs(mypi - PI25DT));
    std::cout << "Tempo para rodar a tarefa " <<std::chrono::duration_cast<std::chrono::microseconds>(duration).count()<<" microseconds\n";

    return 0;
}
