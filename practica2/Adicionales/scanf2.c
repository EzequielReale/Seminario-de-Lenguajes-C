#include <stdio.h>

/****************** Casos de prueba:
Ingrese al menos el siguiente conjunto de datos para probar el programa.
-> Caso 1:
marcos 54
francisco 23
analia 21
mariana 10
federico 20
-> Caso 2:
marcos pardo 24
francisco 10
analia 21.2
mariana 23
federico 20
Lea: http://c-faq.com/stdio/scanfprobs.html y las 3 preguntas relacionadas
enlazadas al principio del documento.
************************************/

int main(int argc, char **argv)
{
    char nombre[20];
    int edad;
    int error;
    // Lee e imprime 5 nombres seguidos de su edad
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre y la edad: ");
        if ((error = fscanf(" %s %d", nombre, &edad)) != 2)
        {
            printf("------> Ocurrio un error, scanf retorno: %d\n", error);
            // Si falla descartamos el intento
            i--;
        }
        else
        {
            printf("Ingreso el nombre: %s con edad: %d\n", nombre, edad);
        }
    }
}