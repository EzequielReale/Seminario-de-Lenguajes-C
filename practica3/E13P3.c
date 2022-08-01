#include "E12P3.c"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int palabras_capicua(const char *str)
{
    int cont = 0;

    char aux[255];

    char *p_aux = aux;
    for (; *str != 0; str++)
    {
        if (!isblank(*str))
        {
            *p_aux = *str;
            p_aux++;
            *p_aux = '\0';
        }
        else
        {
            p_aux = aux;
            if (es_palindromo(p_aux)) cont++;
            aux[0] = '\0';
        }
    }

    return cont;
}

int main()
{
    char str[] = "neuquen es capicua OMG! neuquen neuquen neuquen !!!!";
    printf("Cantidad de palabras capicuas en \"%s\" -> %d\n", str, palabras_capicua(str));
    return 0;
}