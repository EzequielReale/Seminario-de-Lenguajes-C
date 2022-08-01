#include <stdio.h>

int main()
{
    int c, cant_letras = 0, cant_lineas = 0;
    
    while ((c= getchar()) != EOF)
    {
        if (c != '\n')
        {
            cant_letras++;
        }
        else
        {
            cant_lineas++;
        }
        c ;
    }
    printf("%d caracteres y %d lineas.\n",cant_letras,cant_lineas);
    return 0;
}