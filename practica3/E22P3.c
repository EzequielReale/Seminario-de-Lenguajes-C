#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //tr reemplaza cada letra de set1 por la de la misma posicion de set2
    if (argc == 3)
    {
        char cadena[255], set1[255], set2[255];
        strcpy(set1, argv[1]);
        strcpy(set2, argv[2]);

        int tam;
        if ((strlen(set1) < strlen(set2))) tam = strlen(set1);
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
    else
    {
        fputs("Cantidad erronea de argumentos",stderr);
        return 1;
    }
    return 0;
}