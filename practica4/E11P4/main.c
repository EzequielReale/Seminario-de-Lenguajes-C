#include <stdio.h>
#include "t_lista_generica.h"

void mal_uso(t_lista_generica *lista){ // No libera memoria, por eso la libero en la sentencia de abajo
    int i, arr_int[10] = {10, 21, 31, 42, 52, 62, 10, 2, 5, 6};
    lista_generica_inicializar(lista);
    for (i=0; i<10; i++){
        lista_generica_agregar_adelante(lista, &arr_int[i]);
    }
    t_nodo_generico *aux = *lista;
    while (aux) 
    {
        printf("Elemento -> %d\n", *(int *)aux->dato);
        aux = aux->siguiente;
    }
}

int main ()
{
    t_lista_generica lista;
    int x = 5;
    lista_generica_inicializar(&lista);

    puts("Antes de agregar el 5:");
    printf("\tEsta vacia? %d\n", lista_generica_esta_vacia(lista));
    printf("\tExiste 5? %d\n", lista_generica_existe_elemento(lista, &x));

    lista_generica_agregar_adelante(&lista, &x);
    //lista_generica_agregar_atras(&lista, &x);

    puts("\nDespues de agregar el 5:");
    printf("\tEsta vacia? %d\n", lista_generica_esta_vacia(lista));
    printf("\tExiste 5? %d\n", lista_generica_existe_elemento(lista, &x));

    puts("\nDespues de eliminar el 5:");
    printf("\tRetorno de eliminar el 5: %p\n", lista_generica_eliminar_elemento(&lista, &x));
    printf("\tEsta vacia? %d\n", lista_generica_esta_vacia(lista));
    printf("\tExiste 5? %d\n", lista_generica_existe_elemento(lista, &x));
    
    //mal_uso(&lista);
    lista_generica_destruir(&lista);
    return 0;
}