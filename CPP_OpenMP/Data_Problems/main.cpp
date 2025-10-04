#include <omp.h>
#include <fmt/format.h>
#include <stdio.h>
int main()
{
    int x = 100;

    printf("Fora da zona paralela Valor de x: %d, endereco de x:%p\n",x,&x);
    #pragma omp parallel firstprivate(x)
    {
        printf("Valor de x: %d, endereco de x:%p\n",x,&x);
        x = omp_get_thread_num();
        fmt::println("\nSou a thread: {}, imprimindo x = {}",omp_get_thread_num(),x);
    }
    return 0;
}
