#include <stdio.h>

void suma_de_elementos(int arr1[], int arr2[], int arr_suma[],int tam)
{
    for(int i = 0; i < tam; i++) 
    {
        arr_suma[i] = arr1[i] + arr2[i];
    }
}

int main()
{
    int arr1[] = {1,2,3,4,5}, arr2[] = {2,3,4,5,6,7}, tam;
    
    if (sizeof(arr1) > sizeof(arr2)) 
    {
        tam = sizeof(arr2) / sizeof(int);
    }
    else 
    {
        tam = sizeof(arr1) / sizeof(int);
    }
    int arr_suma[tam];

    suma_de_elementos(arr1,arr2,arr_suma,tam);
    for (int i = 0; i < tam; i++){
        printf("Pos: %d   elemento: %d\n",i,arr_suma[i]);
    }
    return 0;
}