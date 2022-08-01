#ifndef LISTA_H
#define LISTA_H

    typedef struct nodo_generico
    {
        void *dato;
        struct nodo_generico *siguiente;
    } t_nodo_generico;

    typedef t_nodo_generico *t_lista_generica;

    // Inicializa el puntero en NULL
    void lista_generica_inicializar(t_lista_generica*);

    // Libera la memoria ocupada por la lista y asigna NULL al puntero
    void lista_generica_destruir(t_lista_generica*);

    // Devuelve 1 si la lista está vacía y 0 si tiene elementos
    char lista_generica_esta_vacia(t_lista_generica);

    // Retorna verdadero 1 si existe el elemento, o 0 en caso contrario
    char lista_generica_existe_elemento(t_lista_generica, void*);

    // Aloca memoria para un nuevo nodo, y agrega el puntero al elemento.
    // Devuelve 1 si se aloco correctamente o 0 si no habia espacio en la memoria heap
    char lista_generica_agregar_adelante(t_lista_generica*, void*);

    // Aloca memoria para un nuevo nodo, y agrega el puntero al elemento atras.
    // Devuelve 1 si se aloco correctamente o 0 si no habia espacio en la memoria heap
    char lista_generica_agregar_atras(t_lista_generica*, void*);

    // Busca *dato en la lista. Si existe, libera el nodo que lo contiene y devuelve su contenido.
    void *lista_generica_eliminar_elemento(t_lista_generica*, void*);

#endif