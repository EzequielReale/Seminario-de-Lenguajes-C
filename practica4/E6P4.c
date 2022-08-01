#include <stdio.h>

typedef struct 
{
    unsigned short dia, mes, anio;
} fecha;

void inicializar(fecha *hoy)
{
    hoy -> dia = 1;
    hoy -> mes = 1;
    hoy -> anio = 1970;
}

int main()
{
    fecha hoy;
    hoy.dia = 27;
    hoy.mes = 5;
    hoy.anio = 2022;
    printf("%d / %d / %d\n", hoy.dia, hoy.mes, hoy.anio);

    inicializar(&hoy);
    printf("%d / %d / %d\n", hoy.dia, hoy.mes, hoy.anio);
    return 0;
}