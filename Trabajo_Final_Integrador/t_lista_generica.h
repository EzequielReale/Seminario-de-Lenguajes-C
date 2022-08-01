#ifndef LISTA_H 
#define LISTA_H 1

    typedef struct nodo_generico
    {
        void *dato;
        struct nodo_generico *siguiente;
    } t_nodo_generico;

    typedef t_nodo_generico *t_lista_generica;

    typedef short (*t_comparador)(void*, void*);

    typedef char bool;

    // inicializa el puntero en NULL
    void lista_generica_inicializar(t_lista_generica *lista);

    // libera la memoria ocupada por la lista y asigna NULL al puntero
    void lista_generica_destruir(t_lista_generica *lista);

    // devuelve 1 si la lista está vacía y 0 si tiene elementos
    bool lista_generica_esta_vacia(t_lista_generica lista);

    // retorna verdadero 1 si existe el elemento, o 0 en caso contrario. Cuenta con comparador generico
    bool lista_generica_existe_elemento(t_lista_generica lista, void *dato, t_comparador cmp);

    // aloca memoria para un nuevo nodo, y agrega el puntero al elemento. Devuelve 1 si se aloco correctamente o 0 si no habia espacio
    bool lista_generica_agregar_adelante(t_lista_generica *lista, void *dato);

    // aloca memoria para un nuevo nodo, y agrega el puntero al elemento atras. Devuelve 1 si se aloco correctamente o 0 si no habia espacio
    bool lista_generica_agregar_atras(t_lista_generica *lista, void *dato);

    // agrega atras una cantidad variable de elementos. Devuelve 1 si se aloco correctamente o 0 si no habia espacio
    bool lista_generica_agregar_en_cantidad(t_lista_generica *lista, int cant, ...);

    // ordena los elementos de la lista con un Bubble Sort adaptado mediante un comparador generico 
    void lista_generica_ordenar(t_lista_generica *lista, t_comparador cmp);

    // busca *dato en la lista, lo elimina y realoca memoria para la lista. Devuelve el dato, o null si no existe. Cuenta con comparador generico
    void *lista_generica_eliminar_elemento(t_lista_generica *lista, void *dato, t_comparador cmp);

    // busca hasta la posición marcada en la lista, elimina el elemento y realoca memoria para la lista. Devuelve el dato, o null si no existe. Tener en cuenta que la lista empieza en 0
    void *lista_generica_eliminar_en(t_lista_generica *lista, int pos);

#endif