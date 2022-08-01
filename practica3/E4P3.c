#include <stdio.h>

int main()
{
    char *arr1 = "Hola mundo";
    char arr2[20];
    printf(" %d ", sizeof(arr1)); //tamaño de un puntero
    printf(" %d ", sizeof(arr2)); //tamaño del string
    return 0;
}