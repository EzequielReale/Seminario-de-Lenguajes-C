#include <stdio.h>
#include <stdarg.h>

int sumatoria(int cant, ...)
{
    int suma = 0;
    va_list args;
    va_start(args, cant);
    for (int i = 0; i < cant; i++) suma += va_arg(args, int);
    va_end(args);
    return suma;
}

int main()
{
    printf("%d + %d + %d + %d = %d\n", 1, 2, 3, 4, sumatoria(4, 1, 2 ,3 ,4));
    return 0;
}