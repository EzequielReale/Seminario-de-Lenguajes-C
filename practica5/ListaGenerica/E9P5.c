#include <stdio.h>
#include <string.h>
#include "t_lista_generica.h"
#define LINEAS_DEFAULT 11

int main(int argc, const char *argv[])
{
    if (argc >= 2)
    {
        FILE *archivo;      
        if ((archivo = fopen(argv[1], "r")))
        {
            char cadenas[LINEAS_DEFAULT][1024], imprimir[LINEAS_DEFAULT][1024];
            unsigned short i;
            
            for (i = 0; i < LINEAS_DEFAULT; i++) 
            {
                cadenas[i][0] = '\0';
                imprimir[i][0] = '\0';
            }

            t_lista_generica lista;
            lista_generica_inicializar(&lista);
            i = 0;
            while (fgets(cadenas[i], sizeof(cadenas[i]), archivo))
            {
                lista_generica_agregar_adelante(&lista, &cadenas[i]);
                i++;
                if (i >= LINEAS_DEFAULT) i = 0;
            }
 
            t_nodo_generico *aux = lista;
            for (i = LINEAS_DEFAULT-1; ((i > 0) && (aux)); i--)
            {
                strcpy(imprimir[i], ((char *)aux->dato));
                aux = aux->siguiente;
            }

            lista_generica_destruir(&lista);

            for (i = 0; i < LINEAS_DEFAULT; i++)
            {
                if (imprimir[i][0] != '\0') puts(imprimir[i]);
            }
            
            fclose(archivo);  
        }
        else fputs("No pudo abrirse el archivo", stderr);
    }
    else
    {
        fputs("No ingreso ningun archivo", stderr);
        return 1;
    }
    return 0;
}