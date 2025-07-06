#include <iostream>
#include <cmath>
#include <print>
#include <chrono>
#include <omp.h>
int main()
{
    const std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    unsigned long n = 99'999;
    unsigned long aux = 2;
    unsigned long prime = 0;

    // Solução por Força bruta

	// #pragma omp parallel for firstprivate(aux) reduction(+:prime)                                // 183079 microsegs
	// #pragma omp parallel for firstprivate(aux) reduction(+:prime) schedule(dynamic)              // 125989 microsegs
	#pragma omp parallel for firstprivate(aux) reduction(+:prime) schedule(guided)                  // 120551 microsegs
    for (long i = 2; i <= n; i++)
    {
        while (aux < i)
        {
            if (i % aux == 0)   break;
            aux++;
        }

        if (aux == i) prime++;

        aux = 2;
    }
    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    const std::chrono::steady_clock::duration duration = end - start;

    if (duration == std::chrono::steady_clock::duration::zero())
        std::println("no time elapsed");

    std::println("{} primos entre 1 e {}",prime,n);

    std::println("Tempo para rodar a tarefa {} milliseconds",std::chrono::duration_cast<std::chrono::milliseconds>(duration).count());
    return 0;
}