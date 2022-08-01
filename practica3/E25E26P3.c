#include <stdlib.h>
#include <stdio.h>
#define N 10
#define K 15

//e25
int *crear_vector_int(int n)
{
    return malloc(sizeof(int) * n);
}

void destruir_vector_int(int *vector)
{
    free(vector);
}

//e26
int *cambiar_tamanio_vector_int(int *vector, int nuevo_tam)
{
    return realloc(vector, sizeof(int) * nuevo_tam);
}

int main()
{
    int *vector = crear_vector_int(N);
    for (int i = 0; i < N; i++) vector[i] = i;
    for (int i = 0; i < N; i++) printf("Posición %d --> Valor %d\n", i, vector[i]);
    puts("\n");

    vector = cambiar_tamanio_vector_int(vector, K);
    for (int i = 0; i < K; i++) vector[i] = i;
    for (int i = 0; i < K; i++) printf("Posición %d --> Valor %d\n", i, vector[i]);
    puts("\n");

    destruir_vector_int(vector);
    for (int i = 0; i < K; i++) printf("Posición %d --> Valor %d\n", i, vector[i]); //imprime basura

    return 0;
}