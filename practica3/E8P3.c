#include <stdio.h>

void string_inverso_iterativo(char *cadena, int tam)
{
    for (int i = tam-1; i >= 0; i--)
    {
        printf("%c",cadena[i]);
    }
}

void string_inverso_recursivo(char *cadena, int act)
{
    if(cadena[act] != '\0')
    {   
        act++;   
        string_inverso_recursivo(cadena, act);
        printf("%c", cadena[--act]);
    }
}

void string_inverso_recursivo2(char *cadena, int tam)
{
    if (tam > 0)
    {
        printf("%c", cadena[--tam]);
        string_inverso_recursivo2(cadena, tam);
    }
}
int main()
{
    char cadena[] = "A la grande le puse Cuca\n";
    string_inverso_iterativo(cadena, sizeof(cadena));
    string_inverso_recursivo(cadena, 0);
    string_inverso_recursivo2(cadena, sizeof(cadena));
    return 0;
}