#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "t_lista_generica.h"

void lista_generica_inicializar(t_lista_generica *lista)
{
    *lista = NULL;
}

void lista_generica_destruir(t_lista_generica *lista)
{
    t_nodo_generico *nodo_act = *lista, *aux;
    while (nodo_act != NULL)
    {
        aux = nodo_act;
        nodo_act = nodo_act->siguiente;
        free(aux);
    }
    *lista = NULL;
}

bool lista_generica_esta_vacia(t_lista_generica lista)
{
    return (lista == NULL);
}

bool lista_generica_existe_elemento(t_lista_generica lista, void *dato, t_comparador cmp)
{
    while ((lista != NULL ) && (cmp(lista->dato, dato) != 0))
    {
       lista = lista->siguiente; 
    }
    if (lista != NULL) return 1;
    else return 0;
}

bool lista_generica_agregar_adelante(t_lista_generica *lista, void *dato)
{
    t_nodo_generico *aux;
    aux = malloc(sizeof(t_nodo_generico));
    if (!aux) return 0;
    aux->dato = dato;
    aux -> siguiente = *lista;
    *lista = aux;

    return 1;
} 

bool lista_generica_agregar_atras(t_lista_generica *lista, void *dato)
{
    t_nodo_generico *nodo = malloc(sizeof(t_nodo_generico));
    if (!nodo) return 0;

    nodo->siguiente = NULL;
    nodo->dato = dato;

    if (*lista == NULL) *lista = nodo;
    else
    {
        t_nodo_generico *ult = *lista;
        while (ult->siguiente != NULL) ult = ult->siguiente;
        ult->siguiente = nodo;   
    }
    return 1;
}

bool lista_generica_agregar_en_cantidad(t_lista_generica *lista, int cant, ...)
{
    char ok;
    va_list args;
    va_start(args, cant);
    for (int i = 0; i < cant; i++) ok = lista_generica_agregar_atras(lista, va_arg(args, void*));
    va_end(args);
    return ok;
}

void lista_generica_ordenar(t_lista_generica *lista, t_comparador cmp)
{
    t_nodo_generico *nodo_act, *nodo_sig;
    void *temp; //variable temporal para intercambiar los datos
    nodo_act = *lista;
    
    while(nodo_act)
    {
        nodo_sig = nodo_act->siguiente;
        while(nodo_sig)
        {
            if(cmp(nodo_act->dato, nodo_sig->dato) == 1) //intercambio: es igual a (nodo_act->dato > nodo_sig->dato)
            {
                temp = nodo_act->dato;
                nodo_act->dato = nodo_sig->dato;
                nodo_sig->dato = temp;
            }
            nodo_sig = nodo_sig->siguiente;
        }
        nodo_act = nodo_act->siguiente;
    }
}


void *lista_generica_eliminar_elemento(t_lista_generica *lista, void *dato, t_comparador cmp)
{
    void *retorno = NULL;
    t_nodo_generico *nodo_act = *lista, *nodo_ant = NULL;

    while ((nodo_act) && (cmp(nodo_act->dato, dato) != 0))
    {
        nodo_ant = nodo_act;
        nodo_act = nodo_act->siguiente;
    }
    if (nodo_act)
    {
        retorno = nodo_act->dato;
        if (!nodo_ant) *lista = nodo_act->siguiente;
        else nodo_ant->siguiente = nodo_act->siguiente;
        free(nodo_act);
    }
    
    return retorno;
}

void *lista_generica_eliminar_en(t_lista_generica *lista, int pos)
{
    int pos_act = 0;
    void *retorno = NULL;
    t_nodo_generico *nodo_act = *lista, *nodo_ant = NULL;

    while ((nodo_act) && (pos_act++ < pos))
    {
        nodo_ant = nodo_act;
        nodo_act = nodo_act->siguiente;
    }
    if (nodo_act)
    {
        retorno = nodo_act->dato;
        if (!nodo_ant) *lista = nodo_act->siguiente;
        else nodo_ant->siguiente = nodo_act->siguiente;
        free(nodo_act);
    }
    
    return retorno;
}