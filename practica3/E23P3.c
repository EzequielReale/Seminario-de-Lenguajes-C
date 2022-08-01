#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tr(char const *argv[])
{
    char cadena[255], set1[255], set2[255];
    strcpy(set1, argv[1]);
    strcpy(set2, argv[2]);

    int tam;
    if ((strlen(set1) > strlen(set2))) tam = strlen(set1);
    else tam = strlen(set2);

    while (scanf("%s", cadena) != EOF)
    {
        for (int i = 0; cadena[i] != 0; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                if (cadena[i] == set1[j]) cadena[i] = set2[j];
            }
        }
        puts(cadena);
    }
}

void _d(char const *argv[])
{
    char cadena[255], set1[255];
    strcpy(set1, argv[2]);
    int tam = strlen(set1);

    while (scanf("%s", cadena) != EOF)
    {
        for (int i = 0; cadena[i] != 0; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                if (cadena[i] == set1[j])
                {
                    for (int k = i; cadena[k] != 0; k++) cadena[k] = cadena[k + 1];
                }
            }
        }
        puts(cadena);
    }
}

void help()
{
    puts("Uso: ./e23 [OPCIÓN]... SET1 [SET2]\n"
         "Traducir o eliminar caracteres de la entrada estandar, escribiendo en la salida estandar.\n\n"
         "\tSin parametro, usa el complemento de SET2 en SET1\n"
         "\t-d, eliminar caracteres en SET1, sin traducir\n"
         "\t-h muestra esta ayuda y sale\n\n"
         "Los SET se especifican como cadenas de caracteres.\n");
}

int main(int argc, char const *argv[])
{
    // tr reemplaza cada letra de set1 por la de la misma posicion de set2
    // tr -d elimina cada letra de set1
    if (argc == 3)
    {
        if (!strcmp(argv[1], "-d")) _d(argv);
        else if (!strcmp(argv[1], "-h")) help();
        else tr(argv);
    }
    else
    {
        fputs("Cantidad erronea de argumentos", stderr);
        return 1;
    }
    return 0;
}