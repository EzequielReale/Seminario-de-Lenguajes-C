#include <stdio.h>

int esMayOMin(char x)
{
    if ((x >= 'A') & (x <= 'Z'))
    {
        return 1;
    }
    else if ((x >= 'a') & (x <= 'z'))
    {
        return 2;
    }
}

int main()
{
    int valor = esMayOMin('0');

    if (valor == 1)
    {
        printf("Mayuscula");
    }
    else if (valor == 2)
    {
        printf("Minuscula");
    }
    else
    {
        printf("Otro caracter");
    }
     
    return 0;
}