#include "t_lista_generica.h"
#include <stdio.h>
#include <stdlib.h>
#define POS 4

short cmp(void *a, void *b)
{
    int a_val = *((int *) a), b_val = *((int *) b);
    return a_val > b_val ? 1 : (a_val == b_val ? 0: -1);
}

void test(t_lista_generica *lista){
    int arr_int[10] = {10, 21, 31, 42, 52, 62, 10, 2, 5, 6};
    for (int i = 0; i < 10; i++) if(!lista_generica_agregar_atras(lista, &arr_int[i])) exit(1);
    
    //lista_generica_agregar_en_cantidad(lista, 10, 10, 21, 31, 42, 52, 62, 10, 2, 5, 6);
    
    puts("Desordenado:");
    t_nodo_generico *aux = *lista;
    while (aux) 
    {
        printf("Elemento -> %d\n", *(int *)aux->dato);
        aux = aux->siguiente;
    }

    lista_generica_ordenar(lista, cmp);
    puts("\nOrdenado:");
    aux = *lista;
    while (aux) 
    {
        printf("Elemento -> %d\n", *(int *)aux->dato);
        aux = aux->siguiente;
    }

    printf("\nEstá vacia la lista? -> %d\n", lista_generica_esta_vacia(*lista));
    printf("\nExiste el %d? -> %d\n", arr_int[POS], lista_generica_existe_elemento(*lista, &arr_int[POS], cmp));

    printf("Despues de eliminar el %d -> ", arr_int[POS]);
    int *ret;
    ret = lista_generica_eliminar_elemento(lista, &arr_int[POS], cmp);
    printf("Su valor de retorno fue: %p\n\n", ret);
    
    aux = *lista;
    while (aux) 
    {
        printf("Elemento -> %d\n", *(int *)aux->dato);
        aux = aux->siguiente;
    }
    
    printf("\nExiste el %d? -> %d\n", arr_int[POS], lista_generica_existe_elemento(*lista, &arr_int[POS], cmp));
}

int main ()
{
    t_lista_generica lista;
    lista_generica_inicializar(&lista);
    printf("Está vacia la lista? -> %d\n", lista_generica_esta_vacia(lista));
    puts("Le agrego elementos\n");
    test(&lista);
    puts("\nDestruyo la lista");
    lista_generica_destruir(&lista);
    printf("Está vacia la lista? -> %d\n", lista_generica_esta_vacia(lista));
    return 0;
}