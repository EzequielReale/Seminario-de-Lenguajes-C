#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace(const char *l, const char *e1, const char *e2, char *r)
{
    int tam;
    if ((strcmp(e1, e2) != 1)) tam = strlen(e1);
    else tam = strlen(e2);

    for (int i = 0; l[i] != 0; i++)
    {
        *r = l[i];
        for (int j = 0; j < tam; j++)
        {
            if (l[i] == e1[j]) *r = e2[j];
        }
        r++;
    }
    *r = '\0';
}

int main(int argc, char const **argv)
{
    char r[255];
    if (argc >= 4)
    {
       replace(argv[1], argv[2], argv[3], r);
       puts(r);
    } 
    else fputs("Cantidad érronea de parámetros", stderr);

    return 0;
}