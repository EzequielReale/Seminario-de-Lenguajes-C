#include <stdio.h>
#include <stdlib.h>

int *inicializar(int **x)
{
    return malloc(sizeof(int));
}

int main()
{
    int *x;
    inicializar(&x);
    printf("%p", x);
    return 0;
}