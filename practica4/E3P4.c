#include <stdio.h>

void inicializar(int *x)
{
    *x = 0;
}

int main()
{
    int x = 1;
    inicializar(&x);
    printf("%d", x);
    return 0;
}