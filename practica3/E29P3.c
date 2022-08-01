#include <stdio.h>
#include "pila.h"

int main()
{
    int tamanio;
    char *p = crear_pila(&tamanio);
    
    puts("Ingrese un texto: ");
    char aux;
    while((aux = getchar()) != EOF){
        p = apilar(p, &tamanio, aux);
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