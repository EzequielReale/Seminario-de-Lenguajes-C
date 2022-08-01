#include <stdio.h>
#include <string.h>

int devolver_cant_palabras (const char cadena[])
{
    int i = strlen(cadena);
    if (i > 0)
    {
        int cant = 1;
        for (; i >= 0; i--)
        {
            if (cadena[i] == ' ') cant++;
        }
        return cant;
    }
    return 0;
}

int main ()
{
    char cadena[] = "Hola hola hola";
    printf("Cantidad de palabras en <<%s>>: %d\n",cadena,devolver_cant_palabras(cadena));
    return 0;
}