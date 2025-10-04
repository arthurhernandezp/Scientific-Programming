#include <chrono>
#include <memory>
#include <fmt/format.h>
#include <omp.h>

void init(std::shared_ptr<int []> &v, size_t s)
{
    v = std::make_shared<int[]>(s);

    for (int i = 0; i < s; ++i)
    {
        v[i] = 1;
    }
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

    unsigned long int acc = 0;
    // std::shared_ptr<unsigned long int[]> local_acc;
    struct alignas(64) Padded { unsigned long val; };
    std::shared_ptr<Padded[]> local_acc(new Padded[NUM_THREADS]);
    // std::shared_ptr<Padded[]> local_acc;
    #pragma omp parallel
    {
        #pragma omp single
        {
            // Executada somente uma vez pela a primeira thread escalonada

            // local_acc = std::make_shared<Padded[]>(NUM_THREADS);
            // std::println("Executada pela thread: {}",omp_get_thread_num());
        }
        //Divisão do trabalho
        int chunk = size / NUM_THREADS;
        int local_init = chunk * omp_get_thread_num();
        int local_end = chunk * (omp_get_thread_num() + 1);

        if ((NUM_THREADS - 1) == omp_get_thread_num())
            local_end = size;

        local_acc[omp_get_thread_num()].val = 0;

        // soma sem race condition, cada thread em sua posição na memoria
        for (int i = local_init; i < local_end; ++i)
        {
            local_acc[omp_get_thread_num()].val += vec[i];
        }

        //  sincronização garantida de que todas as threads terminaram as suas tarefas
        #pragma omp barrier

        //  Redução a um só valor
        #pragma omp single
        {
            for (int i = 0; i < omp_get_num_threads(); ++i)
            {
                acc += local_acc[i].val;
            }
        }
    }

    // Equivalente a essa forma de implementar
    // #pragma omp parallel for reduction(+:acc)
    // for (auto i= 0; i < size; ++i)
    // {
    //     acc += vec[i];
    // }
    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    const std::chrono::steady_clock::duration duration = end - start;

    if (duration == std::chrono::steady_clock::duration::zero())
        fmt::println("no time elapsed");

    fmt::println("Tempo para rodar a tarefa {} microsegundos, e o valor de acc e: {}",std::chrono::duration_cast<std::chrono::microseconds>(duration).count(),acc);
    return 0;
}
