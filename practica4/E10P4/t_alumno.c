#include "t_alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char inicializar_alumno(t_alumno *alumno, char nombre[], char apellido[], unsigned short d, 
                        unsigned short m, unsigned short a, unsigned int legajo)
{
    *alumno = malloc(sizeof(struct s_alumno));
    if (!*alumno) return 0;

    strcpy((*alumno)->nombre, nombre);
    strcpy((*alumno)->apellido, apellido);
    (*alumno)->legajo = legajo;
    (*alumno)->f_nacimiento.dia = d;
    (*alumno)->f_nacimiento.mes = m;
    (*alumno)->f_nacimiento.anio = a;

    return 1;
}
                       
char *to_string(char *str, t_alumno alumno)
{
    strcpy(str, "Alumno ");
    strcat(str, alumno->nombre);
    strcat(str, " ");
    strcat(str, alumno->apellido);
    strcat(str, ":\n\tFecha de nacimiento: ");
    char aux[20];
    sprintf(aux, "%d / %d / %d", (alumno->f_nacimiento).dia, (alumno->f_nacimiento).mes, (alumno->f_nacimiento).anio);
    strcat(str, aux);
    strcat(str, "\n\tNumero de legajo: ");
    sprintf(aux, "%d", alumno->legajo);
    strcat(str, aux); 
    return str;
}

char alumnocmp(t_alumno a1, t_alumno a2)
{
    char iguales = 0;
    if (!strcmp(a1->nombre, a2->nombre) && !strcmp(a1->apellido, a2->apellido))
    {
        iguales = -1;
        if ((a1->f_nacimiento.dia == a2->f_nacimiento.dia) && (a1->f_nacimiento.mes == a2->f_nacimiento.mes) && (a1->f_nacimiento.anio == a2->f_nacimiento.anio) && (a1->legajo == a2->legajo))
        {
            iguales = 1;
        }       
    }
    return iguales;
}

void destruir_alumno(t_alumno *alumno)
{
    free(*alumno);
}

