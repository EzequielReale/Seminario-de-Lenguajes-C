#include <stdio.h>
#include <stdlib.h>
#include "t_alumno.h"

int main()
{
    t_alumno alumno1;
    inicializar_alumno(&alumno1, "Juan", "Perez", 15, 02, 2003, 192436);
    
    char *str = malloc(sizeof(char) * 2048);
    str = to_string(str, alumno1);
    puts(to_string(str, alumno1));
    free(str);
    
    t_alumno alumno2;
    inicializar_alumno(&alumno2, "Juan", "Perez", 16, 03, 2004, 203547);
    
    char aux;
    if ((aux = alumnocmp(alumno1, alumno2)))
    {
        if (aux == 1)
        {
            puts("Son iguales.");
        }
        else
        {
            puts("Los nombres coinciden, la fecha de nacimiento y el legajo no.");
        }
    }
    else
    {
        puts("No coinciden.");
    }

    destruir_alumno(&alumno1);
    destruir_alumno(&alumno2);
    return 0;
}