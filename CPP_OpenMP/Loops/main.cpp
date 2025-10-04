#include <cmath>
#include <chrono>
#include <memory>
#include <random>
#include <fmt/format.h>
#include <omp.h>

void init(std::shared_ptr<int []> &v, size_t s)
{
    v = std::make_shared<int[]>(s);
    const unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::mt19937 generator(seed);
    for (int i = 0; i < s; ++i)
    {
        std::uniform_int_distribution<int> distribution(1, 1000);
        v[i] = distribution(generator);
    }
}

double square(const int &x)
{
    int k = 0;
    while (k < 5000) k++;           //Espera ocupada
    return std::sqrt(x);
}

int main()
{
    const std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    constexpr int NUM_THREADS = 12;
    omp_set_num_threads(NUM_THREADS);
    fmt::println("Usando {} threads",NUM_THREADS);
    std::shared_ptr<int[]> vec;
    constexpr size_t size = 1'000'000;
    init(vec, size);
    // Quebra o vetor no numero de threads(e.g: se exister 12 threads disponivel terá 12 partes divididas do vetor)
    #pragma omp parallel
    {
        int chuck = size / omp_get_num_threads();
        int local_init = chuck * omp_get_thread_num();
        int local_end = chuck * (omp_get_thread_num() + 1);

        if (omp_get_num_threads() - 1  == omp_get_num_threads())
            local_end = size;

        for (auto i= local_init; i < local_end; ++i)
        {
            vec[i] = square(vec[i]);
        }
    }
    // Essa implementação toda pode ser substituida por #pragma omp parallel for

    // #pragma omp parallel for
    // for (auto i= 0; i < size; ++i)
    // {
    //     vec[i] = square(vec[i]);
    // }
    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    const std::chrono::steady_clock::duration duration = end - start;

    if (duration == std::chrono::steady_clock::duration::zero())
        fmt::println("no time elapsed");

    fmt::println("Tempo para rodar a tarefa {} microsegundos",std::chrono::duration_cast<std::chrono::microseconds>(duration).count());
    return 0;
}
