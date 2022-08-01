#include <stdlib.h>
#include "t_lista_generica.h"

/* Los modulos comentados empleaban memcpy/memcmp. Aunque habia sido un error de comprension
   del enunciado, me parecia interesante dejarlos para que se viera otra manera de hacer la lista.
   Aunque esos modulos ahora mismo no funcionen porque requerian que cada nodo "conociera" el tamaño de su tipo para funcionar.*/

void lista_generica_inicializar(t_lista_generica *lista)
{
    *lista = NULL;
}

void lista_generica_destruir(t_lista_generica *lista)
{
    t_nodo_generico *nodo_act = *lista, *aux;
    while (nodo_act)
    {
        aux = nodo_act;
        nodo_act = nodo_act->siguiente;
        free(aux);
    }
    *lista = NULL;
}

char lista_generica_esta_vacia(t_lista_generica lista)
{
    return (lista == NULL);
}

/*char lista_generica_existe_elemento(t_lista_generica lista, void *dato)
{
    while ((lista) && (memcmp(lista->dato, dato, lista->tamanio)))
    {
       lista = lista->siguiente; 
    }
    if (lista) return 1;
    else return 0;
}*/

char lista_generica_existe_elemento(t_lista_generica lista, void *dato)
{
    while ((lista) && (lista->dato != dato))
    {
       lista = lista->siguiente; 
    }
    if (lista) return 1;
    else return 0;
}

/*char lista_generica_agregar_adelante(t_lista_generica *lista, void *dato, size_t tamanio)
{
    t_nodo_generico *aux;
    aux = malloc(sizeof(t_nodo_generico));
    if (!aux){
        return 0;
    }
    aux->dato = malloc(tamanio);
    if(!aux->dato) {
        free(aux);
        return 0;
    }  
    memcpy(aux->dato, dato, tamanio);
    aux->tamanio = tamanio;
    aux->siguiente = *lista;
    *lista = aux;

    return 1;
} */

char lista_generica_agregar_adelante(t_lista_generica *lista, void *dato)
{
    t_nodo_generico *aux;
    aux = malloc(sizeof(t_nodo_generico));
    if (!aux){
        return 0;
    }
    aux->dato = dato;
    aux -> siguiente = *lista;
    *lista = aux;

    return 1;
} 

/*char lista_generica_agregar_atras(t_lista_generica *lista, void *dato, size_t tamanio)
{
    t_nodo_generico *nodo = malloc(sizeof(t_nodo_generico));
    if (!nodo) return 0;

    nodo->tamanio = tamanio;
    nodo->siguiente = NULL;
    nodo->dato = malloc(tamanio);
    if (!nodo->dato) 
    {
        free(nodo);
        return 0;
    }
    memcpy(nodo->dato, dato, tamanio);

    if (!*lista) *lista = nodo;
    else
    {
        t_nodo_generico *ult = *lista;
        while (ult->siguiente) ult = ult->siguiente;
        ult->siguiente = nodo;   
    }
    return 1;
}*/

char lista_generica_agregar_atras(t_lista_generica *lista, void *dato)
{
    t_nodo_generico *nodo = malloc(sizeof(t_nodo_generico));
    if (!nodo) return 0;

    nodo->siguiente = NULL;
    nodo->dato = dato;

    if (!*lista) *lista = nodo;
    else
    {
        t_nodo_generico *ult = *lista;
        while (ult->siguiente) ult = ult->siguiente;
        ult->siguiente = nodo;   
    }
    return 1;
}

void *lista_generica_eliminar_elemento(t_lista_generica *lista, void *dato)
{
    void *retorno = NULL;
    if (lista_generica_existe_elemento(*lista, dato))
    {
        t_nodo_generico *nodo_act = *lista, *nodo_ant = NULL;
        while ((nodo_act) && (nodo_act->dato != dato))
        {
            nodo_ant = nodo_act;
            nodo_act = nodo_act->siguiente;
        }
        retorno = nodo_act->dato;
        if (!nodo_ant) *lista = nodo_act->siguiente;
        else nodo_ant->siguiente = nodo_act->siguiente;
        free(nodo_act);
    }
    return retorno;
}