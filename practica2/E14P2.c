#include <stdio.h>
#define cuadrado(x) x*x

int main()
{
    int x = 7;
    printf("El cuadrado de x=%d es: %d\n", x, cuadrado(x+1));
    return 0;
}