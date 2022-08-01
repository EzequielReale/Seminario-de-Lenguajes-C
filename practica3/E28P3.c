#include <stdlib.h>
#include <stdio.h>

char *crear_pila(int *tamanio)
{
    *tamanio = 0;
    return NULL;
}

void destruir_pila(char *pila)
{
    free(pila);
}

char *apilar(char *pila, int *tamanio, char elem)
{
    if (*tamanio == 0)
    {
        pila = malloc(sizeof(char) * ++(*tamanio));
        pila[(*tamanio)] = elem;
    }
    else
    {
        pila = realloc(pila, sizeof(char) * ((*tamanio)++));
        pila[*tamanio] = elem;
    }

    return pila;
}

char *desapilar(char *pila, int *tamanio, char *elem)
{
    *elem = pila[*tamanio];
    pila = realloc(pila, sizeof(char) * (--(*tamanio)));

    if (*tamanio == 0) pila = NULL;

    return pila;
}

int main()
{
    int tamanio;
    char *p = crear_pila(&tamanio);
    
    puts("Ingrese un texto: ");
    char aux;
    while((aux = getchar()) != EOF){
        p = apilar(p, &tamanio, aux);
        putchar(aux);
    }

    puts("");
    
    while(p != NULL){
        p = desapilar(p, &tamanio, &aux);
        printf("%c", aux);
    }

    puts("");
    
    destruir_pila(p);
    
    return 0;
}