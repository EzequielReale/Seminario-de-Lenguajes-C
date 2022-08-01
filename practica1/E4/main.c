#include <stdio.h>
#include "matem.h"
int main()
{
    int desde = 1;
    int hasta = 10;
    int resultado = sumatoria(desde,hasta);
    printf("La sumatoria de %d a %d da: [ %d ]\n", desde, hasta, resultado);
    return 0;
}