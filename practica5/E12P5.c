#include <stdio.h>
#include <math.h>

void my_function_pow (long arr[], size_t tam, double (*func)(double, double))
{
    for (size_t i = 0; i < tam; i++) arr[i] = func(arr[i], 2);
}

void my_function_print (long arr[], size_t tam, int (*func)(const char*, long))
{
    for (size_t i = 0; i < tam; i++) func("%d - ", arr[i]);
}

int main ()
{
    long arreglo[] = {1, 2, 4, 6, 10, 16, 26, 42};
    int (*p_print)(const char* restrict, long) = printf; 
    double (*p_pow)(double, double) = pow;

    puts("Base:");
    my_function_print(arreglo, sizeof(arreglo)/sizeof(long), p_print);

    my_function_pow(arreglo, sizeof(arreglo)/sizeof(long), p_pow);
    
    puts("\nAl cuadrado:");
    my_function_print(arreglo, sizeof(arreglo)/sizeof(long), p_print);
    putchar('\n');
    return 0;
}