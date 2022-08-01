#include "programs.h"

int right_lines(FILE *fp, int lines)
{
    char *act_line = NULL;
    int i = 0;
    for (; (i < lines) && (dynamic_fgets(&act_line, fp)); i++) 
    {
        fputs(act_line, stdout);
        free(act_line);
        act_line = NULL;
    }
    return i;
}

int right_bytes(FILE *fp, int bytes)
{
    int c, i = 0;
    for (; (i < bytes) && ((c = fgetc(fp)) != EOF); i++) fputc(c, stdout);
    fflush(stdout);
    return i;
}

void reverse_lines(FILE *fp, int lines)
{
    char *ptr = NULL;
    if ((lines > 0) && (dynamic_fgets(&ptr, fp)))
    {
        reverse_lines(fp, lines-1);
        fputs(ptr, stdout);
        free(ptr);
    }
}

void tail_stdin(FILE *fp, int lines, bool mode)
{
    lines += 1; //Incrementa lineas porque si no se pierde el 1er string
    char *strings[lines], *to_print[lines];
    int i;

    for (i = 0; i < lines; i++) //Inicializo los punteros
    {
        strings[i] = NULL;
        to_print[i] = NULL;
    }

    t_lista_generica list;
    lista_generica_inicializar(&list);
    i = 0;
    bool cycle = 0; //Booleano que sirve para saber si di la vuelta completa y tengo que empezar a inicializar en null de nuevo
    while (dynamic_fgets(&strings[i], fp))
    {
        if (!lista_generica_agregar_adelante(&list, strings[i++]))
        {
            error_to_output(E_ALLOC);
            exit(E_ALLOC);
        }
        if (i >= lines)
        {
            i = 0;
            cycle = 1;
        }
        if (cycle)
        {
            //lista_generica_eliminar_en(&list, sizeof(list)/sizeof(t_lista_generica));
            free(strings[i]);
            strings[i] = NULL;
        }
    }

    t_nodo_generico *aux = list;
    for (i = lines - 1; ((i > 0) && (aux)); i--) //Pasa el contenido de la lista a un arreglo para poder imprimir
    {
        if (!mode)
        {
            if (!(to_print[i] = malloc(strlen(aux->dato))))
            {
                error_to_output(E_ALLOC);
                exit(E_ALLOC);
            }
            strcpy(to_print[i], ((char *)aux->dato));
        }
        else fputs((char *)aux->dato, stdout); //Si hay que imprimir en reversa lo hace acá

        aux = aux->siguiente;
    }

    for (int i = 0; i < lines; i++) if(strings[i]) free(strings[i]); //En esta sección hace free's de las estructuras que ya no se usan  
    lista_generica_destruir(&list);

    if (!mode)
    {
        for (i = 0; i < lines; i++) //Hace el free de to_print e imprime (si no está en reversa)
        {
            if (to_print[i] != NULL)
            {
                fputs(to_print[i], stdout);
                free(to_print[i]);
            }         
        }
    }
}