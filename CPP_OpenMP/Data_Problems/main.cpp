#include <omp.h>
#include <print>
#include <stdio.h>
int main()
{
    int x = 100;

    printf("Fora da zona paralela Valor de x: %d, endereco de x:%p\n",x,&x);
    #pragma omp parallel firstprivate(x)
    {
        printf("Valor de x: %d, endereco de x:%p\n",x,&x);
        x = omp_get_thread_num();
        std::println("Sou a thread: {}, imprimindo x = {}",omp_get_thread_num(),x);
    }
    return 0;
}
