#include <stdio.h>

void ordenar (int vector[], int tamanio)
{
    int j, actual;

    for (int i = 2; i < tamanio; i++)
    {
        actual = vector[i];
        j = i-1;
        while ((j > 0) && (vector[j] > actual))
        {
            vector[j+1] = vector[j];
            j--; 
        }
        vector[j+1] = actual;
    }  
}

int main ()
{
    int vector[] = {1,4,8,2,7,5,6,3,9};
    int tamanio = sizeof(vector) / sizeof(int);
    
    printf("Desordenado:\n");
    for (int i = 0; i < tamanio; i++)
    {
        printf("Elemento %d: %d\n",i+1,vector[i]);
    }
    
    ordenar(vector, tamanio);

    printf("\nOrdenado:\n");
    for (int i = 0; i < tamanio; i++)
    {
        printf("Elemento %d: %d\n",i+1,vector[i]);
    }

    return 0;
}