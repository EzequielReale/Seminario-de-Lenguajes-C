#include <stdio.h>

void funcion()
{
    static int x = 0; // Se va incrementando
    int y = 0; // Solo llega hasta 1 y se pierde
    x++; y++;
    printf("x = %d, y = %d\n", x, y) ;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        funcion();
    }
    return 0;
}